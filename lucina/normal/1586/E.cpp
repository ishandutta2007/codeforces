#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m, q;
int par[nax];
int h[nax];
int a[nax], b[nax];
vector <int> g[nax];
void dfs(int node, int parent) {
    par[node] = parent;
    for (int to : g[node]) {
        if (par[to] != -1) continue;
        h[to] = h[node] + 1;
        dfs(to, node);
    }
}

void print_path(int a, int b) {
    static vector <int> path_a;
    static vector <int> path_b;
    path_a.clear(); path_b.clear();
    while (h[a] != h[b]) {
        if (h[a] > h[b]) path_a.push_back(a), a = par[a];
        else path_b.push_back(b), b = par[b];
    }
    while (a != b) {
        path_a.push_back(a);
        path_b.push_back(b);
        a = par[a];
        b = par[b];
    }
    path_a.push_back(a);
    cout << path_a.size() + path_b.size() << '\n';
    for (auto x : path_a) cout << x << ' ';
    reverse(path_b.begin(), path_b.end());
    for (auto x : path_b) cout << x << ' ';
    cout << '\n';
}
int sum[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    while (m --) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(par, -1, sizeof(par));
    dfs(1, 0);
    cin >> q;

    for (int i = 1 ; i <= q ; ++ i) {
        cin >> a[i] >> b[i];
        sum[a[i]] ^= 1;
        sum[b[i]] ^= 1;
    }
    if (int x = accumulate(sum + 1, sum + 1 + n, 0); x) {
        cout << "NO\n" << x / 2 << '\n';
    } else {
        cout << "YES\n";
        for (int i = 1 ; i <= q ; ++ i)
            print_path(a[i], b[i]);
    }
}
/**
    for tree, if some nodes have odd degree-> false
    otherwise, every edges have even degree
    and the query equivalent to xor from root. So it's ok to update path in spanning tree.
*/