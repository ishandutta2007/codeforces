#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x].push_back(i);
    }

    vector<vector<int>> segs(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        segs[l].push_back(-1);
        segs[r].push_back(l);
    }

    multiset<int> open;
    vector<int> left(n);
    for (int i = 0; i < n; i++) {
        for (auto x : segs[i]) {
            if (x == -1) {
                open.insert(i);
            } else {
                open.erase(open.find(x));
            }
        }
        left[i] = open.empty() ? -1 : *open.begin();
    }

    int start_from = 0;
    vector<vector<pair<int, int>>> events(n);
    for (auto &[_, v] : freq) {
        for (int i = 0; i < len(v); i++) {
            if (left[v[i]] == -1) continue;
            int j = lower_bound(all(v), left[v[i]]) - v.begin();
            assert(j <= i);
            if (j == i) continue;

            start_from = max(start_from, v[i - 1]);
            events[v[i - 1]].emplace_back(-1, v[j]);
            events[v[i]].emplace_back(v[j], v[j + 1]);
        }
    }

    multiset<int> conds;
    int ans = n;
    for (int i = 0; i < n; i++) {
        for (auto [from, to] : events[i]) {
            if (from != -1) {
                conds.erase(conds.find(from));
            }
            conds.insert(to);
        }
        if (i < start_from) continue;

        if (conds.empty()) {
            ans = 0;
        } else {
            ans = min(ans, i - *conds.begin() + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}