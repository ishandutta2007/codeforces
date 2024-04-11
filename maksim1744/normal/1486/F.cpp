/*
    author:  Maksim1744
    created: 18.02.2021 18:08:23
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

vector<int> lca_ind;
vector<vector<int>> lca_sparse;
vector<int> lca_p2;
vector<int> lca_depth;
void build_lca_sparse(vector<vector<int>>& g, int root = 0) {
    int n = g.size();
    vector<int> euler;
    lca_ind.resize(n);
    lca_depth.assign(n, -1);
    function<void(int, int)> dfs = [&](int v, int depth) {
        lca_ind[v] = euler.size();
        euler.pb(v);
        lca_depth[v] = depth;
        for (auto k : g[v]) {
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

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int m;
    cin >> m;
    build_lca_sparse(g, 0);
    vector<pair<int, int>> e(m);
    cin >> e;
    --e;

    vector<int> dots(n, 0);

    vector<vector<pair<int, int>>> bylca(n);
    vector<vector<pair<int, int>>> byup(n);

    vector<ll> uplca(n, 0), downlca(n, 0);

    vector<int> lvl(n, 0);
    vector<vector<int>> up(20, vector<int>(n, -1));
    {
        vector<bool> u(n, false);
        function<void(int)> dfs1 = [&](int v) {
            u[v] = true;
            for (auto k : g[v]) {
                if (!u[k]) {
                    lvl[k] = lvl[v] + 1;
                    up[0][k] = v;
                    dfs1(k);
                }
            }
        };
        dfs1(0);
        for (int i = 1; i < up.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                if (up[i - 1][j] != -1) {
                    up[i][j] = up[i - 1][up[i - 1][j]];
                }
            }
        }
    }

    auto get_up = [&](int v, int k) {
        for (int i = 0; i < up.size(); ++i) {
            if ((k >> i) & 1) {
                v = up[i][v];
            }
        }
        return v;
    };

    vector<ll> lca2(n, 0);

    for (auto [u, v] : e) {
        if (u == v) {
            dots[u]++;
            continue;
        }
        int k = get_lca(u, v);

        if (k == u || k == v) {
            uplca[k]++;
            downlca[k ^ u ^ v]++;
            int x = (k ^ u ^ v);
            x = get_up(x, lvl[x] - lvl[k] - 1);
            lca2[x]++;
        } else {
            bylca[get_lca(u, v)].eb(u, v);
            byup[u].eb(u, get_lca(u, v));
            byup[v].eb(v, get_lca(u, v));
            downlca[u]++;
            downlca[v]++;
        }
    }

    show(uplca);
    show(downlca);

    ll ans = 0;
    show(byup);
    show(bylca);
    show(lca2);

    vector<bool> u(n, false);
    vector<int> cup(n, 0);
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        vector<int> ch;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k);
                ch.pb(k);
            }
        }
        for (auto [x, y] : bylca[v]) {
            int k = get_lca(x, y);
            assert(k == v);
            if (k == x || k == y)
                assert(false);
            x = get_up(x, lvl[x] - lvl[k] - 1);
            y = get_up(y, lvl[y] - lvl[k] - 1);
            cup[x]--;
            cup[y]--;
        }
        for (int k : ch)
            cup[v] += cup[k];

        show(v, dots[v], uplca[v], downlca[v], bylca[v], cup[v]);

        ll trash = 0;
        trash += (ll)(dots[v]) * (cup[v] + bylca[v].size()) * 2;
        trash += (ll)(downlca[v]) * (uplca[v] + bylca[v].size()) * 2;
        trash += (ll)dots[v] * downlca[v] * 2;
        trash += (ll)dots[v] * (dots[v] - 1);
        show(v, trash);
        ans += trash;

        vector<pair<int, int>> pr;

        for (auto [x, y] : bylca[v]) {
            x = get_up(x, lvl[x] - lvl[v] - 1);
            y = get_up(y, lvl[y] - lvl[v] - 1);
            ans += (cup[v] - cup[x] - cup[y]) * 2;
            pr.eb(x, y);
        }
        show(v, pr);
        ll cur = (ll)pr.size() * (pr.size() - 1) / 2;
        map<int, ll> byx, byy;
        for (auto [x, y] : pr) {
            byx[x]++;
            byx[y]++;
        }
        for (auto [a, b] : byx) {
            cur -= b * (b - 1) / 2;
        }
        map<pair<int, int>, ll> by2;
        for (auto p : pr) {
            by2[{min(p.first, p.second), max(p.first, p.second)}]++;
        }
        show(byx, byy, by2);
        for (auto [a, b] : by2) {
            cur += b * (b - 1) / 2;
        }
        show(cur);
        ans += cur * 2;


        ll cups = 0;
        // cups += (ll)cup[v] * (cup[v] - 1);
        // for (auto k : ch) {
        //     cups -= (ll)cup[k] * (cup[k] - 1);
        // }
        for (auto k : ch)
            cups += lca2[k] * (cup[v] - cup[k]);
        for (auto k : ch)
            cup[k] -= lca2[k];
        ll sm = 0;
        for (auto k : ch)
            sm += cup[k];
        for (auto k : ch)
            cups += lca2[k] * (sm - cup[k]);
        show(v, cups, cup);
        ans += cups;


        cup[v] -= uplca[v];
        cup[v] += downlca[v];
        show(v, ans);
        shows;
    };
    dfs(0);
    show(ans);
    cout << ans / 2 << '\n';

    return 0;
}