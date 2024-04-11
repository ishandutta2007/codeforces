#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;
const int Maxn = 1000006;

int fac[Maxn], ifac[Maxn];
int pw[Maxn];
int T;
int n, m, k;

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
    return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    pw[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw[i] = ll(pw[i - 1]) * inv2 % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        m = n - m;
        if (m == 0) {
            int res = ll(n) * k % mod;
            printf("%d\n", res);
            continue;
        }
        int res = 0;
        for (int r = 1; r < n; r++) {
            int val = ll(r) * k % mod;
            res = (res + ll(val) * C(n - (r + 1), m - 1) % mod * pw[n - r]) % mod;
        }
        printf("%d\n", res);
    }
    return 0;
}