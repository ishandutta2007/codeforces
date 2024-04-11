#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

using Segment = array<ll, 3>;

ll seed;

ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % MOD;
    return ret;
}

void solve() {
    int n, m;
    ll vmax;
    cin >> n >> m >> seed >> vmax;
    set<Segment> segs;
    for (int i = 0; i < n; i++) {
        segs.insert(Segment{i, i, rnd() % vmax + 1});
    }
    vector<Segment> buf;
    vector<pair<ll, int>> comp;
    while (m--) {
        int op = rnd() % 4;
        ll l = rnd() % n;
        ll r = rnd() % n;
        if (l > r) swap(l, r);
        ll X;
        if (op == 2) {
            X = rnd() % (r - l + 1);
        } else {
            X = rnd() % vmax + 1;
        }

        if (op == 0) {
            while (true) {
                auto it = segs.upper_bound(Segment{r, n + 1, 0});
                if (it == segs.begin()) break;
                it = prev(it);
                auto [x, y, z] = *it;
                if (y < l) break;
                if (x < l) {
                    buf.push_back(Segment{x, l - 1, z});
                }
                buf.push_back(Segment{max(x, l), min(y, r), z + X});
                if (r < y) {
                    buf.push_back(Segment{r + 1, y, z});
                }
                segs.erase(it);
            }
            for (const auto& seg : buf) {
                segs.insert(seg);
            }
            buf.clear();
        }
        if (op == 1) {
            while (true) {
                auto it = segs.upper_bound(Segment{r, n + 1, 0});
                if (it == segs.begin()) break;
                it = prev(it);
                auto [x, y, z] = *it;
                if (y < l) break;
                if (r < y) {
                    buf.push_back(Segment{r + 1, y, z});
                }
                if (!buf.empty() && buf.back()[2] == X) {
                    buf.back()[0] = max(x, l);
                } else {
                    buf.push_back(Segment{max(x, l), min(y, r), X});
                }
                if (x < l) {
                    buf.push_back(Segment{x, l - 1, z});
                }
                segs.erase(it);
            }
            for (const auto& seg : buf) {
                segs.insert(seg);
            }
            buf.clear();
        }
        if (op == 2) {
            auto it = segs.upper_bound(Segment{r, n + 1, 0});
            it = prev(it);
            while (it != segs.end() && (*it)[1] >= l) {
                auto [x, y, z] = *it;
                comp.emplace_back(z, min(y, r) - max(x, l) + 1);
                it = prev(it);
            }
            sort(comp.begin(), comp.end());
            for (const auto& [val, cnt] : comp) {
                if (X < cnt) {
                    cout << val << '\n';
                    break;
                }
                X -= cnt;
            }
            comp.clear();
        }
        if (op == 3) {
            ll Y = rnd() % vmax + 1;
            ll res = 0;
            auto it = segs.upper_bound(Segment{l, n + 1, 0});
            it = prev(it);
            while (it != segs.end() && (*it)[0] <= r) {
                auto [x, y, z] = *it;
                res += binpow(z, X, Y) * (min(y, r) - max(x, l) + 1);
                res %= Y;
                it = next(it);
            }
            cout << res << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}