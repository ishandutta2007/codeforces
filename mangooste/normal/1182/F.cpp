#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    ll a, b, p, q;
    cin >> a >> b >> p >> q;
    p <<= 1, q <<= 1;
    ll h = q >> 1;

    auto query = [&](ll x) {
        ll rem = x * p % q;
        return abs(rem - h);
    };

    auto compare = [&](ll x, ll y) {
        ll qx = query(x), qy = query(y);
        if (qx != qy) return qx < qy;
        return x < y;
    };

    ll best = a;
    const int B = max<int>(1, sqrt(b - a + 1));
    vector<pair<ll, int>> rems;
    for (int i = 0; i < B; i++) {
        rems.emplace_back(p * (a + i) % q, a + i);
        if (compare(a + i, best)) best = a + i;
    }
    sort(all(rems));
    vector<pair<ll, int>> new_rems;
    for (int i = 0; i < B; i++) {
        if (i == 0 || rems[i].first != rems[i - 1].first) {
            new_rems.push_back(rems[i]);
        }
    }
    rems = new_rems;

    for (ll c = 1;; c++) {
        ll from = a + c * B, to = from + B;
        if (to > b) {
            for (ll i = from; i <= b; i++) {
                if (compare(i, best)) best = i;
            }
            break;
        }

        ll value = c * B * p % q;
        ll need = (h - value + q) % q;
        int pos = lower_bound(all(rems), pair{need, -1}) - rems.begin();
        for (int d = -1; d <= 1; d++) {
            int i = (pos + d + len(rems)) % len(rems);
            int cur = c * B + rems[i].second;
            if (compare(cur, best)) best = cur;
        }
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}