
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, k, u, v, p[N], in[N], out[N];
vector<int> adj[N];
bool vis[N];
int t = 0;

void dfs(int x) {
    vis[x] = true;
    in[x] = t++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            p[y] = x;
            dfs(y);
        }
    }
    out[x] = t++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    p[1] = 1;
    dfs(1);
    while(m--) {
        cin >> k;
        int l = -1, r = 2 * N;
        while(k--) {
            cin >> v;
            v = p[v];
            l = max(l, in[v]);
            r = min(r, out[v]);
        }
        cout << (l <= r ? "YES" : "NO") << "\n";
    }
}