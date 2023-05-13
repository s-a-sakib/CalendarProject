#include <bits/stdc++.h>

// Declaration of user defined function

void month(int i,int a);
int day_count(int i , int a);
void week();
void days(int a , int b, int c, int d);

using namespace std;

int main(){
    int a , b , j , daycode;
    cout << "Please input the year : 20";
    cin >> a;
    cout << endl;

    int counter = -1;

    // leap yean and non leap year month code
    int non_lp[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int lp[12] = {-1,2,3,6,1,4,6,2,5,0,3,5};

    // user defined funtion call
    for(int i = 1 ; i <= 12 ; i++){
        //calculaing how many days a month have
        b = day_count(i,a); // i is the month and a is the last two digits of the year
        month(i,a); //printing the month name
        week();
        days(a,b,non_lp[i-1],lp[i-1]);
        cout << endl << endl;
    }
    return 0;
}

int day_count(int i , int a){
    int b;
    if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
       return b = 31;
    else if(i == 2 and a % 4 == 0) // leap year february
       return b = 29;
    else if(i == 2 and a % 4 !=  0) // non leap-year february
        return b = 28;
    else return b = 30;
}

void month(int i , int a){
    string Month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    cout << Month[i-1] << " , 20" << a << endl;
}

void week(){
    cout <<"Su   Mo   Tu   We   Th   Fr   Sa"<< endl;
}

void days(int a , int b , int c , int d){
    int daycode , j , k , counter = -1;
    if(a % 4 != 0) daycode = (a + (a / 4) + 1 + c + 6) % 7;
    else daycode = (a + (a / 4) + 1 + d + 6) % 7;

    for(k = 0 ; k <= daycode ; k++){ //for space count
        if(k != 0) cout <<"     ";
        counter = counter + 1;
    }
    for(j = 1; j <= b ; j++){ //day calculation
        if(j < 10) cout << j <<"    ";
        if(j >= 10) cout << j <<"   ";
        counter = counter + 1;
        if(counter % 7 == 0) cout << endl;
    }
    counter = -1;
}