#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

class Tree {
public:
    int n, log, root;
    vector<vector<int>> G, jump;
    vector<int> parent, depth, sz, tin, tout;

private:
    void dfs_depth(int v, int pr) {
        for (auto u : G[v]) {
            if (u == pr)
                continue;
            depth[u] = depth[v] + 1;
            dfs_depth(u, v);
        }
    }

    void dfs_sz(int v, int pr) {
        sz[v] = 1;
        for (auto u : G[v]) {
            if (u == pr)
                continue;
            dfs_sz(u, v);
            sz[v] += sz[u];
        }
    }

    void dfs_parent(int v, int pr) {
        parent[v] = pr;
        for (auto u : G[v])
            if (u != pr)
                dfs_parent(u, v);
    }

    void dfs_time(int v, int pr, int &timer) {
        tin[v] = timer++;
        for (auto u : G[v])
            if (u != pr)
                dfs_time(u, v, timer);
        tout[v] = timer++;
    }

    void dfs_all(int v, int pr, int &timer) {
        parent[v] = pr;
        sz[v] = 1;
        tin[v] = timer++;
        jump[v][0] = pr;
        for (int i = 1; i < log; i++)
            jump[v][i] = jump[jump[v][i - 1]][i - 1];
        for (auto u : G[v]) {
            if (u == pr)
                continue;
            depth[u] = depth[v] + 1;
            dfs_all(u, v, timer);
            sz[v] += sz[u];
        }
        tout[v] = timer++;
    }
    
public:
    Tree() : n(0), log(0), root(0) {}

    void resize(int n_) {
        n = n_, log = 0;
        while ((1 << log) <= n)
            log++;
        G.resize(n);
    }

    void clear() {
        n = log = root = 0;
        G.clear();
        parent.clear();
        depth.clear();
        sz.clear();
        tin.clear();
        tout.clear();
        jump.clear();
    }

    void add_edge(int v, int u) {
        G[v].push_back(u);
        G[u].push_back(v);
    }

    void build_depth() {
        depth = vector<int>(n, 0);
        dfs_depth(root, root);
    }

    void build_sz() {
        sz = vector<int>(n, 0);
        dfs_sz(root, root);
    }

    void build_parent() {
        parent = vector<int>(n, -1);
        dfs_parent(root, root);
    }

    void build_time() {
        tin = tout = vector<int>(n);
        int timer = 0;
        dfs_time(root, root, timer);
    }

    void build_all() {
        depth = vector<int>(n, 0);
        sz = vector<int>(n, 0);
        parent = vector<int>(n, -1);
        tin = tout = vector<int>(n, 0);
        jump = vector<vector<int>>(n, vector<int>(log));
        int timer = 0;
        dfs_all(root, root, timer);
    }

    bool is_parent(int v, int u) {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }

    int lca(int v, int u) {
        if (is_parent(v, u))
            return v;
        if (is_parent(u, v))
            return u;
        for (int i = log - 1; i >= 0; i--)
            if (!is_parent(jump[v][i], u))
                v = jump[v][i];
        return parent[v];
    }

    int la(int v, int d) {
        for (int i = 0; i < log; i++)
            if (((d >> i) & 1))
                v = jump[v][i];
        return v;
    }

    int dist(int v, int u) {
        return depth[v] + depth[u] - 2 * depth[lca(v, u)];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    Tree tr;
    tr.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        tr.add_edge(v, u);
    }
    tr.build_depth();
    tr.build_time();
    tr.build_parent();
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> cur(k);
        for (int &i : cur)
            cin >> i, i--;
        for (int i = 1; i < k; i++)
            if (tr.depth[cur[i]] > tr.depth[cur[0]])
                swap(cur[0], cur[i]);
        bool ok = true;
        for (int i = 1; i < k; i++)
            ok &= tr.is_parent(cur[i], cur[0]) || tr.is_parent(tr.parent[cur[i]], cur[0]);
        cout << (ok ? "YES\n" : "NO\n");
    }
}