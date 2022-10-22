#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
int q;
ll g;
ll np, mp;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll getPlace(ll a, ll b)
{
    b--;
    if (a == 1) return b / np;
    else return b / mp;
}

int main()
{
    cin >> n >> m >> q;
    g = gcd(n, m);
    np = n / g, mp = m / g;
    while (q--) {
        ll sx, sy; scanf("%I64d %I64d", &sx, &sy);
        ll ex, ey; scanf("%I64d %I64d", &ex, &ey);
        printf("%s\n", getPlace(sx, sy) == getPlace(ex, ey)? "YES": "NO");
    }
    return 0;
}