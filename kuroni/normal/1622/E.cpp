#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        vector<string> s(n);
        pair<long long, vector<pair<int, int>>> ans = {0, {}};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int msk = 0; msk < (1 << n); msk++) {
            long long cur = 0;
            vector<pair<int, int>> coe(m);
            for (int i = 0; i < m; i++) {
                coe[i].second = i;
            }
            for (int i = 0; i < n; i++) {
                cur += (msk >> i & 1 ? 1 : -1) * a[i];
                for (int j = 0; j < m; j++) {
                    coe[j].first += (s[i][j] == '1') * (msk >> i & 1 ? -1 : 1);
                }
            }
            sort(coe.begin(), coe.end());
            for (int i = 0; i < m; i++) {
                cur += coe[i].first * (i + 1);
                coe[i].first = i + 1;
            }
            sort(coe.begin(), coe.end(), [](const pair<int, int> u, const pair<int, int> v) {
                return u.second < v.second;
            });
            ans = max(ans, {cur, coe});
        }
        for (int i = 0; i < m; i++) {
            cout << ans.second[i].first << " \n"[i == m - 1];
        }
    }
}