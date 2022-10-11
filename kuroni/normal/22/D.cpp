#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n, l, r;
vector<int> ans;
vector<pair<int, int>> ve, st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        ve.push_back({l, r});
    }
    sort(ve.begin(), ve.end());
    for (auto [l, r] : ve) {
        while (!st.empty() && st.back().se >= r) {
            st.pop_back();
        }
        st.push_back({l, r});
    }
    int pt = -100000;
    for (auto [l, r] : st) {
        // cout << l << " - " << r << '\n';
        if (pt < l) {
            ans.push_back(pt = r);
        }
    }
    cout << ans.size() << '\n';
    for (int v : ans) {
        cout << v << " ";
    }
}