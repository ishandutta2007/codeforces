#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, x, y;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y); x /= g; y /= g;
    printf("%I64d\n", min(a / x, b / y));
    return 0;
}