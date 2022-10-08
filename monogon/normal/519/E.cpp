
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// find midpoint of shortest path between them
// if odd distance, answer 0
// if even distance, we have a midpoint that we can find

const int N = 1e5 + 5;
int n, u, v, m, a, b, dp[N], depth[N], par[N][20], tin[N], tout[N];
vi adj[N];
bool vis[N];
int t = 0;

void dfs(int x) {
    vis[x] = true;
    dp[x] = 1;
    tin[x] = t++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            par[y][0] = x;
            dfs(y);
            dp[x] += dp[y];
        }
    }
    tout[x] = t++;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}
int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int i = 19; i >= 0; i--) {
        if(!anc(par[x][i], y)) x = par[x][i];
    }
    return par[x][0];
}
int subtree(int x, int c) {
    if(x == c) return 0;
    for(int i = 19; i >= 0; i--) {
        if(!anc(par[x][i], c)) x = par[x][i];
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1][0] = 1;
    dfs(1);
    rep(k, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }
    cin >> m;
    while(m--) {
        cin >> a >> b;
        int c = lca(a, b);
        int dist = depth[a] + depth[b] - 2 * depth[c];
        if(dist & 1) {
            cout << "0\n";
        }else {
            if(depth[a] > depth[b]) swap(a, b);
            int d = depth[c] + (depth[b] - depth[a]) / 2;
            int x = b;
            for(int i = 19; i >= 0; i--) {
                if(depth[par[x][i]] >= d) x = par[x][i];
            }
            assert(depth[x] == d);
            if(x == c) {
                cout << n - subtree(a, c) - subtree(b, c) << '\n';
            }else {
                cout << dp[x] - subtree(b, x) << '\n';
            }
        }
    }
}