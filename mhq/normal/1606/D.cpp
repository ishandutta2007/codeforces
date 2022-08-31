#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> inds(n);
        iota(inds.begin(), inds.end(), 0);
        sort(inds.begin(), inds.end(), [&](int x, int y) {
            return a[x][0] > a[y][0];
        });
        vector<vector<int>> pref_min(n, vector<int>(m));
        vector<vector<int>> pref_max(n, vector<int>(m));
        vector<vector<int>> suf_min(n, vector<int>(m));
        vector<vector<int>> suf_max(n, vector<int>(m));
        for (int i = 0; i + 1 < m; i++) {
            int cur_mn = 1e9;
            for (int j = 0; j + 1 < n; j++) {
                cur_mn = min(cur_mn, a[inds[j]][i]);
                pref_min[j][i] = cur_mn;
                if (i > 0) {
                    pref_min[j][i] = min(pref_min[j][i], pref_min[j][i - 1]);
                }
            }
            int cur_max = -1e9;
            for (int j = n - 1; j >= 1; j--) {
                cur_max = max(cur_max, a[inds[j]][i]);
                pref_max[j][i] = cur_max;
                if (i > 0) {
                    pref_max[j][i] = max(pref_max[j][i], pref_max[j][i - 1]);
                }
            }
        }
        for (int i = m - 1; i > 0; i--) {
            int cur_max = -1e9;
            for (int j = 0; j + 1 < n; j++) {
                cur_max = max(cur_max, a[inds[j]][i]);
                suf_max[j][i] = cur_max;
                if (i + 1 < m) {
                    suf_max[j][i] = max(suf_max[j][i], suf_max[j][i + 1]);
                }
            }
            int cur_mn = 1e9;
            for (int j = n - 1; j >= 1; j--) {
                cur_mn = min(cur_mn, a[inds[j]][i]);
                suf_min[j][i] = cur_mn;
                if (i + 1 < m) {
                    suf_min[j][i] = min(suf_min[j][i], suf_min[j][i + 1]);
                }
            }
        }
        bool fnd = false;
        for (int i = 0; i + 1 < m; i++) {
            if (fnd) break;
            for (int j = 0; j + 1 < n; j++) {
                if (pref_min[j][i] > pref_max[j + 1][i] && suf_min[j + 1][i + 1] > suf_max[j][i + 1]) {
                    cout << "YES\n";
                    string s(n, 'B');
                    for (int x = 0; x <= j; x++) {
                        s[inds[x]] = 'R';
                    }
                    cout << s << " " << i + 1 << '\n';
                    fnd = true;
                    break;
                }
            }
        }
        if (!fnd) cout << "NO\n";
    }
    return 0;
}