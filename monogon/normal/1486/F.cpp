
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

struct node {
    set<int> s;
    int gone = 0;
    bool insert(int x) {
        if(s.count(-x)) {
            s.erase(-x);
            gone++;
            return true;
        }else {
            s.insert(x);
            return false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi tin(n + 1), tout(n + 1);
    vector<vi> par(n + 1, vi(20, 0));
    int ti = 0;
    function<void(int, int)> dfs = [&](int x, int p) {
        par[x][0] = p;
        tin[x] = ti++;
        for(int y : g[x]) {
            if(y != p) {
                dfs(y, x);
            }
        }
        tout[x] = ti++;
    };
    dfs(1, 1);
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
    int m;
    cin >> m;
    ll ans = 1LL * m * (m - 1) / 2;
    vector<node> s(n + 1);
    vi pos(m + 1), pos2(m + 1);
    rep(i, 1, m + 1) {
        int u, v;
        cin >> u >> v;
        if(tout[u] > tout[v]) swap(u, v);
        pos[i] = u;
        pos2[i] = v;
        s[u].insert(i);
        s[v].insert(-i);
    }
    vi c(n + 1, 0), d(n + 1, 0), cursed(n + 1, 0);
    auto anc = [&](int x, int y) {
        return tin[x] <= tin[y] && tout[y] <= tout[x];
    };
    ll type1 = 0, type2 = 0, type3 = 0, type4 = 0, type5 = 0;
    function<void(int, int)> dfs2 = [&](int x, int p) {
        int e = 0;
        int removed = s[x].gone;
        ll sum = 0;
        auto rem = [&](int u) {
            u = (u > 0 ? pos[u] : pos2[-u]);
            e++;
            if(u == x) return -e;
            assert(!anc(u, x));
            for(int l = 19; l >= 0; l--) {
                if(!anc(par[u][l], x)) u = par[u][l];
            }
            d[u]++;
            return u;
        };
        multiset<pii> ve;
        auto ins = [&](int u) {
            int a = rem(u);
            int b = rem(-u);
            if(a < b) swap(a, b);
            ve.insert({a, b});
            removed++;
        };
        for(int y : g[x]) {
            if(y != p) {
                dfs2(y, x);
                sum += cursed[y];
                c[y] = sz(s[y].s);
                if(sz(s[x].s) < sz(s[y].s)) {
                    for(int z : s[x].s) {
                        if(s[y].insert(z)) ins(z);
                    }
                    s[x].gone += s[y].gone;
                    s[x].s.swap(s[y].s);
                }else {
                    s[x].gone += s[y].gone;
                    for(int z : s[y].s) {
                        if(s[x].insert(z)) ins(z);
                    }
                }
            }
        }
        for(int y : g[x]) {
            if(y != p) {
                type1 += 1LL * d[y] * (c[y] - d[y]);
                type2 += 1LL * d[y] * (d[y] - 1) / 2;
                type5 += 1LL * cursed[y] * (sum - cursed[y]);
            }
        }
        while(!ve.empty()) {
            int s1 = sz(ve);
            ve.erase(*ve.begin());
            int s2 = sz(ve);
            int dif = s1 - s2;
            type3 += 1LL * dif * (dif - 1) / 2;
        }
        ll val = 1LL * removed * (m - s[x].gone - sz(s[x].s));
        type4 += val;
        cursed[x] = s[x].gone;
    };
    dfs2(1, 1);
    // cout << type1 << ' ' << type2 << ' ' << type3 << ' ' << type4 << ' ' << type5 << '\n';
    cout << ans - type1 - type2 + type3 - type4 + type5 / 2 << '\n';
}