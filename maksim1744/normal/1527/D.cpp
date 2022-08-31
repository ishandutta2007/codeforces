/*
    author:  Maksim1744
    created: 20.05.2021 18:22:14
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
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> where(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] < where.size())
            where[a[i]] = i;
    }
    
    build_lca_sparse(g, where[0]);
    
    vector<bool> u(n, false);
    vector<int> sz(n, 1);
    vector<bool> has1(n, false);
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        if (a[v] == 1) has1[v] = true;
        for (int k : g[v]) {
            if (!u[k]) {
                dfs(k);
                has1[v] = (has1[v] || has1[k]);
                sz[v] += sz[k];
            }
        }
    };


    
    dfs(where[0]);
    ll count_0 = 0;
    for (int k : g[where[0]]) {
        count_0 += (ll)sz[k] * (sz[k] - 1) / 2;
    }
    
    ll other0 = 1;
    for (int k : g[where[0]]) {
        if (!has1[k])
            other0 += sz[k];
    }
    
    vector<int> pth = {where[0]};
    vector<ll> cnt = {0};
    cnt[0] = (ll)n * (n - 1) / 2;
    for (int k : g[where[0]]) {
        cnt[0] -= (ll)sz[k] * (sz[k] - 1) / 2;
    }
    int down1 = where[0];
    int down2 = where[0];
    auto gets = [&](int v) {
        if (a[v] == 0) return other0;
        return (ll)sz[v];
    };
    for (int k = 1; where[k] != -1; ++k) {
        int v = where[k];
        if (dist(where[0], v) + dist(v, down1) == dist(where[0], down1)) {
            pth.pb(v);
        } else if (dist(where[0], v) == dist(v, down1) + dist(where[0], down1)) {
            down1 = v;
            pth.pb(v);
        } else if (dist(where[0], v) + dist(v, down2) == dist(where[0], down2)) {
            pth.pb(v);
        } else if (dist(where[0], v) == dist(v, down2) + dist(where[0], down2) && get_lca(v, down1) == where[0]) {
            down2 = v;
            pth.pb(v);
        } else {
            break;
        }
        cnt.pb(gets(down1) * gets(down2));
    }
    cnt.pb(0);
    
    show(pth);
    show(cnt);


    vector<ll> result(n + 5, 0);
    for (int i = 0; i + 1 < cnt.size(); ++i)
        result[i + 1] = cnt[i] - cnt[i + 1];
    result[0] = count_0;
    result.resize(n + 1);
    cout << result << '\n';

    // ll ans = 0;
    // for (int i = 0; i < pth.size(); ++i) {
    //     ll curc = cnt[i] - cnt[i + 1];
    //     show(curc, i+1);
    //     ans += curc * (i + 1);
    // }
    // cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}