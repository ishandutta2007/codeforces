#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a, b, da, db, depth[N];
vector<int> adj[N];
int diam = 0;

int dfs(int x, int p) {
    int len = 0;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            int cur = 1 + dfs(y, x);
            diam = max(diam, cur + len);
            len = max(len, cur);
        }
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> a >> b >> da >> db;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        diam = 0;
        depth[a] = 0;
        dfs(a, -1);
        cout << (2 * da >= min(diam, db) || depth[b] <= da ? "Alice" : "Bob") << '\n';
    }
}