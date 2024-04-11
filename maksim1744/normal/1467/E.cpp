/*
    author:  Maksim1744
    created: 08.01.2021 18:33:14
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
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
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
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> notree(n, false);
    vector<int> need(n, 0);
    int needcnt = 0;
    vector<int> par(n, -1);
    build_lca_sparse(g, 0);

    for (int ii = 0; ii < 2; ++ii) {
        vector<int> order;
        vector<bool> u(n, false);
        function<void(int)> dfs1 = [&](int v) {
            u[v] = true;
            if (ii == 0) order.pb(v);
            for (auto k : g[v]) {
                if (!u[k]) {
                    par[k] = v;
                    dfs1(k);
                }
            }
            if (ii == 1) order.pb(v);
        };
        dfs1(0);
        map<int, vector<int>> m;
        for (auto k : order) {
            m[a[k]].pb(k);
        }


        for (auto [a, v] : m) {
            if (v.size() == 1) continue;
            for (int i = 0; i + 1 < v.size(); ++i) {
                int a = v[i], b = v[i + 1];
                int c = get_lca(a, b);
                if (c != a && c != b) {
                    notree[a] = true;
                    notree[b] = true;
                    continue;
                }
                if (b == c) swap(a, b);
                notree[b] = true;
                needcnt++;
                for (auto k : g[a]) {
                    if (k == par[a]) continue;
                    if (get_lca(k, b) == k) {
                        need[k]++;
                        need[b]--;
                        break;
                    }
                }
                // need[par[b]]++;
                // need[a]--;
            }
        }
    }

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int v, int x) {
        if (notree[v]) return;
        x += need[v];
        if (x == needcnt) ++ans;
        for (auto k : g[v]) {
            if (k != par[v]) {
                dfs2(k, x);
            }
        }
    };
    dfs2(0, 0);
    cout << ans << '\n';

    return 0;
}