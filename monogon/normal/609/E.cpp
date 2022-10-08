
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, m, u[N], v[N], dsu[N];
ll w[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

using edge = pair<ll, int>;
vector<edge> e;
ll ans = 0;
vector<edge> adj[N];
bool vis[N];
int tin[N], tout[N], par[N][20], t = 0;
ll mx[N][20];

void dfs(int x) {
    tin[x] = t++;
    vis[x] = true;
    for(auto &p : adj[x]) {
        ll we;
        int y;
        tie(we, y) = p;
        if(!vis[y]) {
            par[y][0] = x;
            mx[y][0] = we;
            dfs(y);
        }
    }
    tout[x] = t++;
}
bool anc(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int l = 19; l >= 0; l--) {
        if(!anc(par[x][l], y)) {
            x = par[x][l];
        }
    }
    return par[x][0];
}
ll getmx(int x, int c) {
    if(anc(x, c)) return 0;
    ll res = 0;
    for(int l = 19; l >= 0; l--) {
        if(!anc(par[x][l], c)) {
            res = max(res, mx[x][l]);
            x = par[x][l];
        }
    }
    return max(res, mx[x][0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu, dsu + N, -1);
    rep(i, 0, m) {
        cin >> u[i] >> v[i] >> w[i];
        e.emplace_back(w[i], i);
    }
    sort(all(e));
    for(auto &p : e) {
        ll we;
        int i;
        tie(we, i) = p;
        if(trace(u[i]) != trace(v[i])) {
            join(u[i], v[i]);
            ans += we;
            adj[u[i]].emplace_back(we, v[i]);
            adj[v[i]].emplace_back(we, u[i]);
        }
    }
    par[1][0] = 1;
    mx[1][0] = 0;
    dfs(1);
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
            mx[i][l] = max(mx[i][l - 1], mx[par[i][l - 1]][l - 1]);
        }
    }
    rep(i, 0, m) {
        int c = lca(u[i], v[i]);
        cout << ans + w[i] - max(getmx(u[i], c), getmx(v[i], c)) << '\n';
    }
}