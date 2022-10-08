
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// for G, an edge chosen at most once. Delete edges such that there
// are an even number of vertices on both sides

const int N = 2e5 + 5;
int q, k, u, v;
ll t, G, B;
bool vis[N];
int sz[N];
vector<pair<int, ll>> adj[N];

void dfs(int x) {
    vis[x] = true;
    sz[x] = 1;
    for(auto p : adj[x]) {
        auto [y, t] = p;
        if(!vis[y]) {
            dfs(y);
            if(sz[y] % 2 == 1) G += t;
            B += t * min(sz[y], 2 * k - sz[y]);
            sz[x] += sz[y];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> k;
        for(int i = 0; i < 2 * k; i++) adj[i].clear();
        for(int i = 0; i < 2 * k - 1; i++) {
            cin >> u >> v >> t;
            u--; v--;
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }
        fill(vis, vis + 2 * k, 0);
        G = B = 0;
        dfs(0);
        cout << G << " " << B << endl;
    }
}