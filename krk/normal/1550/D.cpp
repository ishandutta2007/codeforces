#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int fac[Maxn], ifac[Maxn];
int T;
int n, l, r;

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

int Get(int pos, int neg, int n, int val)
{
    int lft = n - pos - neg;
    int a = n / 2;
    int b = n - a;
    int res = 0;
    if (pos <= a && neg <= b)
        res = (res + C(lft, a - pos)) % mod;
    if (n % 2) {
        swap(a, b);
        if (pos <= a && neg <= b)
            res = (res + C(lft, a - pos)) % mod;
    }
    return ll(res) * val % mod;
}

int main()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = ll(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &l, &r);
        int res = 0;
        int lef = 1, rig = n;
        int pos = 0, neg = 0;
        int oth;
        while (lef <= rig)
            if (lef - l <= r - rig) {
                neg++;
                res = (res + Get(pos, neg, n, lef - l)) % mod;
                neg--;
                pos++;
                lef++;
                oth = r - rig;
            } else {
                pos++;
                res = (res + Get(pos, neg, n, r - rig)) % mod;
                pos--;
                neg++;
                rig--;
                oth = lef - l;
            }
        res = (res + Get(pos, neg, n, oth)) % mod;
        printf("%d\n", res);
    }
    return 0;
}