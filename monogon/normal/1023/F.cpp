
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

// sort all edges
// competitor edge connects different simulated components, same of your components
// all of your edges on the intended path need to have that cost
// create overall tree
// write down these pairs of nodes
// min cost in subtree (range) that appears odd number of times
// join with parent, path-compression dsu until it reaches lca

struct dsu {
    vector<int> a;
    dsu(size_t n) {
        a.assign(n, -1);
    }
    size_t find(size_t x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    size_t size(size_t x) {
        return -a[find(x)];
    }
    bool join(size_t x, size_t y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    dsu D(n + 1), D2(n + 1);
    vector<vi> g(n + 1);
    rep(i, 0, k) {
        int u, v;
        cin >> u >> v;
        D.join(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<tuple<ll, int, int>> krus;
    rep(i, 0, m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        krus.push_back({w, u, v});
    }
    sort(all(krus));
    vector<tuple<ll, int, int>> Q;
    for(auto &pa : krus) {
        ll w; int u, v;
        tie(w, u, v) = pa;
        if(D2.find(u) != D2.find(v)) {
            if(D.find(u) == D.find(v)) {
                Q.push_back({w, u, v});
            }else {
                D2.join(u, v);
                D.join(u, v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
    vector<vi> par(n + 1, vi(20));
    vi tin(n + 1, -1), tout(n + 1);
    int ti = 0;
    function<void(int, int)> dfs = [&](int x, int p) {
        tin[x] = ti++;
        for(int y : g[x]) {
            if(y != p) {
                par[y][0] = x;
                dfs(y, x);
            }
        }
        tout[x] = ti++;
    };
    par[1][0] = 1;
    dfs(1, 1);
    rep(i, 1, n + 1) {
        if(par[i][0] == -1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    rep(l, 1, 20) rep(i, 1, n + 1) {
        par[i][l] = par[par[i][l - 1]][l - 1];
    }
    auto anc = [&](int x, int y) {
        return tin[x] <= tin[y] && tout[y] <= tout[x];
    };
    auto lca = [&](int x, int y) {
        if(anc(x, y)) return x;
        for(int l = 19; l >= 0; l--) {
            if(!anc(par[x][l], y)) x = par[x][l];
        }
        return par[x][0];
    };
    vi go(n + 1, -1);
    rep(i, 1, n + 1) go[i] = (D2.find(i) == D2.find(par[i][0]) ? par[i][0] : i);
    function<int(int)> trace = [&](int x) {
        return go[x] == x ? x : go[x] = trace(go[x]);
    };

    auto jump = [&](int x, int y) {
        int cnt = 0;
        while((x = trace(x)) != (y = trace(y))) {
            go[x] = par[x][0];
            cnt++;
        }
        return cnt;
    };
    ll ans = 0;
    for(auto &pa : Q) {
        ll w; int a, b;
        tie(w, a, b) = pa;
        int c = lca(a, b);
        ans += w * (jump(a, c) + jump(b, c));
    }
    rep(i, 1, n + 1) {
        if(trace(i) != trace(1)) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';
}