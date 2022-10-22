#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000ll;

ll x;
ll res = Inf;
ll bi, bj;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    cin >> x;
    for (ll i = 1; i * i <= x; i++) if (x % i == 0) {
        ll j = x / i;
        if (gcd(i, j) == 1) {
            ll cand = max(i, j);
            if (cand < res) { res = cand; bi = i; bj = j; }
        }
    }
    cout << bi << " " << bj << endl;
    return 0;
}