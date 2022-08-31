/*
    author:  Maksim1744
    created: 16.04.2021 18:03:32
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
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
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
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
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

struct DSU2 {
    vector<int> rk;
    vector<int> p;
    vector<int> high;
    vector<int> lvl;
    int n;
 
    DSU2(int n = 1) : n(n) {
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
    vector<vector<int>> g(n);
    vector<pair<int, pair<int, int>>> e(m);

    set<pair<int, int>> has;
    int x = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        x ^= w;
        g[u].eb(v);
        g[v].eb(u);
        has.emplace(min(u, v), max(u, v));
        e.eb(w, mp(u, v));
    }
    sort(e.begin(), e.end());

    DSU d(n);
    vector<vector<int>> comps(n);
    vector<pair<int, pair<int, int>>> tree;
    ll other = (ll)n * (n - 1) / 2 - m;
    for (int it = 0; it < 21; ++it) {
        for (int i = 0; i < n; ++i) {
            comps[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            comps[d.par(i)].pb(i);
        }
        vector<pair<int, pair<int, int>>> ec;
        vector<int> al;
        for (int i = 0; i < n; ++i) {
            if (!comps[i].empty())
                al.pb(i);
        }

        for (int i = 0; i < comps.size(); ++i) {
            if (comps[i].empty()) {
                continue;
            }
            map<int, int> cnt;
            for (int v : comps[i]) {
                for (int u : g[v]) {
                    if (!d.check(u, v)) {
                        cnt[d.par(u)]++;
                    }
                }
            }
            vector<pair<int, int>> cntv(cnt.begin(), cnt.end());
            cntv.eb(i, 0);
            bool found = false;
            for (int j = 0; j < cntv.size(); ++j) {
                if (cntv[j].first == i) continue;
                ll sza = d.rk[i];
                ll szb = d.rk[cntv[j].first];
                if (sza * szb > cntv[j].second) {
                    for (int v : comps[i]) {
                        for (int u : g[v]) {
                            if (d.par(u) == cntv[j].first) {
                                ec.eb(0, mp(u, v));
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }
                    assert(found);
                    break;
                }
            }
            if (found) continue;
            assert(cntv.size() <= al.size());
            if (cntv.size() < al.size()) {
                sort(cntv.begin(), cntv.end());
                for (int j = 0; j < al.size(); ++j) {
                    if (j >= cntv.size() || cntv[j].first != al[j]) {
                        int v = comps[i][0];
                        int u = comps[al[j]][0];
                        ec.eb(0, mp(u, v));
                        break;
                    }
                }
            }
        }
        if (ec.empty()) break;
        for (auto [w, uv] : ec) {
            auto [u, v] = uv;
            assert(w == 0);
            if (d.check(u, v)) continue;
            --other;
            tree.eb(0, mp(u, v));
            d.un(u, v);
        }
    }

    ll sm = 0;

    vector<pair<int, pair<int, int>>> notree;

    for (auto [w, uv] : e) {
        auto [u, v] = uv;
        if (d.check(u, v)) {
            notree.eb(w, uv);
            continue;
        }
        d.un(u, v);
        sm += w;
        tree.eb(w, uv);
    }

    if (other > 0) {
        cout << sm << '\n';
        return 0;
    }

    ll ans = sm + x;

    {
        vector<vector<pair<int, int>>> gtree(n);
        for (auto [w, uv] : tree) {
            auto [u, v] = uv;
            gtree[u].eb(v, w);
            gtree[v].eb(u, w);
        }

        vector<int> par(n, -1);
        vector<bool> u(n, false);
        vector<int> lvl(n, 0);
        function<void(int)> dfs1 = [&](int v) {
            u[v] = true;
            for (auto [k, w] : gtree[v]) {
                if (!u[k]) {
                    par[k] = v;
                    lvl[k] = lvl[v] + 1;
                    dfs1(k);
                }
            }
        };
        show(gtree);
        dfs1(0);
        build_lca_sparse(gtree, 0);

        map<pair<int, int>, int> mem;
        show(lvl);

        DSU2 d(n);
        d.lvl = lvl;
        auto go_up2 = [&](int v, int k, int w) {
            show(v, k);
            while (lvl[v] > lvl[k]) {
                v = d.high[d.par(v)];
                if (lvl[v] <= lvl[k]) break;
                d.un(v, par[v]);
                mem[mp(min(v, par[v]), max(v, par[v]))] = w;
            }
            show(v, k);
        };
        
        for (auto [w, uv] : notree) {
            auto [u, v] = uv;
            int k = get_lca(u, v);
            go_up2(u, k, w);
            go_up2(v, k, w);
        }

        for (auto [w, uv] : tree) {
            auto [u, v] = uv;
            if (u > v) swap(u, v);
            if (has.count({u, v})) continue;
            if (!mem.count({u, v})) continue;
            ans = min(ans, sm + mem[{u, v}] - w);
        }
    }
    cout << ans << '\n';

    return 0;
}