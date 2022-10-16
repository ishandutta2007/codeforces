#include <iostream>
#include <cstdio>
#include <limits.h>
#include <math.h>
using namespace std;
const int INF = INT_MAX;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n, x, y, d;
        scanf("%d%d%d%d", &n, &x, &y, &d);
        int res = INF;
    
        if(abs(x - y) % d == 0) res = min(res, abs(x - y) / d);
        if((y - 1) % d == 0) res = min(res, (int)ceil((x - 1.0) / d) + (y - 1) / d);
        if((n - y) % d == 0) res = min(res, (int)ceil((double)(n - x) / d) + (n - y) / d);
        printf("%d\n", res == INF ? -1 : res);
    }
    return 0;
}