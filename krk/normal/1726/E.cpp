#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 300005;

int fac[Maxn], inv[Maxn];
int prs[Maxn], rem[Maxn];
int T;
int n;

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
    if (n < 0 || k < 0 || k > n) return 0;
    return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
    prs[0] = 1;
    for (int i = 2; i < Maxn; i += 2)
        prs[i] = ll(i - 1) * 2 * prs[i - 2] % mod;
    rem[0] = 1;
    for (int i = 1; i < Maxn; i++)
        rem[i] = (rem[i - 1] + ll(i - 1) * rem[i - 2]) % mod;
    fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 0; i <= n - i; i += 2)
            res = (res + ll(C(n - i, i)) * prs[i] % mod * rem[n - 2 * i]) % mod;
        printf("%d\n", res);
    }
    return 0;
}