
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct node {
    int u, v, k, w1, wk, su, sv;
    node(int u, int v, int k, int w1, int wk, int su, int sv):
        u(u), v(v), k(k), w1(w1), wk(wk), su(su), sv(sv) {}
};

const int N = 3005;
int n, u, v;
vector<int> adj[N];
vector<node*> vec;
bool vis[N];
int d[N][N], sz[N][N], par[N][N];
ll dp[N][N];

bool cmp(const node *n1, const node *n2) {
    return n1->k < n2->k;
}
void dfs(int u, int x, int k) {
    vis[x] = true;
    sz[u][x] = 1;
    d[u][x] = k;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(u, y, k + 1);
            sz[u][x] += sz[u][y];
            par[u][y] = x;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        fill(vis, vis + n, false);
        dfs(i, i, 0);
    }
    for(int u = 0; u < n; u++) {
        for(int v = u + 1; v < n; v++) {
            vec.push_back(new node(u, v, d[u][v], par[v][u], par[u][v], sz[v][u], sz[u][v]));
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    ll ans = 0;
    for(node *x : vec) {
        ans = max(ans, dp[x->v][x->u] = dp[x->u][x->v] = max(dp[x->u][x->wk], dp[x->w1][x->v]) + x->su * x->sv);
    }
    cout << ans << endl;
}