#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll g;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll a; scanf("%I64d", &a);
        g = gcd(g, a);
    }
    int res = 0;
    for (ll i = 1; i * i <= g; i++) if (g % i == 0) {
        res++;
        if (i * i < g) res++;
    }
    printf("%d\n", res);
    return 0;
}