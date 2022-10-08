
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

// for each node in tree, compute farthest leaf
// minimum of all farthest leaf values is the answer

const int N = 2e5 + 5;
int n, col[N], dsu[N], u[N], v[N], depth[N], dp[N];
vi adj[N], ve[N];
bool vis[N];
int diam = 1e9;

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            ve[x].push_back(1 + depth[y]);
        }
    }
    sort(ve[x].rbegin(), ve[x].rend());
    depth[x] = (ve[x].empty() ? 0 : ve[x][0]);
}

void dfs2(int x) {
    vis[x] = true;
    sort(ve[x].rbegin(), ve[x].rend());
    diam = min(diam, ve[x].empty() ? 0 : ve[x][0]);
    for(int y : adj[x]) {
        if(!vis[y]) {
            int d = 0;
            if(!ve[x].empty() && ve[x][0] != 1 + depth[y]) {
                d = ve[x][0];
            }else if(sz(ve[x]) >= 2 && ve[x][0] == 1 + depth[y]) {
                d = ve[x][1];
            }
            ve[y].push_back(1 + d);
            dfs2(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> col[i];
    fill(dsu + 1, dsu + n + 1, -1);
    rep(i, 0, n - 1) {
        cin >> u[i] >> v[i];
        if(col[u[i]] == col[v[i]]) {
            join(u[i], v[i]);
        }
    }
    rep(i, 0, n - 1) {
        if(col[u[i]] != col[v[i]]) {
            u[i] = trace(u[i]);
            v[i] = trace(v[i]);
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }
    }
    rep(i, 1, n + 1) {
        if(trace(i) == i) {
            dfs(i);
            fill(vis, vis + n + 1, false);
            dfs2(i);
            break;
        }
    }
    cout << diam << endl;
}