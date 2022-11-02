#include <iostream>

using namespace std;

int main () {
    int a;
    int b;
    int t1=-1;
    cin >> a;
    cin >> b;
    if (a>b) {
        t1=a;
        a=b;
        b=t1;
    }
    int ad=a+((double)b-(double)a-1)/2;
    int bd=6-b+1+((double)b-(double)a-1)/2;
    int dd;
    if ((b-a)%2==0) dd=1;
    else dd=0;
    if (a==b) {
        ad=0;
        dd=6;
        bd=0;
    }
    if (t1>-1){
        t1=ad;
        ad=bd;
        bd=t1;
    }
    cout << ad;
    cout << " ";
    cout << dd;
    cout << " ";
    cout << bd << endl;
}