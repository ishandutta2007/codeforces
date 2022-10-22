#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int fac[Maxn], inv[Maxn];
int n, m, a, b;
int res;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int z = 0; z <= n - 2; z++) {
        int ways = ll(C(n - 2, z)) * fac[z] % mod * C(m - 1, z) % mod;
        int ways2 = 1;
        if (z < n - 2)
            ways2 = ll(z + 2) * toPower(n, n - z - 3) % mod * toPower(m, n - (z + 2)) % mod;
        res = (res + ll(ways) * ways2) % mod;
    }
    printf("%d\n", res);
    return 0;
}