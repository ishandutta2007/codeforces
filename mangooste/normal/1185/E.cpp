#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> table(n), kek_table(m, string(n, '0'));
        for (auto &el : table) {
            cin >> el;
        }
        int mx_el = -1;
        pii where = mp(-1, -1);
        vector<vector<pii>> poses(26);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (table[i][j] != '.') {
                    poses[table[i][j] - 'a'].eb(i, j);
                } else {
                    table[i][j] = 'a' - 1;
                }
                if (mx_el < table[i][j] - 'a') {
                    mx_el = table[i][j] - 'a';
                    where = mp(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                kek_table[j][i] = table[i][j];
            }
        }
        bool ok = true;
        vector<array<int, 4>> ans;
        for (int ch = 0; ch < 26 && ch <= mx_el && ok; ch++) {
            if (poses[ch].empty()) {
                ans.pb({where.first, where.second, where.first, where.second});
            } else {
                bool chk_row = true, chk_col = true;
                int need_row = poses[ch][0].first;
                int need_col = poses[ch][0].second;
                for (int i = 1; i < poses[ch].size(); i++) {
                    chk_row &= (poses[ch][i].first == need_row);
                    chk_col &= (poses[ch][i].second == need_col);
                }
                if (chk_row) {
                    sort(all(poses[ch]), [](pii &a, pii &b) {
                        return a.second < b.second;
                    });
                    int mn = poses[ch][0].second, mx = poses[ch].back().second;
                    ans.pb({need_row, mn, need_row, mx});
                    ok &= (*min_element(table[need_row].begin() + mn, table[need_row].begin() + mx + 1) >= ch + 'a');
                } else if (chk_col) {
                    sort(all(poses[ch]), [](pii &a, pii &b) {
                        return a.first < b.first;
                    });
                    int mn = poses[ch][0].first, mx = poses[ch].back().first;
                    ans.pb({mn, need_col, mx, need_col});
                    ok &= (*min_element(kek_table[need_col].begin() + mn, kek_table[need_col].begin() + mx + 1) >= ch + 'a');
                } else {
                    ok = false;
                }
            }
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << ' ' << ans[i][2] + 1 << ' ' << ans[i][3] + 1 << '\n';
            }
        }
    }
}