#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 190;
int a[N * 2];
int main(){
    for(int i = 3; i <= 360; i++){
        for(int j = 1; j <= i - 2; j++){
            if(180 * j % i == 0 && (!a[180 * j / i]))
                a[180 * j / i] = i; 
        }
    }
    int T; scanf("%d", &T);
    while(T--){
        int deg; scanf("%d", &deg);
        printf("%d\n", a[deg]);
    }
    return 0;
}