#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = 3e5 + 10;
ll c[maxN], w[maxN];
int x[maxN], y[maxN];
struct twoedge {
    //    ,   
    //0-,    (, )
    int n;
    int m;
    vector<vector<pair<int, int> > > g;
    vector<bool> used;
    vector<int> up;
    vector<int> h;
    vector<bool> bridges;

    void dfs(int v, int p, int id) {
        up[v] = h[v];
        used[v] = true;
        for (auto &it : g[v]) {
            if (used[it.first]) {
                if (id != it.second) {
                    up[v] = min(up[v], h[it.first]);
                }
            } else {
                h[it.first] = h[v] + 1;
                dfs(it.first, v, it.second);
                if (up[it.first] == h[it.first]) {
                    bridges[it.second] = true;
                }
                up[v] = min(up[v], up[it.first]);
            }
        }
    }

    vector<vector<int>> components;

    void sec_dfs(int v, vector<int> &f) {
        f.emplace_back(v);
        used[v] = true;
        for (auto &it : g[v]) {
            if (!used[it.first] && !bridges[it.second]) {
                sec_dfs(it.first, f);
            }
        }
    }

    twoedge(vector<vector<pair<int, int> > > &edge) {
        g = edge;
        n = g.size();
        m = -1;
        for (int i = 0; i < n; i++) {
            for (auto &it : g[i]) {
                m = max(m, it.second);
            }
        }
        m++;
        h = vector<int>(n, 0);
        up = vector<int>(n, 0);
        bridges = vector<bool>(m, false);
        used = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i, -1, -1);
            }
        }
        used.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                vector<int> cmps;
                sec_dfs(i, cmps);
                components.emplace_back(cmps);
            }
        }
    }
};
bool is[maxN];
int v[maxN];
ll cost[maxN];
int id[maxN];
bool spec[maxN];
int par[maxN];
vector < pair < int, int > > edges[maxN];
vector < pair < int, int > > gg[maxN];
ll dp[maxN][2];
void dfs_first(int v, int p) {
    dp[v][1] = cost[v];
    dp[v][0] = 0;
    for (auto& it : gg[v]) {
        if (it.first == p) continue;
        dfs_first(it.first, v);
    }
    for (auto& it : gg[v]) {
        if (it.first == p) continue;
        dp[v][0] += max(dp[it.first][0], dp[it.first][1]);
        dp[v][1] += max(0LL, dp[it.first][1] - it.second);
    }
}
ll up[maxN];
ll ans[maxN];
void dfs_second(int v, int p) {
    if (p == -1) up[v] = cost[v];
    ll total = 0;
    for (auto& it : gg[v]) {
        if (it.first == p) continue;
        total += max(0LL, dp[it.first][1] - it.second);
    }
    ans[v] = up[v] + total;
    for (auto& it : gg[v]) {
        if (it.first == p) continue;
        up[it.first] = max(cost[it.first], cost[it.first] + up[v] + total - it.second - max(0LL, dp[it.first][1] - it.second));
        dfs_second(it.first, v);
    }
}

int getPar(int i) {
    if (par[i] == i) return i;
    return par[i] = getPar(par[i]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        v[i]--;
        is[v[i]] = true;
    }
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) cin >> w[i];
    vector < vector < pair < int, int > > > g(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        g[x[i]].emplace_back(y[i], i);
        g[y[i]].emplace_back(x[i], i);
    }
    auto P = twoedge(g);
    int SZ = P.components.size();
    int c = 0;
    for (auto& it : P.components) {
        for (int v : it) {
            id[v] = c;
        }
        c++;
    }
    assert(c == SZ);
    int EDGES_ADD = 0;
    for (auto& it : P.components) {
        for (int v : it) {
            if (is[v]) {
                spec[id[v]] = true;
            }
            cost[id[v]] += ::c[v];
            for (auto& to : g[v]) {
                if (id[v] < id[to.first]) {
                    EDGES_ADD++;
                    edges[id[v]].emplace_back(id[to.first], to.second);
                    edges[id[to.first]].emplace_back(id[v], to.second);
                }
            }
        }
    }
    assert(EDGES_ADD == SZ - 1);
    vector < int > deg(SZ);
    queue < int > q;
    for (int i = 0; i < SZ; i++) par[i] = i;
    for (int i = 0; i < SZ; i++) {
        deg[i] = edges[i].size();
        if (!spec[i] && deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        deg[v]--;
        int who = -1;
        for (auto& it : edges[v]) {
            if (deg[it.first] > 0) {
                who = it.first;
                break;
            }
        }
        assert(who != -1);
        par[v] = who;
        cost[who] += cost[v];
        deg[who]--;
        if (deg[who] == 1 && !spec[who]) {
            q.push(who);
        }
    }
    //  par
    int root = -1;
    for (int i = 0; i < SZ; i++) {
        if (par[i] == i) {
            root = i;
        }
    }
    assert(root != -1);
    for (int i = 0; i < SZ; i++) {
        if (par[i] == i) {
            for (auto& it : edges[i]) {
                if (par[it.first] == it.first) {
                    gg[i].emplace_back(it.first, w[it.second]);
//                    cout << " EDGE " << i << "->" << it.first << " " << w[it.second] << endl;
                }
            }
        }
    }
    dfs_first(root, -1);
    dfs_second(root, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[getPar(id[i])] << " ";
    }
    return 0;
}