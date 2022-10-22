#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l1, r1, t1;
ll l2, r2, t2;
ll a1;
ll a2;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    cin >> l1 >> r1 >> t1;
    cin >> l2 >> r2 >> t2;
    a1 = r1 - l1 + 1;
    a2 = r2 - l2 + 1;
    ll g = gcd(t1, t2);
    int md = ((l2 - l1) % t1 + t1) % t1;
    md %= g;
    ll res1 = min(a1 - md, a2);
    ll lose = -(md - g);
    ll res2 = min(a1, a2 - lose);
    cout << max(max(res1, res2), 0ll) << endl;
    return 0;
}