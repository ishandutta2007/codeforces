#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 1005;
int p[maxN][maxN];
vector<int> g[maxN];
bool can[maxN][maxN];
int cnt[maxN][maxN];
bool used[maxN][maxN];
bool was[maxN];
vector<int> by[maxN][maxN];
bool marked[maxN][maxN];
vector<int> z[2];
bool last[maxN];
int clr[maxN];
void dfs(int v) {
    last[v] = true;
    z[clr[v]].emplace_back(v);
    for (int to : g[v]) {
        if (!last[to]) {
            clr[to] = clr[v] ^ 1;
            dfs(to);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt[i][j] = 0;
            used[i][j] = false;
            marked[i][j] = false;
            by[i][j].clear();
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        was[i] = false;
        g[i].clear();
        for (int j = 1; j <= n; j++) {
            cin >> p[i][j];
            cnt[j][p[i][j]]++;
            by[j][p[i][j]].emplace_back(i);
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = i + 1; j <= 2 * n; j++) {
            bool ok = true;
            can[i][j] = can[j][i] = false;
            for (int k = 1; k <= n; k++) {
                if (p[i][k] == p[j][k]) {
                    ok = false;
                    break;
                }
            }
            can[i][j] = can[j][i] = ok;
        }
    }
    vector<int> ans;
    queue<pair<int,int>> all;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cnt[i][j] == 1) {
                all.emplace(i, j);
                used[i][j] = true;
            }
        }
    }
    while (!all.empty()) {
        auto it = all.front();
        all.pop();
        int pos = it.first;
        int val = it.second;
        if (marked[pos][val]) continue;
        int who = -1;
        for (auto& id : by[pos][val]) {
            if (was[id]) continue;
            assert(who == -1);
            who = id;
        }
        was[who] = true;
        ans.emplace_back(who);
        for (int z = 1; z <= n; z++) {
            marked[z][p[who][z]] = true;
            used[z][p[who][z]] = true;
        }
        for (int z = 1; z <= 2 * n; z++) {
            if (z != who && !can[who][z]) {
                if (was[z]) continue;
                was[z] = true;
                for (int r = 1; r <= n; r++) {
                    if (!used[r][p[z][r]]) {
                        cnt[r][p[z][r]]--;
                        if (cnt[r][p[z][r]] == 1) {
                            used[r][p[z][r]] = true;
                            all.emplace(r, p[z][r]);
                        }
                    }

                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!used[i][j]) {
                assert(cnt[i][j] == 2);
                vector<int> t;
                for (auto& it : by[i][j]) {
                    if (!was[it]) {
                        t.emplace_back(it);
                    }
                }
                assert(t.size() == 2);
                g[t[0]].emplace_back(t[1]);
                g[t[1]].emplace_back(t[0]);
            }
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        last[i] = false;
        clr[i] = 0;
    }
    int coef = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (!was[i] && !g[i].empty() && !last[i]) {
            z[0].clear();
            z[1].clear();
            dfs(i);
            assert(z[0].size() == z[1].size());
            coef = mult(coef, 2);
            for (int to : z[0]) ans.emplace_back(to);
        }
    }
    cout << coef << '\n';
    assert(ans.size() == n);
    for (int r : ans) cout << r << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}