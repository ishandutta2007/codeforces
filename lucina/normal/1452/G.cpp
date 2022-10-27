#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int d[nax];
vector <int> g[nax];
int ans[nax];
bool out[nax];
int sz[nax];
vector <int> in_tree;
int mx[nax];
inline void upd_max(int &a, int b) {a = max(a, b);}
void dfs_sz(int v, int parent) {
    sz[v] = 1;
    in_tree.push_back(v);
    for (int to : g[v]) {
        if (to != parent) {
            dfs_sz(to, v);
            sz[v] += sz[to];
        }
    }
}
int find_centroid(int tree_sz) {
    for (int node : in_tree) {
        bool ok = true;
        for (int to : g[node]) {
            if (sz[to] < sz[node]) ok &= sz[to] * 2 <= tree_sz;
            else ok &= (tree_sz - sz[node]) * 2 <=  tree_sz;
        }
        if (ok) return node;
    }
    return -1;
}
int h[nax]; // level of node in centroid tree
int mx_sz;


void dfs(int node, int parent) {
    if (h[node] < d[node]) {
        upd_max(mx[min(d[node] - h[node] - 1, mx_sz)], d[node]);
    }
    for (int to : g[node]) {
        if (to == parent) continue;
        h[to] = h[node] + 1;
        dfs(to, node);
    }
}

/**
    for each centroid, find the answer
    that contribute passed through this centroid.
    to update all nodes with distance < d[x]
    contribute value d[x] - dist_to_centroid(x) - 1, update this in array
    this can further contribute to other nodes with distance from centroid <= d[x] - dist_to_centroid(x) - 1
    The only thing left is to take maximum suffix.
*/
void solve_centroid(int node) {
    in_tree.clear();
    dfs_sz(node, 0);
    int cen = find_centroid(sz[node]);
    mx_sz = sz[node];
    for (int i = 0 ; i <= mx_sz; ++ i) mx[i] = 0;
    h[cen] = 0;
    dfs(cen, 0);
    for (int i = mx_sz ; i >= 1 ; -- i) upd_max(mx[i - 1], mx[i]);

    for (int x : in_tree) {
        upd_max(ans[x], mx[h[x]]);
    }

    for (int to : g[cen]) {
        g[to].erase(find(g[to].begin(), g[to].end(), cen));
        solve_centroid(to);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    {
        int k;
        queue <int> q;
        cin >> k;
        fill(d + 1, d + 1 + n, nax);
        while (k --) {
            int x;
            cin >> x;
            q.push(x);
            d[x] = 0;
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int to : g[x]) {
                if (d[x] + 1 < d[to]) {
                    d[to] = d[x] + 1;
                    q.push(to);
                }
            }
        }
    }


    solve_centroid(1);
    for (int i = 1 ; i <= n ; ++ i) {
        if (d[i] == 0) cout << "0 ";
        else cout << ans[i] << ' ';
    }
}