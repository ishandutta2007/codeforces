#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 4 * (int)1e5 + 100;
int w[maxN];
vector < pair <int, int > > g[maxN];
bool br[maxN];
int s;
int up[maxN];
bool used[maxN];
int tin[maxN];
int ti = 0;
void dfs(int v, int p) {
    used[v] = true;
    up[v] = tin[v] = ti++;
    for (auto to : g[v]) {
        if (to.first == p) continue;
        if (used[to.first]) {
            up[v] = min(up[v], tin[to.first]);
        }
        else {
            dfs(to.first, v);
            up[v] = min(up[v], up[to.first]);
            if (up[to.first] > tin[v]) {
                br[to.second] = true;
            }
        }
    }
}
int cmp = 0;
int where[maxN];
int sz[maxN];
ll we[maxN];
void dfs2(int v) {
    used[v] = true;
    where[v] = cmp;
    we[cmp] += w[v];
    sz[cmp]++;
    for (auto to : g[v]) {
        if (used[to.first] || br[to.second]) continue;
        dfs2(to.first);
    }
}
vector < int > ed[maxN];
ll sum_on_path[maxN];
ll total = 0;
bool good[maxN];
int frst[maxN];
void dfs3(int v, int p) {
    sum_on_path[v] += we[v];
    if (sz[v] >= 2 || p == -1) {
        good[v] = true;
    }
    for (int to : ed[v]) {
        if (to == p) continue;
        sum_on_path[to] += sum_on_path[v];
        frst[to] = frst[v];
        dfs3(to, v);
        good[v] |= good[to];
    }
}
void dfs4(int v, int p) {
    if (good[v]) frst[v] = v;
    for (int to : ed[v]) {
        if (to == p) continue;
        frst[to] = frst[v];
        dfs4(to, v);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    if (n == 1) {
        cout << w[1];
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, i}); g[b].push_back({a, i});
    }
    cin >> s;
    dfs(1, -1);
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cmp++;
            dfs2(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto to : g[i]) {
            if (br[to.second]) {
                ed[where[i]].push_back(where[to.first]);
            }
        }
    }
    int st = where[s];
    dfs3(st, -1);
    for (int i = 1; i <= cmp; i++) {
        if (good[i]) total += we[i];
    }
    dfs4(st, -1);
    ll best = 0;
    for (int i = 1; i <= cmp; i++) {
        if (!good[i]) {
            best = max(best, sum_on_path[i] - sum_on_path[frst[i]]);
        }
    }
    cout << total + best;
    return 0;
}