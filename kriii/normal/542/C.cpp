#include <stdio.h>

int N,P[202],C[202];

long long gcd(long long a, long long b)
{
    return b ? gcd(b,a%b) : a;
}

int main()
{
    scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&P[i]);
    int ov = 1; long long per = 1;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++) C[j] = -1;
        C[i] = 0;
        int x = i, l, u;
        while (1){
            if (C[P[x]] != -1){
                l = C[x] + 1 - C[P[x]];
                u = C[P[x]];
                break;
            }
            C[P[x]] = C[x] + 1;
            x = P[x];
        }
        if (ov < u)
            ov = u;
        per = per / gcd(per,l) * l;
    }
    long long ans = 0;
    while (ans < ov) ans += per;
    printf ("%lld\n",ans);

    return 0;
}