/*
    author:  Maksim1744
    created: 01.03.2020 17:39:49
*/

#include <bits/stdc++.h>

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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build_lca_sparse(g, 0);
    vector<int> order;
    vector<bool> u(n, false);
    vector<int> tin(n), tout(n);
    int timer = 0;

    function<void(int)> dfs = [&](int v) {
        tin[v] = timer++;
        u[v] = true;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k);
            }
        }
        tout[v] = timer++;
    };
    dfs(0);

    vector<int> inf(n, 0);
    vector<int> col(n);
    int tinf = 1;

    vector<vector<pair<int, int>>> g0(n);
    int q;
    cin >> q;
    while (q--) {
        int k, m;
        cin >> k >> m;
        vector<int> speed(k);
        vector<int> st(k);
        for (int i = 0; i < k; ++i) {
            cin >> st[i] >> speed[i];
            --st[i];
        }
        vector<int> ess(m);
        cin >> ess;
        --ess;
        vector<int> ver = ess;
        for (int i = 0; i < k; ++i) {
            ver.pb(st[i]);
        }
        sort(ver.begin(), ver.end());
        ver.erase(unique(ver.begin(), ver.end()), ver.end());
        sort(ver.begin(), ver.end(), [&](int i, int j) {return tin[i] < tin[j];});
        int x = ver.size();
        for (int i = 0; i < x - 1; ++i) {
            ver.pb(get_lca(ver[i], ver[i + 1]));
        }
        ver.pb(get_lca(ver[0], ver[x - 1]));
        sort(ver.begin(), ver.end());
        ver.erase(unique(ver.begin(), ver.end()), ver.end());
        vector<pair<int, int>> ev;
        for (auto v : ver) {
            ev.eb(tin[v], v);
            ev.eb(tout[v], v);
        }
        sort(ev.begin(), ev.end());
        vector<int> sta;
        for (auto [tm, v] : ev) {
            if (!sta.empty() && sta.back() == v) {
                sta.pop_back();
            } else {
                if (!sta.empty()) {
                    int d = dist(v, sta.back());
                    g0[sta.back()].eb(v, d);
                    g0[v].eb(sta.back(), d);
                }
                sta.pb(v);
            }
        }

        set<pair<pair<int, int>, pair<int, int>>> s;

        for (int i = 0; i < k; ++i) {
            inf[st[i]] = tinf;
            col[st[i]] = i;
            for (auto [u, w] : g0[st[i]]) {
                s.emplace(mp((w + speed[i] - 1) / speed[i], i), mp(u, w));
            }
        }


        while (!s.empty()) {
            show(s);
            auto [sth, vv] = *s.begin();
            auto v = vv.first;
            int ind = sth.second;
            s.erase(s.begin());
            if (inf[v] == tinf) continue;
            inf[v] = tinf;
            col[v] = ind;
            for (auto [u, w] : g0[v]) {
                if (inf[u] < tinf) {
                    s.emplace(mp((vv.second + w + speed[ind] - 1) / speed[ind], ind), mp(u, vv.second + w));
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            cout << col[ess[i]] + 1 << ' ';
        }
        cout << '\n';

        for (auto x : ver) {
            g0[x].clear();
        }
        ++tinf;
    }

    return 0;
}