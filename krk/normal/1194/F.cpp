#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int pw2[Maxn], ipw2[Maxn];
int fac[Maxn], inv[Maxn];
int n;
ll t;
int a[Maxn];
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
    pw2[0] = ipw2[0] = fac[0] = inv[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw2[i] = 2ll * pw2[i - 1] % mod;
        fac[i] = ll(i) * fac[i - 1] % mod;
        inv[i] = Inv(fac[i]);
        ipw2[i] = Inv(pw2[i]);
    }
    scanf("%d %I64d", &n, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int pnt = 1;
    ll sum = 0;
    while (pnt <= n) {
        sum += a[pnt];
        if (sum + pnt <= t) res = (res + 1) % mod;
        else break;
        pnt++;
    }
    if (pnt <= n) {
        t -= sum;
        int all = 0;
        int cur = 0;
        while (cur <= t) {
            all = (all + ll(C(pnt, cur)) * ipw2[pnt]) % mod;
            cur++;
        }
        cur--;
        while (pnt <= n && t >= 0) {
            while (cur > t) {
                all = (all - ll(C(pnt, cur)) * ipw2[pnt] % mod + mod) % mod;
                cur--;
            }
            res = (res + all) % mod;
            all = (ll(all) * 2ll - ll(C(pnt, cur)) * ipw2[pnt] % mod + mod) % mod;
            all = ll(all) * ipw2[1] % mod;
            pnt++; t -= a[pnt];
        }
    }
    printf("%d\n", res);
    return 0;
}