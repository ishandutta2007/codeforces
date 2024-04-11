#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int d;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &d);
        double a, b, delta;
        delta = d * d - 4 * d;
        if(delta < 0) puts("N");
        else delta = sqrt(delta), printf("Y %.9f %.9f\n", (delta + d) / 2, (-delta + d) / 2);
    }
    return 0;
}