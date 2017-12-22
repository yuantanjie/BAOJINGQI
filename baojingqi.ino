#include <Microduino_ColorLED.h> //引用彩灯库

#define lightSensorPin  A0
#define ColorLEDPin    8      //彩灯引脚
#define NUMPIXELS      1      //级联彩灯数量
#define val_max 255
#define val_min 0
ColorLED strip = ColorLED(NUMPIXELS, ColorLEDPin); //将ColorLED类命名为strip，并定义彩灯数量和彩灯引脚号
#define light_cm 300
#define humanHotSensor 6//人体传感器
bool humanHotState = false;
 #define voice 100
    
#define mic_pin A2

#define buzzer_pin 2//定义蜂鸣器驱动引脚
#define buzzer_fre 2000//定义蜂鸣器输出频率
int light_val;
int micState;





void setup() {
  pinMode(mic_pin, INPUT);
  
  Serial.begin(9600);

  pinMode(lightSensorPin, INPUT);
  pinMode(humanHotSensor, INPUT);
  
  Serial.begin(112000);
pinMode(buzzer_pin, OUTPUT);

strip.begin();

  
}

void loop() {
   light_val = analogRead( lightSensorPin);
   humanHotState = digitalRead(humanHotSensor);
   micState=analogRead(mic_pin);
  if ( light_val < light_cm )
  {
if (humanHotState||micState>voice ) {
  strip.setPixelColor(0, strip.Color(255, 215, 234));//浅血牙光
  strip.show();   //LED显示
  delay(500);  //延迟0.5秒输出
  strip.setPixelColor(0, strip.Color(3, 179, 64));//巴黎绿光
  strip.show();  //LED显示
  delay(500);  //延迟0.5秒输出
  strip.setPixelColor(0, strip.Color(17, 31, 106));//藏蓝光
  strip.show();  //LED显示
  delay(500);  //延迟0.5秒输出
  strip.setPixelColor(0, strip.Color(0, 0, 0));//灭
  strip.show();  //LED显示

tone(buzzer_pin, buzzer_fre);   //驱动蜂鸣器
    delay(1000);
    noTone(buzzer_pin);//蜂鸣器不响

  }

}
}
