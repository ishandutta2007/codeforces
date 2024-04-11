#include <stdio.h>

const long long mod = 1000000007;
long long inv[2002002];

int N;

int main()
{
    scanf ("%d",&N);
    inv[1] = 1;
    for (int i=2;i<=2*N+2;i++){
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    long long ans = 1;
    for (int i=N+2;i<=2*N+2;i++) ans = ans * i % mod;
    for (int i=1;i<=N+1;i++) ans = ans * inv[i] % mod;
    printf ("%lld\n",(ans+mod-1)%mod);

    return 0;
}