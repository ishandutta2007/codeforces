#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

int n, m, level[N], parent[N], up[18][N], depth[N], closest_red[N];
vector<int> g[N];

int dfs(int v, int size, int& center, int p = -1) {
    int sum = 1;
    for (auto u : g[v])
        if (u != p && level[u] == -1) {
            sum += dfs(u, size, center, v);
        }
    if (center == -1 && (2 * sum >= size || p == -1))
        center = v;
    return sum;
}

void build(int v, int size, int depth, int last) {
    int center = -1;
    dfs(v, size, center);
    level[center] = depth;
    parent[center] = last;
    for (auto u : g[center])
        if (level[u] == -1)
            build(u, size / 2, depth + 1, center);
}

void dfs_lca(int v, int p) {
    up[0][v] = p;
    depth[v] = depth[p] + 1;
    for (auto u : g[v])
        if (!up[0][u])
            dfs_lca(u, v);
}

void build_lca() {
    for (int j = 1; j < 18; j++)
        for (int i = 1; i <= n; i++)
            up[j][i] = up[j - 1][up[j - 1][i]];
}

int get_dist(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int ans = 0;
    for (int j = 17; j >= 0; j--)
        if (depth[u] - (1 << j) >= depth[v]) {
            ans += (1 << j);
            u = up[j][u];
        }
    if (u == v)
        return ans;
    for (int j = 17; j >= 0; j--)
        if (up[j][u] != up[j][v]) {
            ans += 2 * (1 << j);
            u = up[j][u];
            v = up[j][v];
        }
    return ans + 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        level[i] = -1;
    build(1, n, 0, -1);
    dfs_lca(1, 1);
    build_lca();

    for (int i = 1; i <= n; i++)
        closest_red[i] = get_dist(i, 1);
    while (m--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            int center = v;
            while (center != -1) {
                closest_red[center] = min(closest_red[center], get_dist(v, center));
                center = parent[center];
            }
        } else {
            int center = v;
            int ans = 1e9;
            while (center != -1) {
                ans = min(ans, get_dist(v, center) + closest_red[center]);
                center = parent[center];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}