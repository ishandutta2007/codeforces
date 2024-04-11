#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y;
multiset<ll> sdiv;

int main() {
    cin >> x >> y;
    ll x2 = x;
    for (int k = 2; k <= 1000000; k++) {
        while (x2 % k == 0) sdiv.insert(k), x2 /= k;
    }
    if (x2 > 1) sdiv.insert(x2);

    ll ans = 0;
    while (y > 0) {
        vector<ll> rem;
        for (ll d : sdiv)
            if (y % d == 0) {
                y /= d;
                rem.push_back(d);
            }
        for (ll d : rem) sdiv.erase(sdiv.find(d));

        if (sdiv.empty()) { // x = 1
            ans += y;
            break;
        }

        ll ma = 0;
        for (ll d : sdiv)
            ma = max(ma, d * (y / d));
        ans += y - ma;
        y = ma;
    }

    cout << ans << '\n';
}