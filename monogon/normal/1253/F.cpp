
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

struct dsu {
    vi a;
    vector<ll> ans;
    vector<vector<pii>> qu;
    dsu(int n, int q) {
        a.assign(n, -1);
        ans.assign(q, -1);
        qu.resize(n);
    }
    int trace(int x) {
        return a[x] < 0 ? x : a[x] = trace(a[x]);
    }
    void join(int x, int y, ll w) {
        if((x = trace(x)) == (y = trace(y))) return;
        if(a[x] > a[y]) swap(x, y);

        for(auto &pa : qu[y]) {
            int i, b;
            tie(i, b) = pa;
            if(trace(b) == x) {
                ans[i] = w;
            }else {
                qu[x].push_back(pa);
            }
        }
        
        a[x] += a[y];
        a[y] = x;
    }
    void query(int i, int a, int b) {
        qu[a].push_back({i, b});
        qu[b].push_back({i, a});
    }
};

using edge = tuple<ll, int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<pair<ll, int>>> g(n + 1);
    vector<edge> e;
    rep(i, 0, m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
        e.push_back({w, u, v});
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    vi par(n + 1);
    vector<bool> vis(n + 1);
    minpq<pair<ll, int>> Q;
    rep(i, 1, k + 1) {
        dist[i] = 0;
        par[i] = i;
        Q.push({0, i});
    }

    while(!Q.empty()) {
        ll d; int x;
        tie(d, x) = Q.top(); Q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(auto &ed : g[x]) {
            ll w; int y;
            tie(w, y) = ed;
            if(d + w < dist[y]) {
                dist[y] = d + w;
                par[y] = par[x];
                Q.push({dist[y], y});
            }
        }
    }

    vector<edge> e2;
    for(auto &ed : e) {
        ll w; int u, v;
        tie(w, u, v) = ed;
        e2.push_back({w + dist[u] + dist[v], par[u], par[v]});
    }
    sort(all(e2));
    dsu D(k + 1, q);
    
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        D.query(i, a, b);
    }

    for(auto &ed : e2) {
        ll w; int u, v;
        tie(w, u, v) = ed;
        D.join(u, v, w);
    }

    rep(i, 0, q) {
        cout << D.ans[i] << '\n';
    }
}