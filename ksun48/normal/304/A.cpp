
//CALVIN WANNA CODE
#include <iostream>
#include <math.h>
//#include <calvin>
using namespace std;


int main() {
    int n;
    cin >> n;
    int k = 0;
    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b++){
            double c = sqrt((a*a+b*b)+0.000000001);
            if(c <= int(c)+ 0.00000001 && c <= n + 0.000000001){
                k++;
            }
        }
    }
    cout << k << endl;
    return 0;
}