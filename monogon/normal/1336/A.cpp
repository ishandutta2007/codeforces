
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, k, u, v, depth[N], sz[N];
vector<int> adj[N];
bool vis[N], ind[N];

int dfs(int x) {
    vis[x] = true;
    sz[x] = 0;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            sz[x] += dfs(y);
        }
    }
    return sz[x] + 1;
}
ll dfs2(int x, ll len) {
    vis[x] = true;
    ll ans = (ind[x] ? len : 0);
    for(int y : adj[x]) {
        if(!vis[y]) {
            ans += dfs2(y, len + !ind[x]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    vector<pair<int, int>> ve;
    for(int i = 1; i <= n; i++) {
        ve.emplace_back(sz[i] - depth[i], i);
    }
    sort(ve.begin(), ve.end());
    for(int i = 0; i < k; i++) {
        ind[ve[i].second] = true;
    }
    fill(vis, vis + N, false);
    cout << dfs2(1, 0) << endl;
}