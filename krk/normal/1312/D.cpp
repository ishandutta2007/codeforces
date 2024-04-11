#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n, m;
int fac[Maxn], inv[Maxn];

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
    scanf("%d %d", &n, &m);
    if (n == 2) { printf("0\n"); return 0; }
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
        res = (res + C(i - 1, n - 2)) % mod;
    res = ll(res) * (n - 2) % mod;
    for (int i = 0; i < n - 3; i++)
        res = ll(res) * 2ll % mod;
    printf("%d\n", res);
    return 0;
}