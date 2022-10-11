#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define len(a) int(a.size())
#define all(a) (a).begin(), (a).end()

void norm(pair<ll, ll> &a) {
    if (a.second < a.first) swap(a.second, a.first);
}

bool inter(pair<ll, ll> a, pair<ll, ll> b) {
    return min(a.second, b.second) >= max(a.first, b.first);
}

pair<ll, ll> get(pair<ll, ll> a, pair<ll, ll> b) {
    if (inter(a, b)) {
        return {0, max({abs(b.second - a.first), abs(b.first - a.first),
                        abs(b.second - a.second), abs(b.first - a.second)})};
    } else {
        return {min({abs(b.second - a.first), abs(b.first - a.first),
                     abs(b.second - a.second), abs(b.first - a.second)}),
                max({abs(b.second - a.first), abs(b.first - a.first),
                     abs(b.second - a.second), abs(b.first - a.second)})};
    }
}

bool can(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d) {
    return inter(get(a, b), get(c, d));
}

bool can(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d, ll mid) {
    norm(a);
    norm(b);
    norm(c);
    norm(d);
    return can(a, b, {c.first - mid, c.second + mid}, d)
        || can(a, b, c, {d.first - mid, d.second + mid});
}

ll relax(array<pair<ll, ll>, 4> ps) {
    ll ans = 0;
    ans += abs(ps[0].second - ps[1].second);
    ans += abs(ps[2].second - ps[3].second);
    ans += abs(ps[0].first - ps[3].first);
    ans += abs(ps[1].first - ps[2].first);

    ll l = -1, r = 1e15;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (can({ps[0].second, ps[1].second}, {ps[2].second, ps[3].second}, {ps[0].first, ps[3].first},
                {ps[1].first, ps[2].first}, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    ans += 2 * r;
//    dbg(ps, ans);
    return ans;
}

void solve() {
    array<pair<ll, ll>, 4> ps;
    for (int i = 0; i < 4; i++) {
        cin >> ps[i].first >> ps[i].second;
    }

    vector<int> inds(4);
    iota(all(inds), 0);

    ll ans = LLONG_MAX;
    do {
        array<pair<ll, ll>, 4> cur;
        for (int i = 0; i < 4; i++) {
            cur[i] = ps[inds[i]];
        }
        ans = min(ans, relax(cur));
    } while (next_permutation(all(inds)));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}