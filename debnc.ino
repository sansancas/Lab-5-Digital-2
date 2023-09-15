const int buttonPin2 = PUSH2;     // the number of the pushbutton pin
const int buttonPin = PUSH1;  
const int ledPinG =  GREEN_LED;      // the number of the LED pin
const int ledPinR =  RED_LED;
const int ledPinB =  BLUE_LED;

const int led11 =  25;
const int led12 =  24;
const int led13 =  4;
const int led14 =  23;
const int led15 =  3;
const int led16 =  2;


const int led21 =  27;
const int led22 =  8;
const int led23 =  28;
const int led24 =  29;
const int led25 =  9;
const int led26 =  10;


// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState = HIGH;             // the current reading from the input pin
int buttonState2 = HIGH;
int lastButtonState = HIGH;   // the previous reading from the input pin
int lastButtonState2 = HIGH;
int inicio = 0;
int cont1 = 0;
int cont2 = 0;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long lastDebounceTime2 = 0;
long debounceDelay = 100;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led14, OUTPUT);
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  pinMode(led21, OUTPUT);
  pinMode(led22, OUTPUT);
  pinMode(led23, OUTPUT);
  pinMode(led24, OUTPUT);
  pinMode(led25, OUTPUT);
  pinMode(led26, OUTPUT);
}

void loop() {

  int reading = digitalRead(buttonPin);
  int reading2 = digitalRead(buttonPin2);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonState = reading;
  }

  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  } 
  
  if ((millis() - lastDebounceTime2) > debounceDelay) {
    buttonState2 = reading2;
  }

//  int button = buttonState + buttonState2;
   if (!buttonState == 1 && lastButtonState == 1 && inicio == 1){
    cont1++;
    delay(200);
   }
   if (!buttonState2 == 1 && lastButtonState2 == 1 && inicio == 1){
    cont2++;
    delay(200);
   }
//  digitalWrite(ledPinB, !button);
  if (!buttonState == 1 && lastButtonState == 1 && !buttonState2 == 1 && lastButtonState2 == 1 && inicio == 0){
      digitalWrite(led11, LOW);
      digitalWrite(led12, LOW);
      digitalWrite(led13, LOW);
      digitalWrite(led14, LOW);
      digitalWrite(led15, LOW);
      digitalWrite(led16, LOW);
      digitalWrite(led21, LOW);
      digitalWrite(led22, LOW);
      digitalWrite(led23, LOW);
      digitalWrite(led24, LOW);
      digitalWrite(led25, LOW);
      digitalWrite(led26, LOW);
      digitalWrite(ledPinR, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(ledPinR, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);               // wait for a second
      digitalWrite(ledPinB, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(ledPinB, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);               // wait for a second
      digitalWrite(ledPinG, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second      
      digitalWrite(ledPinG, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);
      cont1 = 0;
      cont2 = 0;
      inicio = 1;
    }
    
   if (inicio == 1){
    switch (cont1) {
      case 1:
        digitalWrite(led11, HIGH);
        break;
      case 2:
        digitalWrite(led12, HIGH);
        break;
      case 3:
        digitalWrite(led13, HIGH);
        break;
      case 4:
        digitalWrite(led14, HIGH);
        break; 
      case 5:
        digitalWrite(led15, HIGH);
        cont2 = 7;
        digitalWrite(led16, HIGH);
        inicio = 0;
        break;
      default:
        ;
    break;
    }
    switch (cont2) {
      case 1:
        digitalWrite(led21, HIGH);
        break;
      case 2:
        digitalWrite(led22, HIGH);
        break;
      case 3:
        digitalWrite(led23, HIGH);
        break;
      case 4:
        digitalWrite(led24, HIGH);
        break; 
      case 6:
        digitalWrite(led25, HIGH);
        cont1 = 7;
        digitalWrite(led26, HIGH);
        inicio = 0;
        break;
      default:
        ;
}
   }
  lastButtonState = reading;
  lastButtonState2 = reading2;
}
