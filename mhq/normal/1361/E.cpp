#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e5 + 10;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector < int > g[maxN];
bool used[maxN];
int timer = 0;
int tin[maxN];
int tout[maxN];
int h[maxN];
int par[maxN];
void dfs(int v) {
    used[v] = true;
    tin[v] = timer++;
    for (int to : g[v]) {
        if (used[to]) continue;
        h[to] = h[v] + 1;
        par[to] = v;
        dfs(to);
    }
    tout[v] = timer++;
}
int mn[maxN][2];
int to_who[maxN][2];
const int INF = (int)1e9;
void upd(int v, int val, int vert) {
    if (val < mn[v][0]) {
        mn[v][1] = mn[v][0];
        to_who[v][1] = to_who[v][0];
        mn[v][0] = val;
        to_who[v][0] = vert;
    }
    else if (val < mn[v][1]) {
        mn[v][1] = val;
        to_who[v][1] = vert;
    }
}
bool is_bad[maxN];
void sec_dfs(int v) {
    mn[v][0] = INF;
    mn[v][1] = INF;
    for (int to : g[v]) {
        if (par[to] == v) {
            sec_dfs(to);
            for (int j = 0; j < 2; j++) {
                upd(v, mn[to][j], to_who[to][j]);
            }
        }
        else {
            int his_h = h[to];
            upd(v, his_h, to);
        }
    }
    if (par[v] != -1) {
        //not root
        assert(mn[v][0] < h[v]);
        if (mn[v][1] < h[v]) {
            is_bad[v] = true;
        }
    }
}
void last_dfs(int v) {
    if (par[v] != -1) {
        is_bad[v] |= is_bad[to_who[v][0]];
    }
    for (int to : g[v]) {
        if (par[to] == v) {
            last_dfs(to);
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        is_bad[i] = false;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    int C = -1;
    for (int BUBEN = 0; BUBEN < 70; BUBEN++) {
        timer = 0;
        int who = rnd() % n + 1;
        for (int i = 1; i <= n; i++) {
            used[i] = false;
            par[i] = -1;
        }
        h[who] = 0;
        dfs(who);
        bool all_ok = true;
        for (int i = 1; i <= n; i++) {
            if (!all_ok) break;
            for (int to : g[i]) {
                if (par[to] != i && (!(tin[to] <= tin[i] && tout[i] <= tout[to]))) {
                    all_ok = false;
                    break;
                }
            }
        }
        if (all_ok) {
            C = who;
            break;
        }
    }
    if (C == -1) {
        cout << -1 << '\n';
        return;
    }
    sec_dfs(C);
    last_dfs(C);
    vector < int > ans;
    for (int i = 1; i <= n; i++) {
        if (!is_bad[i]) ans.emplace_back(i);
    }
    int at_least = (n + 4) / 5;
    if ((int)ans.size() >= at_least) {
        for (int v : ans) cout << v << " ";
        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }
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