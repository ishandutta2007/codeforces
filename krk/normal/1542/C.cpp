#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

int T;
ll n;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        int res = 0;
        ll cur = 1;
        for (int i = 2; n != 0; i++) {
            ll ncur = lcm(cur, i);
            res = (res + (n / cur - n / ncur) % mod * i) % mod;
            n = n / ncur * ncur;
            cur = ncur;
        }
        printf("%d\n", res);
    }
    return 0;
}