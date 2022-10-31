//Tom Williams Tech 2022
//Made for OCR GCSE Spec ( 97/100 )


//counters and buttons 

int correct = 0;

int counter2 = 0;

int reset = 12;

int score = 0;

//lcd stuffs
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7,8 , 9);

//variables for the backend

char *actors[]={"castle", "forest", "golden", "knight", "damage","police","abroad", "accept", "access", "across", "acting", "income", "indeed", "injury", "inside"};

char *anagrams[]={"sacelt","rstefo","godnle","nkihgt","amgead","ecilop","braado", "ctcape", "csasce", "oarssc", "agctin","ecinmo", "ndeide", "juyrni", "ndisei"};

long actor1;

bool incorrect = true;

String answer={};
String UI={};

 // variable for reading the potentiometer status

int sensorValue = 0;
const int enter = 13;
int enterValue = 0;
int outputValue = 0;
//runs once

void setup() {

  lcd.begin(16,2);
  Serial.begin(9600); //start serial monitor

  randomSeed(analogRead(A1)); //for true random

  // initialize the potentiometer pin as an input:
  pinMode(A0, INPUT);
  pinMode(enter, INPUT_PULLUP);
  pinMode(reset, INPUT_PULLUP);

}

 

//runs repeatedly

void loop() {

 

//display anagram on lcd:
//sizeof(actors)/sizeof(char*)
actor1 = random(0,14);
  lcd.setCursor(0,0);
  
 for (int counter = 0; counter <=5; counter++){
  lcd.setCursor(counter, 0);
  lcd.print(anagrams[actor1][counter]);
  
   
 }


//main while loop
correct = 0;
while (correct == 0){


  // read the state of the potentiometer value:
sensorValue = analogRead(A0);
outputValue = map(sensorValue, 0, 1023, 0, 60);
Serial.println(outputValue);
  
//checks if user is wrong
  if (answer.length()> 6){
    counter2 = 0;
    answer = {""};

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wrong!");
    lcd.setCursor(0,1);
    lcd.print("Retry...");
    delay(1000);                                                                                                                                                                                                                                                         
    lcd.clear();
  for (int counter = 0; counter <=5; counter++){
  lcd.setCursor(counter, 0);
  lcd.print(anagrams[actor1][counter]);
  
 }


}

//checks if the user is correct.
  if (answer == actors[actor1]){
   
    correct = 1;
    score = score +1;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Well Done");
    lcd.setCursor(0,1);
    lcd.print("Score = ");
    lcd.setCursor(8,1);
    lcd.print(score);

    delay(1000);
    lcd.clear();                                                                               
    counter2 = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    answer = "";

    }


  if (digitalRead(reset) == HIGH){
     counter2 = 0;
    answer = {""};
     lcd.clear();
  for (int counter = 0; counter <=5; counter++){
  lcd.setCursor(counter, 0);
  lcd.print(anagrams[actor1][counter]);

  }
    
    }
  
  
    //while loops for flashing  INDEX 1
  if(outputValue > 0 && outputValue < 10 && (digitalRead(enter) == LOW)){    //if angle is letter -- no buttonpress

  Serial.println("Ind 1");
  lcd.setCursor(0,0);
  lcd.print(" ");                //flash off
     
  if (outputValue > 0 && (digitalRead(enter) == HIGH) && (outputValue < 10)) {          //checks for button press
     answer += anagrams[actor1][0];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][0]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
    
  else{     //no press...
  delay(20);
  lcd.setCursor(0,0);   // if no button press flash back on
  lcd.print(anagrams[actor1][0]);
      
  if (outputValue > 0 && (digitalRead(enter) == HIGH) && (outputValue < 10)) {   //another quick check for the button press
     answer += anagrams[actor1][0];
    
     lcd.setCursor(counter2,1);
     lcd.print(anagrams[actor1][0]);
     counter2 = counter2 + 1;
     delay(200);
  }
      else{  //if no press...
  delay(20);
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 60);
  Serial.println(outputValue);
      }}}
  
  
  
  
  
 
     //while loops for flashing  INDEX 2
  if(outputValue > 10 && outputValue < 20 && (digitalRead(enter) == LOW)){    //if angle is letter -- no buttonpress
  lcd.setCursor(1,0);
  lcd.print(" ");                //flash off
     
  if (outputValue > 10 && (digitalRead(enter) == HIGH) && (outputValue < 20)) {          //checks for button press
     answer += anagrams[actor1][1];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][1]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
    
  else{     //no press...
  delay(20);
  lcd.setCursor(1,0);   // if no button press flash back on
  lcd.print(anagrams[actor1][1]);
      
  if (outputValue > 10 && (digitalRead(enter) == HIGH) && (outputValue < 20)) {   //another quick check for the button press
     answer += anagrams[actor1][1];
    
     lcd.setCursor(counter2,1);
     lcd.print(anagrams[actor1][1]);
     counter2 = counter2 + 1;
     delay(200);
  }
      else{  //if no press...
  delay(20);
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 60);
  Serial.println(outputValue);
      }}}
  
  
  
  
  
  
       //while loops for flashing  INDEX 3
  if(outputValue > 20 && outputValue < 30 && (digitalRead(enter) == LOW)){    //if angle is letter -- no buttonpress
  lcd.setCursor(2,0);
  lcd.print(" ");                //flash off
     
  if (outputValue > 20 && (digitalRead(enter) == HIGH) && (outputValue < 30)) {          //checks for button press
     answer += anagrams[actor1][2];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][2]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
    
  else{     //no press...
  delay(20);
  lcd.setCursor(2,0);   // if no button press flash back on
  lcd.print(anagrams[actor1][2]);
      
  if (outputValue > 20 && (digitalRead(enter) == HIGH) && (outputValue < 30)) {   //another quick check for the button press
     answer += anagrams[actor1][2];
    
     lcd.setCursor(counter2,1);
     lcd.print(anagrams[actor1][2]);
     counter2 = counter2 + 1;
     delay(200);
  }
      else{  //if no press...
  delay(20);
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 60);
  Serial.println(outputValue);
  Serial.println(answer);
      }}}
  
  
  

  
       //while loops for flashing  INDEX 4
  if(outputValue > 30 && outputValue < 40 && (digitalRead(enter) == LOW)){    //if angle is letter -- no buttonpress
  lcd.setCursor(3,0);
  lcd.print(" ");                //flash off
     
  if (outputValue > 30 && (digitalRead(enter) == HIGH) && (outputValue < 40)) {          //checks for button press
     answer += anagrams[actor1][3];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][3]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
    
  else{     //no press...
  delay(20);
  lcd.setCursor(3,0);   // if no button press flash back on
  lcd.print(anagrams[actor1][3]);
      
  if (outputValue > 30 && (digitalRead(enter) == HIGH) && (outputValue < 40)) {   //another quick check for the button press
     answer += anagrams[actor1][3];
    
     lcd.setCursor(counter2,1);
     lcd.print(anagrams[actor1][3]);
     counter2 = counter2 + 1;
     delay(200);
  }
      else{  //if no press...
  delay(20);
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 60);
  Serial.println(outputValue);
      }}}
  
  
  
  
         //while loops for flashing  INDEX 5
  if(outputValue > 40 && outputValue < 50 && (digitalRead(enter) == LOW)){    //if angle is letter -- no buttonpress
  lcd.setCursor(4,0);
  lcd.print(" ");                //flash off
     
  if (outputValue > 40 && (digitalRead(enter) == HIGH) && (outputValue < 50)) {          //checks for button press
     answer += anagrams[actor1][4];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][4]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
    
  else{     //no press...
  delay(20);
  lcd.setCursor(4,0);   // if no button press flash back on
  lcd.print(anagrams[actor1][4]);
      
  if (outputValue > 40 && (digitalRead(enter) == HIGH) && (outputValue < 50)) {   //another quick check for the button press
     answer += anagrams[actor1][4];
    
     lcd.setCursor(counter2,1);
     lcd.print(anagrams[actor1][4]);
     counter2 = counter2 + 1;
     delay(200);
  }
      else{  //if no press...
  delay(20);
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 60);
  Serial.println(outputValue);
      }}}
  
  
  
  
  
  
  
           //while loops for flashing  INDEX 5
  if(outputValue > 50 && outputValue < 60 && (digitalRead(enter) == LOW)){    //if angle is letter -- no buttonpress
  lcd.setCursor(5,0);
  lcd.print(" ");                //flash off
     
  if (outputValue > 50 && (digitalRead(enter) == HIGH) && (outputValue < 60)) {          //checks for button press
     answer += anagrams[actor1][5];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][5]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
    
  else{     //no press...
  delay(20);
  lcd.setCursor(5,0);   // if no button press flash back on
  lcd.print(anagrams[actor1][5]);
      
  if (outputValue > 50 && (digitalRead(enter) == HIGH) && (outputValue < 60)) {   //another quick check for the button press
     answer += anagrams[actor1][5];
    
     lcd.setCursor(counter2,1);
     lcd.print(anagrams[actor1][5]);
     counter2 = counter2 + 1;
     delay(200);
  }
      else{  //if no press...
  delay(20);
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 60);
  Serial.println(outputValue);
      }}}
      
      
 if (outputValue > 0 && (digitalRead(enter) == HIGH) && (outputValue < 10)) {          //checks for button press
     answer += anagrams[actor1][0];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][0]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
         
 if (outputValue > 10 && (digitalRead(enter) == HIGH) && (outputValue < 20)) {          //checks for button press
     answer += anagrams[actor1][1];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][1]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }


  if (outputValue > 20 && (digitalRead(enter) == HIGH) && (outputValue < 30)) {          //checks for button press
     answer += anagrams[actor1][2];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][2]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }

 if (outputValue > 30 && (digitalRead(enter) == HIGH) && (outputValue < 40)) {          //checks for button press
     answer += anagrams[actor1][3];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][3]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }


  if (outputValue > 40 && (digitalRead(enter) == HIGH) && (outputValue < 50)) {          //checks for button press
     answer += anagrams[actor1][4];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][4]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }

  if (outputValue > 50 && (digitalRead(enter) == HIGH) && (outputValue < 60)) {          //checks for button press
     answer += anagrams[actor1][5];
    
    lcd.setCursor(counter2,1);
    lcd.print(anagrams[actor1][5]);          //prints to the second row
    counter2 = counter2 + 1;
      delay(200);
  }
 }}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
