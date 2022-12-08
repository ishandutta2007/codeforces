#include <stdio.h>

int N, M;
char S[100003];

int main()
{
    scanf("%d %d %s", &N, &M, S + 1);
    int L = 0;
    while (S[L+1]) L++;
    int dif = 0;
    long long ans = -(M-1) * L;
    for (int i = L; i >= 1; i--){
        if (S[i] != S[i + 1]) dif++;
        ans += dif * (M - 1);
    }
    dif = 0;
    for (int i = 1; i <= L; i++){
        if (S[i] != S[i - 1]) dif++;
        ans += dif * (M - 1);
    }

    char p = 0, q = 0; int l = 2;
    for (int i=1;i<=L;i++){
        char r = S[i];
        if (p == r) l++;
        else l = 2;
        p = q; q = r;
        if (p && q && p != q && l >= 2) ans -= l - 1;
    }

    printf ("%lld\n",ans);

    return 0;
}