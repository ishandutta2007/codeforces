#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll a, m;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll Phi(ll n)
{
    ll res = n;
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
        res -= res / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) res -= res / n;
    return res;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d %I64d", &a, &m);
        ll g = gcd(a, m);
        a /= g; m /= g;
        printf("%I64d\n", Phi(m));
    }
    return 0;
}