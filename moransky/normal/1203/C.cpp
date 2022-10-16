#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 400005, M = 1000005;
int n, primes[M], tot = 0;
bool st[M];
LL a[N], g, ans = 1;
LL gcd(LL x, LL y){
    return y ? gcd(y, x % y) : x;
}
int main(){
    for(int i = 2; i <= 1000000; i++){
        if(!st[i]) primes[++tot] = i;
        for(int j = 1; i * primes[j] <= 1000000; j++){
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", a + i);
    g = a[1];
    for(int i = 2; i <= n; i++)
        g = gcd(g, a[i]);

    for(int i = 1; i <= tot && primes[i] <= g / primes[i]; i++){
        if(g % primes[i] == 0){
            int s = 0;
            while(g % primes[i] == 0) s++, g /= primes[i];
            ans *= s + 1;
        }
    }
    if(g > 1) ans *= 2;
    printf("%I64d\n", ans);
    return 0;
}