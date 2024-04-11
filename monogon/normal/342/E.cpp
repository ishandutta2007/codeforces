
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int n, m;
vi adj[N];
int dp[N], cpar[N], tin[N], depth[N], par[N][20], tout[N], ti = 0, red[N];
bool vis[N];

void dfs_lca(int x, int p) {
    tin[x] = ti++;
    par[x][0] = p;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            red[y] = red[x] + 1;
            dfs_lca(y, x);
        }
    }
    tout[x] = ti++;
}

void dfs(int x, int p) {
    dp[x] = 1;
    for(int y : adj[x]) {
        if(!vis[y] && y != p) {
            dfs(y, x);
            dp[x] += dp[y];
        }
    }
}

int find_centroid(int x, int p, int s) {
    for(int y : adj[x]) {
        if(!vis[y] && y != p && dp[y] > s / 2) {
            return find_centroid(y, x, s);
        }
    }
    return x;
}

void init_centroid(int x, int p) {
    dfs(x, p);
    int c = find_centroid(x, p, dp[x]);
    vis[c] = true;
    cpar[c] = p;
    for(int y : adj[c]) {
        if(!vis[y] && y != p) {
            init_centroid(y, c);
        }
    }
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int l = 19; l >= 0; l--) {
        if(!anc(par[x][l], y)) x = par[x][l];
    }
    return par[x][0];
}

int dist(int x, int y) {
    int c = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_lca(1, 1);
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
    init_centroid(1, -1);
    while(m--) {
        int ty, x;
        cin >> ty >> x;
        if(ty == 1) {
            // paint red
            int v = x;
            while(x != -1) {
                red[x] = min(red[x], dist(x, v));
                x = cpar[x];
            }
        }else {
            // print answer
            int v = x;
            int ans = red[x];
            while(x != -1) {
                ans = min(ans, dist(x, v) + red[x]);
                x = cpar[x];
            }
            cout << ans << '\n';
        }
    }
}