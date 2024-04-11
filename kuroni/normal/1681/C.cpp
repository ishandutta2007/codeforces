#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[j] < a[j - 1]) {
                    ans.push_back({j, j - 1});
                    swap(a[j], a[j - 1]);
                }
            }
        }
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i].second < a[i - 1].second) {
                ok = false;
            }
        }
        if (ok) {
            cout << ans.size() << '\n';
            for (auto [u, v] : ans) {
                cout << u + 1 << " " << v + 1 << '\n';
            }
        } else {
            cout << "-1\n";
        }
    }
}