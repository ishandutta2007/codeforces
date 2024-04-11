#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxk = 15;
const int mod = 1000000007;

int bits[1 << Maxk];
int fac[Maxk], inv[Maxk];
int n, k, m;
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

int Inv(int a) { return toPower(a, mod - 2); }

int C(int n, int k)
{
    int res = 1;
    for (int i = 0; i < k; i++)
        res = ll(res) * (n - i) % mod;
    return ll(res) * inv[k] % mod;
}

void Solve(int k, int c, int mult)
{
    if (k == 1) {
        if (c > n + 2) return;
        res = (res + ll(n + 2 - c) * mult) % mod;
        return;
    }
    if (c + k - 2 > n) return;
    int res1 = ll(C(n - c + 1, k - 1)) * (n - c + 2) % mod;
    int res2 = ll(C(n - c + 2, k)) * (k - 1) % mod;
    int add = (res1 - res2 + mod) % mod;
    res = (res + ll(add) * mult) % mod;
}

void Gen(int lvl, int dif, int sum, int mask, int mult)
{
    if (lvl >= k) Solve(dif, sum - dif + (dif - 1) * m + 2, mult);
    else {
        for (int i = 0; i <= m; i++) {
            int cnt = bits[mask];
            mask = (mask << 1);
            if (mask & 1 << m) mask ^= 1 << m;
            if (cnt == 0) Gen(lvl + 1, dif + 1, sum + 1, mask | 1, mult);
            else Gen(lvl + 1, dif, sum + i + 1, mask | 1, ll(mult) * (cnt + 1) % mod);
        }
    }
}

int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxk; i++) {
        fac[i] = ll(fac[i - 1]) * i % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i < 1 << m; i++)
        bits[i] = __builtin_popcount(i);
    Gen(1, 1, 1, 1, 1);
    printf("%d\n", res);
    return 0;
}