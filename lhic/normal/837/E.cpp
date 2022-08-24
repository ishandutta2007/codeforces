#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

ll x, y;
vector<ll> vv;

int main() {
    cin >> x >> y;
    ll tmp = x;
    for (ll i = 2; i * i <= tmp; ++i) {
        if (tmp % i != 0)
            continue;
        vv.push_back(i);
        while (tmp % i == 0)
            tmp /= i;
    }
    if (tmp != 1)
        vv.push_back(tmp);
    ll ans = 0;
    while (y != 0) {
        ll g = __gcd(x, y);
        x /= g, y /= g;
        ll mx = 0;
        for (ll i: vv) {
            if (x % i == 0) {
                mx = max(mx, (y / i) * i);
            }
        }
        ans += y - mx;
        y = mx;
    }
    cout << ans << "\n";
    return 0;
}