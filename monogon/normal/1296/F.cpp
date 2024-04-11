
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005;
int n, u[N], v[N], m, a[N], b[N], g[N], f[N];
vector<int> adj[N];
int par[N];

void dfs(int x, int p) {
    par[x] = p;
    for(int y : adj[x]) {
        if(par[y] == 0) {
            dfs(y, x);
        }
    }
}
int lca(int x, int y) {
    vector<int> vx;
    vector<int> vy;
    while(par[x] != x) {
        vx.push_back(x);
        x = par[x];
    }
    while(par[y] != y) {
        vy.push_back(y);
        y = par[y];
    }
    int c = 1;
    while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
        c = vx.back();
        vx.pop_back();
        vy.pop_back();
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(f, f + N, 1);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> g[i];
    }
    dfs(1, 1);
    for(int i = 0; i < m; i++) {
        int x = a[i], y = b[i];
        int c = lca(x, y);
        while(x != c) {
            f[x] = max(f[x], g[i]);
            x = par[x];
        }
        while(y != c) {
            f[y] = max(f[y], g[i]);
            y = par[y];
        }
    }
    for(int i = 0; i < m; i++) {
        int x = a[i], y = b[i];
        int c = lca(x, y);
        int m = 1e9;
        while(x != c) {
            m = min(m, f[x]);
            x = par[x];
        }
        while(y != c) {
            m = min(m, f[y]);
            y = par[y];
        }
        if(m != g[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        if(u[i] == par[v[i]]) {
            cout << f[v[i]] << " ";
        }else {
            cout << f[u[i]] << " ";
        }
    }
    cout << endl;
}