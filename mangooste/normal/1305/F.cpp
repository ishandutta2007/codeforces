#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int ans = n;
    while (double(clock()) / CLOCKS_PER_SEC < 2) {
        ll value = a[rng() % n];
        for (auto x : {value - 1, value, value + 1}) {
            if (x <= 1) continue;

            auto relax = [&](ll y) {
                ll tot = 0;
                for (auto x : a) {
                    ll rem = x % y;
                    if (x == rem) {
                        tot += y - rem;
                    } else {
                        tot += min(rem, y - rem);
                    }
                }
                ans = min<ll>(ans, tot);
            };

            for (ll y = 2; y * y <= x; y++) {
                if (x % y == 0) {
                    while (x % y == 0) x /= y;
                    relax(y);
                }
            }
            if (x != 1) relax(x);
        }
    }
    cout << ans << '\n';
}