#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod1 = 10000000000ll;
const ll mod2 = 1000000007;
const ll lim = 9000000000000000000ll;

ll Mult(ll a, ll b, ll mod)
{
    a %= mod; b %= mod;
    if (a == 0 || b == 0) return 0;
    if (a <= lim / b) return a * b % mod;
    if (a > b) swap(a, b);
    ll res = 0;
    while (a) {
        if (a & 1) res = (res + b) % mod;
        a >>= 1; b = (b + b) % mod;
    }
    return res;
}

ll S(int x, ll mod)
{
    int a = x, b = x + 1, c = 2 * x + 1;
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    if (a % 3 == 0) a /= 3;
    else if (b % 3 == 0) b /= 3;
    else c /= 3;
    return Mult(Mult(a, b, mod), c, mod);
}

ll C2(ll x, ll mod)
{
    ll a = x, b = x - 1;
    if (a % 2 == 0) a /= 2;
    else b /= 2;
    return Mult(a, b, mod);
}

ll F(ll i, ll j, ll mod)
{
    if (i == 0 || j == 0) return 0;
    ll res = 0;
    if (i <= j) {
        res = C2(ll(i) * i + 1, mod);
        res = (res + Mult(j - i, C2(i + 1, mod), mod)) % mod;
        ll sum = (S(j - 1, mod) - S(i - 1, mod) + mod) % mod;
        res = (res + Mult(i, sum, mod)) % mod;
    } else {
        res = C2(ll(j) * j + 1, mod);
        res = (res - Mult(i - j, C2(j, mod), mod) + mod) % mod;
        ll sum = (S(i, mod) - S(j, mod) + mod) % mod;
        res = (res + Mult(j, sum, mod)) % mod;
    }
    return res;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
        ll res1 = (F(r2, c2, mod1) - F(r1 - 1, c2, mod1) + mod1) % mod1;
        res1 = (res1 - F(r2, c1 - 1, mod1) + mod1) % mod1;
        res1 = (res1 + F(r1 - 1, c1 - 1, mod1)) % mod1;
        ll res2 = (F(r2, c2, mod2) - F(r1 - 1, c2, mod2) + mod2) % mod2;
        res2 = (res2 - F(r2, c1 - 1, mod2) + mod2) % mod2;
        res2 = (res2 + F(r1 - 1, c1 - 1, mod2)) % mod2;
        if (res1 % mod2 == res2) printf("%I64d\n", res1);
        else {
            string lin(13, '.');
            int pnt = 12;
            for (int i = 0; i < 10; i++) {
                lin[pnt--] = res1 % 10 + '0';
                res1 /= 10;
            }
            printf("%s\n", lin.c_str());
        }
    }
    return 0;
}