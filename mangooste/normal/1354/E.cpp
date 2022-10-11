#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
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

int n, m;
int a, b, c;
vector<vector<int>> G;
int cmp_num = 0;
vector<int> col;
vector<vector<pii>> cmp;

inline void GG() {
    cout << "NO\n";
    exit(0);
}

void dfs(int v, int cur_col, int &cnt, int &sz) {
    if (cur_col == 0)
        cnt++;
    sz++;
    col[v] = cur_col;
    cmp.back().eb(v, col[v]);
    for (auto u : G[v]) {
        if (col[u] == -1) {
            dfs(u, cur_col ^ 1, cnt, sz);
        } else if (col[u] == cur_col) {
            GG();
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> a >> b >> c;
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].pb(u);
        G[u].pb(v);
    }
    col.resize(n, -1);
    vector<pii> ps;
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            int cnt = 0, sz = 0;
            cmp.pb({});
            dfs(i, 0, cnt, sz);
            cmp_num++;
            ps.eb(cnt, sz - cnt);
        }
    }
    vector<vector<char>> dp(cmp_num, vector<char>(n + 1, 0));
    dp[0][ps[0].first] = 1;
    dp[0][ps[0].second] = 1;
    for (int i = 1; i < cmp_num; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - ps[i].first >= 0 && dp[i - 1][j - ps[i].first]) {
                dp[i][j] = 1;
            }
            if (j - ps[i].second >= 0 && dp[i - 1][j - ps[i].second]) {
                dp[i][j] = 1;
            }
        }
    }
    if (!dp[cmp_num - 1][b]) {
        GG();
    }
    int pos = cmp_num - 1, cnt = b;
    vector<int> ans(n, -1);
    while (pos >= 0) {
        if (pos == 0) {
            if (cnt == ps[0].first) {
                for (auto el : cmp[pos]) {
                    if (el.second == 0) {
                        ans[el.first] = 2;
                    }
                }
            } else if (cnt == ps[0].second) {
                for (auto el : cmp[pos]) {
                    if (el.second == 1) {
                        ans[el.first] = 2;
                    }
                }
            } else {
                assert(false);
            }
        } else {
            if (cnt - ps[pos].first >= 0 && dp[pos - 1][cnt - ps[pos].first]) {
                for (auto el : cmp[pos]) {
                    if (el.second == 0) {
                        ans[el.first] = 2;
                    }
                }
                cnt -= ps[pos].first;
            } else if (cnt - ps[pos].second >= 0 && dp[pos - 1][cnt - ps[pos].second]) {
                for (auto el : cmp[pos]) {
                    if (el.second == 1) {
                        ans[el.first] = 2;
                    }
                }
                cnt -= ps[pos].second;
            } else {
                assert(false);
            }
        }
        pos--;
    }
    cout << "YES\n";
    for (auto el : ans) {
        if (el != -1) {
            cout << 2;
        } else if (a == 0) {
            cout << 3;
            b--;
        } else {
            cout << 1;
            a--;
        }
    }
    cout << '\n';
}