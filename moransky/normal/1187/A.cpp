#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n, s, t;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &s, &t);
        printf("%d\n", max(s, t) - (s + t - n) + 1);
    }
    return 0;
}