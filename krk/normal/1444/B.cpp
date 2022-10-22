#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int mod = 998244353;

int fac[Maxn], ifac[Maxn];
int n;
int a[Maxn];

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
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = (sum - a[i] + mod) % mod;
    for (int i = n; i < 2 * n; i++)
        sum = (sum + a[i]) % mod;
    int mult = 0;
    for (int i = 0; i <= n; i++)
        mult = (mult + ll(C(n, i)) * C(n, i)) % mod;
    int res = ll(sum) * mult % mod;
    printf("%d\n", res);
    return 0;
}