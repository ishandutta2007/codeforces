#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double h, r;
    cin >> r >> h;
    double k = h/r;
    int num = 0;
    while(k >= 0.9999999){
        num+=2;
        k -= 1;
    }
    if(k >= 0.866025){
        num+=3;
    } else if(k >= 0.4999999){
        num += 2;
    } else {
        num ++;
    }
    cout << num << endl;
    return 0;
}