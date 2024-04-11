/*
    author:  Maksim1744
    created: 11.04.2021 02:29:47
*/

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<int> high;
    vector<int> lvl;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        lvl.resize(n);
        iota(p.begin(), p.end(), 0);
        high = p;
        rk.assign(n, 1);
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        if (lvl[high[u]] < lvl[high[v]])
            high[v] = high[u];
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

vector<int> lca_ind;
vector<vector<int>> lca_sparse;
vector<int> lca_p2;
vector<int> lca_depth;
void build_lca_sparse(vector<vector<pair<int, int>>>& g, int root = 0) {
    int n = g.size();
    vector<int> euler;
    lca_ind.resize(n);
    lca_depth.assign(n, -1);
    function<void(int, int)> dfs = [&](int v, int depth) {
        lca_ind[v] = euler.size();
        euler.pb(v);
        lca_depth[v] = depth;
        for (auto [k, w] : g[v]) {
            if (lca_depth[k] == -1) {
                dfs(k, depth + 1);
                euler.pb(v);
            }
        }
    };
    dfs(root, 0);
    int m = euler.size();
    int log = 1;
    while ((1 << log) < m)
        ++log;
    lca_sparse.resize(log);
    lca_sparse[0].resize(m);
    lca_p2.resize(m + 1);
    int pp2 = 0;
    for (int i = 1; i < lca_p2.size(); ++i) {
        if (1 << (pp2 + 1) <= i)
            ++pp2;
        lca_p2[i] = pp2;
    }
    lca_p2[0] = 0;
    for (int i = 0; i < m; ++i)
        lca_sparse[0][i] = euler[i];
    for (int i = 1; i < log; ++i) {
        lca_sparse[i].assign(m, 0);
        for (int j = 0; j < m - (1 << (i - 1)); ++j) {
            int v1 = lca_sparse[i - 1][j], v2 = lca_sparse[i - 1][j + (1 << (i - 1))];
            if (lca_depth[v1] < lca_depth[v2])
                lca_sparse[i][j] = v1;
            else
                lca_sparse[i][j] = v2;
        }
    }
}

int get_lca(int u, int v) {
    if (u == v)
        return u;
    u = lca_ind[u];
    v = lca_ind[v];
    if (u > v)
        swap(u, v);
    int v1 = lca_sparse[lca_p2[v - u + 1]][u], v2 = lca_sparse[lca_p2[v - u + 1]][v - (1 << lca_p2[v - u + 1]) + 1];
    if (lca_depth[v1] < lca_depth[v2])
        return v1;
    else
        return v2;
}

int dist(int u, int v) {
    return lca_depth[u] + lca_depth[v] - 2 * lca_depth[get_lca(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].second >> e[i].first;
        --e[i].second.first;
        --e[i].second.second;
    }
    vector<vector<pair<int, int>>> tree(n);
    {
        auto e2 = e;
        DSU d(n);
        sort(e.begin(), e.end());
        for (auto [w, uv] : e) {
            auto [u, v] = uv;
            if (d.check(u, v)) continue;
            d.un(u, v);
            tree[u].eb(v, w);
            tree[v].eb(u, w);
        }
        e = e2;
    }

    vector<vector<pair<int, ll>>> up(20, vector<pair<int, ll>>(n, {-1, 0}));
    vector<int> par(n, -1);
    vector<bool> u(n, false);
    vector<int> lvl(n, 0);
    function<void(int)> dfs1 = [&](int v) {
        u[v] = true;
        for (auto [k, w] : tree[v]) {
            if (!u[k]) {
                par[k] = v;
                up[0][k] = {v, w};
                lvl[k] = lvl[v] + 1;
                dfs1(k);
            }
        }
    };
    dfs1(0);

    for (int i = 1; i < up.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[i - 1][j].first != -1) {
                up[i][j] = {up[i - 1][up[i - 1][j].first].first, max(up[i - 1][j].second, up[i - 1][up[i - 1][j].first].second)};
            }
        }
    }

    auto in_tree = [&](pair<int, int> p) {
        return par[p.first] == p.second || par[p.second] == p.first;
    };

    auto go_up1 = [&](int v, int k) {
        ll val = 0;
        for (int i = 0; i < up.size(); ++i) {
            if ((k >> i) & 1) {
                val = max(val, up[i][v].second);
                v = up[i][v].first;
            }
        }
        return mp(v, val);
    };

    build_lca_sparse(tree, 0);

    // solve p3
    map<pair<int, int>, int> mem;
    {
        auto e2 = e;

        DSU d(n);
        d.lvl = lvl;

        sort(e.begin(), e.end());

        auto go_up2 = [&](int v, int k, int w) {
            while (lvl[v] > lvl[k]) {
                v = d.high[d.par(v)];
                if (lvl[v] <= lvl[k]) break;
                d.un(v, par[v]);
                mem[mp(min(v, par[v]), max(v, par[v]))] = w;
            }
        };

        for (auto [w, uv] : e) {
            if (in_tree(uv)) continue;
            auto [u, v] = uv;
            int k = get_lca(u, v);
            go_up2(u, k, w);
            go_up2(v, k, w);
        }

        e = e2;
    }

    for (auto [w, uv] : e) {
        auto [u, v] = uv;
        if (in_tree(uv)) {
            if (!mem.count(mp(min(u, v), max(u, v))))
                cout << 1000000000 << '\n';
            else
                cout << mem[mp(min(u, v), max(u, v))] << '\n';
        } else {
            int t = get_lca(u, v);
            auto p1 = go_up1(u, lvl[u] - lvl[t]);
            auto p2 = go_up1(v, lvl[v] - lvl[t]);
            ll val = max(p1.second, p2.second);
            cout << val << '\n';
        }
    }

    return 0;
}