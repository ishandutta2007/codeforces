#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 3000006;
const int Maxd = 3;

int fac[Maxn], ifac[Maxn];
int inv[Maxn];
int n, q;
int A[Maxn];
int B[Maxd + 1];
int C[Maxn];

int FC(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    inv[1] = 1;
    for (int i=2; i<Maxn; ++i)
        inv[i] = (mod - ll(mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        ifac[i] = ll(ifac[i - 1]) * inv[i] % mod;
    }
    scanf("%d %d", &n, &q);
    int N = 3 * n + 3;
    for (int i = 0; i <= N; i++)
        A[i] = FC(N, i);
    for (int i = 1; i <= Maxd; i++)
        B[i] = FC(Maxd, i);
    for (int i = N; i >= Maxd; i--) {
        int mult = A[i];
        for (int j = Maxd; j >= 0; j--)
            A[i - (Maxd - j)] = (A[i - (Maxd - j)] - ll(mult) * B[j] % mod + mod) % mod;
        C[i - Maxd] = mult;
    }
    while (q--) {
        int k; scanf("%d", &k);
        printf("%d\n", C[k]);
    }
    return 0;
}