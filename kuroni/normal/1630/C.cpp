#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        r[u] = i;
        if (l[u] == 0) {
            l[u] = i;
        }
    }
    vector<pair<int, int>> ve;
    for (int i = 1; i <= n; i++) {
        if (r[i] > l[i]) {
            ve.push_back({l[i], r[i]});
        }
    }
    sort(ve.begin(), ve.end());
    vector<pair<int, int>> st, all;
    int ans = 0;
    for (auto [l, r] : ve) {
        if (st.empty() || st.back().second < r) {
            if (st.empty() || st.back().second < l) {
                ans--;
                all.push_back({l, r});
            } else if (st.size() >= 2 && st[st.size() - 2].second > l) {
                st.pop_back();
            }
            all.back().second = r;
            st.push_back({l, r});
        }
    }
    // for (auto [l, r] : st) {
    //     // cout << l << " " << r << '\n';
    // }
    for (auto [l, r] : all) {
        // cout << l << "-" << r << '\n';
        ans += r - l + 1;
    }
    ans -= st.size();
    cout << ans << '\n';
}