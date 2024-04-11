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

using edge = tuple<ll, int, int>;

struct dsu {
    vi a;
    dsu(int n) {
        a.assign(n, -1);
    }
    int trace(int x) {
        return a[x] < 0 ? x : a[x] = trace(a[x]);
    }
    void join(int x, int y) {
        if((x = trace(x)) == (y = trace(y))) return;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll x = 0;
    vector<edge> e;
    vector<vi> g(n + 1);
    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        x ^= w;
        e.push_back({w, u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int idx = 1;
    rep(i, 1, n + 1) if(sz(g[i]) < sz(g[idx])) idx = i;
    dsu D(n + 1);
    set<int> se;
    rep(i, 1, n + 1) se.insert(i);
    se.erase(idx);
    for(int v : g[idx]) {
        se.erase(v);
    }
    for(int v : se) {
        D.join(idx, v);
    }
    vi ve;
    rep(i, 1, n + 1) {
        if(D.trace(i) == i) ve.push_back(i);
    }
    int k = sz(ve);
    map<pii, int> smh;
    for(auto &ed : e) {
        ll w; int u, v;
        tie(w, u, v) = ed;
        u = D.trace(u);
        v = D.trace(v);
        smh[{u, v}]++;
        smh[{v, u}]++;
    }
    vi sizes(k);
    rep(i, 0, k) sizes[i] = -D.a[ve[i]];
    rep(i, 0, k) rep(j, i + 1, k) {
        if(smh[{ve[i], ve[j]}] < 1LL * sizes[i] * sizes[j]) {
            D.join(ve[i], ve[j]);
        }
    }
    ll cost = 0;
    map<int, int> ma;
    for(auto &ed : e) {
        ll w; int u, v;
        tie(w, u, v) = ed;
        u = D.trace(u);
        v = D.trace(v);
        if(u == v) {
            ma[u]++;
        }
    }
    bool f = false;
    rep(i, 1, n + 1) {
        if(D.trace(i) == i) {
            int si = -D.a[i];
            ll c = 1LL * si * (si - 1) / 2 - ma[i];
            if(c != si - 1) f = true;
        }
    }
    sort(all(e));
    dsu D2(n + 1);
    for(auto &ed : e) {
        ll w; int u, v;
        tie(w, u, v) = ed;
        int u2 = D.trace(u);
        int v2 = D.trace(v);
        if(u2 != v2) {
            cost += w;
            D.join(u, v);
            D2.join(u, v);
        }
    }
    for(auto &ed : e) {
        ll w; int u, v;
        tie(w, u, v) = ed;
        u = D2.trace(u);
        v = D2.trace(v);
        if(u != v) {
            x = min(x, w);
        }
    }
    cout << cost + (f ? 0 : x) << '\n';
}