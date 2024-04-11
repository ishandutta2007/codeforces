#include<iostream>
#define LL long long
using namespace std;

int main(){
    LL n;
    cin >> n;
    LL pow3[38];
    pow3[0] = 1;
    for(int i = 1; i < 38; i++){
        pow3[i] = pow3[i-1]*3;
    }
    for(int i = 0; i < 38; i++){
        if(n % pow3[i] != 0){
            cout << (n/pow3[i])+1 << endl;
            return 0;
        }
    }
}