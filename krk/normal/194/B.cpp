#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll n;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        ll res = 4ll * n / gcd(4ll * n, n + 1) + 1ll;
        printf("%I64d\n", res);
    }
    return 0;
}