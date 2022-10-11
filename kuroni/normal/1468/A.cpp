#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int t, n, u, a[N], ans[N], le[N];

struct bit {
    int bit[N];

    void init() {
        fill(bit + 1, bit + n + 1, 0);
    }

    void update(int u, int v) {
        for (; u <= n; u += u & -u) {
            bit[u] = max(bit[u], v);
        }
    }

    int query(int u) {
        int ans = 0;
        for (; u > 0; u -= u & -u) {
            ans = max(ans, bit[u]);
        }
        return ans;
    }
} bit;

void solve() {
    vector<pair<int, int>> ve, st;
    cin >> n;
    bit.init();
    for (int i = 1; i <= n; i++) {
        cin >> u;
        ve.push_back({u, i});
        while (!st.empty() && st.back().second <= u) {
            st.pop_back();
        }
        le[i] = (st.empty() ? -1 : st.back().first);
        st.push_back({i, u});
    }
    sort(ve.begin(), ve.end());
    for (auto [_, i] : ve) {
        ans[i] = bit.query(i - 1) + 1;
        if (le[i] != -1) {
            ans[i] = max(ans[i], bit.query(le[i]) + 2);
        }
        bit.update(i, ans[i]);
        // cout << i << ": " << ans[i] << '\n';
    }
    cout << *max_element(ans + 1, ans + n + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}