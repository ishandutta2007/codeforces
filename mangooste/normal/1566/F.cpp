#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    sort(all(a));

    vector<pair<ll, ll>> segs;
    for (int i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;

        auto it = lower_bound(all(a), l);
        if (it == a.end() || r < *it)
            segs.emplace_back(l, r);
    }

    m = len(segs);
    sort(all(segs));

    constexpr ll INF = 1e13;
    vector<ll> dp(m + 1, INF);
    dp[0] = 0;

    ll prev_x = -INF;
    for (int i = 0; i < n; prev_x = a[i++]) {
        int pos1 = lower_bound(all(segs), pair<ll, ll>{prev_x, 0}) - segs.begin();
        int pos2 = lower_bound(all(segs), pair<ll, ll>{a[i], 0}) - segs.begin();
        int pos3 = lower_bound(all(segs), pair<ll, ll>{i == n - 1 ? INF : a[i + 1], 0}) - segs.begin();

        int new_size = pos3 - pos2 + 1;
        int prev_size = pos2 - pos1 + 1;
        vector<ll> new_dp(new_size, INF);

        vector<ll> pref(new_size + 1, INF);
        vector<ll> suf(new_size, INF);

        ll cur_r = a[i];
        for (int j = pos2; j >= pos1; j--) {
            if (j != pos2)
                cur_r = min(cur_r, segs[j].second);

            int id = j - pos1;
            int from = min<int>(pos3, lower_bound(all(segs), pair<ll, ll>{2 * a[i] - cur_r, 0}) - segs.begin()) - 1;
            int id_from = from - pos2 + 1;

            suf[id_from] = min(suf[id_from], a[i] - cur_r + dp[id]);
            pref[id_from + 1] = min(pref[id_from + 1], 2 * (a[i] - cur_r) + dp[id]);
        }

        for (int i = new_size - 2; i >= 0; i--)
            suf[i] = min(suf[i], suf[i + 1]);

        for (int i = 1; i < new_size; i++)
            pref[i] = min(pref[i], pref[i - 1]);

        for (int j = 0; j < new_size; j++) {
            ll cur_l = j == 0 ? a[i] : segs[pos2 + j - 1].first;
            new_dp[j] = min(pref[j] + cur_l - a[i], suf[j] + 2 * (cur_l - a[i]));
        }

        dp = new_dp;
    }

    cout << dp.back() << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}