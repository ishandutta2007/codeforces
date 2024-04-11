#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 305, M = 1000000;
typedef long long LL;
int n, d[N], primes[M + 10], tot = 0;
bool st[M + 10];
int main(){
    for(int i = 2; i <= M; i++){
        
        if(!st[i]) primes[++tot] = i;
        for(int j = 1; i <= M / primes[j]; j++){
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }


    int T; scanf("%d", &T);
    while(T--){
        LL ans = 1;
        bool success = true;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", d + i);
        
        sort(d + 1, d + 1 + n);
        LL val = (LL)d[1] * d[n];
        for(int i = 2; i <= (n + 1) >> 1; i++)
            if((LL)d[i] * d[n - i + 1] != val){
                success = false;
                break;
            }
        for(int i = 1; i <= tot && primes[i] <= val / primes[i]; i++) {
            if(val % primes[i] == 0){
                int s = 0;
                while(val % primes[i] == 0) val /= primes[i], s++;
                ans *= (s + 1);
            }
        }
        if(val > 1) ans *= 2;
        
        if(ans - 2 != n) success = false;
        if(success) printf("%lld\n",  (LL)d[1] * d[n]);
        else puts("-1");
    }
    return 0;
}