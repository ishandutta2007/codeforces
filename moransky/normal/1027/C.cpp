#include <iostream>
#include <cstdio>
#include <limits.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 10010;
int n, a, cnt[SIZE], d[SIZE << 1], tot, ansA, ansB;
double c, minn;
 
int main(){
    int T; scanf("%d", &T);
    while(T--){
        memset(cnt, 0, sizeof cnt);
        bool success = false; tot = 0;
        minn = 10001;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a), cnt[a]++;
            if(cnt[a] == 2) d[++tot] = a;
            if(cnt[a] == 4) d[++tot] = a;
        } 
        sort(d + 1, d + 1 + tot);
        for(int i = 1; i < tot; i++){
            if(d[i] == d[i + 1]){ ansA = d[i], ansB = d[i + 1]; break; }
            c = (double)d[i + 1] / d[i];
            if(c < minn)ansA = d[i], ansB = d[i + 1], minn = c;
        }    
        printf("%d %d %d %d\n", ansA, ansA, ansB, ansB);
    }
    return 0;
}