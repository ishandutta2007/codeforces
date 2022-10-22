#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll m, d, w;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d %I64d", &m, &d, &w);
        if (d == 1) {
            printf("0\n");
            continue;
        }
        ll k = lcm(d - 1, w) / (d - 1);
        ll lim = min(m, d);
        ll z = lim / k;
        ll res = z * (lim - k + lim - z * k) / 2;
        printf("%I64d\n", res);
    }
    return 0;
}