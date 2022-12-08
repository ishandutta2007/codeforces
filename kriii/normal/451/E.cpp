#include <stdio.h>

const long long mod = 1000000007;
int N; long long S,A[22],inv[22];

int main()
{
    scanf ("%d %lld",&N,&S);
    for (int i=0;i<N;i++){
        scanf ("%lld",&A[i]); A[i]++;
    }
    inv[1] = 1;
    for (int i=2;i<=N;i++){
        inv[i] = (mod - mod / i) * inv[mod%i] % mod;
    }

    long long ans = 0;

    for (int i=0;i<(1<<N);i++){
        long long g = 1, s = 0;
        for (int j=0;j<N;j++) if (i & (1 << j)){
            g = -g;
            s += A[j];
        }

        if (S >= s){
            s = S - s; s += N - 1; s %= mod;
            if (s >= N-1){
                g = (mod + g) % mod;
                for (long long i=s;i>=s-N+2;i--) g = (g * i) % mod;
                for (int i=1;i<=N-1;i++) g = (g * inv[i]) % mod;
                ans = (ans + g) % mod;
            }
        }
    }

    printf ("%lld\n",ans);

    return 0;
}