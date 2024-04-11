#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    constexpr int INF = 1 << 30;
    vector<pair<int, int>> tree(2 * n);
    
    auto update = [&](int pos, int value) {
        pos += n;
        tree[pos] = {value, pos - n};
        for (pos >>= 1; pos; pos >>= 1) {
            tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
        }
    };

    auto query = [&](int l, int r) {
        pair<int, int> ans{INF, n};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = min(ans, tree[l++]);
            if (r & 1) ans = min(ans, tree[--r]);
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        update(i, a[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        int cnt = min(35, r - l);
        vector<int> inds;
        inds.reserve(cnt);
        while (cnt--) {
            inds.push_back(query(l, r).second);
            update(inds.back(), INF);
        }

        int ans = INF;
        for (int i = 0; i < len(inds); i++) {
            for (int j = i + 1; j < len(inds); j++) {
                ans = min(ans, a[inds[i]] | a[inds[j]]);
            }
        }
        cout << ans << '\n';

        for (auto x : inds) {
            update(x, a[x]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}