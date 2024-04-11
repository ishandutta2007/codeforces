
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// find max s-t flow, with uniform weight edges (at most 3 iterations)
// 0 -> answer is 0
// 3 -> impossible
// 1 edge -> find bridges that disconnect s from t,
// so compute bridges, compute a path from s to t, choose cheapest in the intersection.
// 1 edge is done in O(n + m) time

// 2 edges? how many edges are candidates?
// find a path from s->t, at least one edge must be removed
// try all removals, reduce to 1-edge algorithm.
// At most n candidates -> O(nm)

struct edge {
    int v, w, i;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<edge> e;
    vector<vi> g(n + 1);
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(sz(e));
        e.push_back({v, w, i});
        g[v].push_back(sz(e));
        e.push_back({u, w, i});
    }
    vi low(n + 1), dep(n + 1);
    vector<bool> bridge(m, false);
    vector<bool> vis1(n + 1, false);
    auto oneedge = [&](int ban) -> pii {
        fill(all(bridge), false);
        fill(all(vis1), false);
        auto dfs = [&](auto dfs, int x, int j) -> void {
            vis1[x] = true;
            low[x] = dep[x];
            for(int i : g[x]) {
                if(e[i].i == j || e[i].i == ban) continue;
                if(!vis1[e[i].v]) {
                    dep[e[i].v] = 1 + dep[x];
                    dfs(dfs, e[i].v, e[i].i);
                    if(low[e[i].v] == dep[e[i].v]) {
                        bridge[e[i].i] = true;
                    }
                    low[x] = min(low[x], low[e[i].v]);
                }else {
                    low[x] = min(low[x], dep[e[i].v]);
                }
            }
        };
        dep[s] = 0;
        dfs(dfs, s, -1);
        fill(all(vis1), false);
        int a = INT_MAX, idx = -1;
        auto dfs2 = [&](auto dfs2, int x) -> bool {
            vis1[x] = true;
            if(x == t) return true;
            bool reach = false;
            for(int i : g[x]) {
                if(e[i].i == ban) continue;
                if(!vis1[e[i].v] && dfs2(dfs2, e[i].v)) {
                    reach = true;
                    if(bridge[e[i].i] && e[i].w < a) {
                        a = e[i].w;
                        idx = e[i].i;
                    }
                }
            }
            return reach;
        };
        dfs2(dfs2, s);
        return {a, idx};
    };

    int ans = INT_MAX;
    vi best;
    pii pa = oneedge(-1);
    if(pa.first != INT_MAX) {
        ans = pa.first;
        best = {pa.second};
    }

    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto dfs, int x) -> bool {
        vis[x] = true;
        if(x == t) return true;
        bool reach = false;
        for(int i : g[x]) {
            if(!vis[e[i].v] && dfs(dfs, e[i].v)) {
                reach = true;
                pii pa = oneedge(e[i].i);
                if(pa.first != INT_MAX && pa.first + e[i].w < ans) {
                    ans = pa.first + e[i].w;
                    best = {e[i].i, pa.second};
                }
            }
        }
        return reach;
    };
    if(!dfs(dfs, s)) {
        ans = 0;
        best = {};
    }

    if(ans == INT_MAX) {
        cout << -1 << '\n';
    }else {
        cout << ans << '\n' << sz(best) << '\n';
        for(int x : best) cout << x + 1 << ' ';
        cout << '\n';
    }
}