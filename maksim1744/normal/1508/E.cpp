/*
    author:  Maksim1744
    created: 16.04.2021 18:45:58
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    --a;
    auto a0 = a;
    vector<int> where(n);
    for (int i = 0; i < n; ++i) {
        where[a[i]] = i;
    }
    vector<vector<int>> g(n);
    vector<int> par(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        par[v] = u;
        g[u].pb(v);
    }
    ll total = 0;
    int last = n;
    for (int i = 0; i < n; ++i) {
        int v = where[i];
        bool ok = false;
        for (int u : g[v]) {
            if (a[u] > a[v]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            last = i;
            while (par[v] != -1) {
                swap(a[v], a[par[v]]);
                v = par[v];
                total++;
            }
            break;
        }
    }
    show(total);
    ll was = total;
    for (int i = 0; i < n; ++i) {
        where[a[i]] = i;
    }

    vector<int> mn(n);
    vector<int> lvl(n);
    function<void(int)> dfs1 = [&](int v) {
        if (g[v].empty()) {
            mn[v] = a[v];
            return;
        }
        for (int k : g[v]) {
            lvl[k] = lvl[v] + 1;
            dfs1(k);
        }
        sort(g[v].begin(), g[v].end(), [&](int a, int b) {
            return mn[a] < mn[b];
        });
        mn[v] = mn[g[v][0]];
    };
    dfs1(0);

    vector<int> ind(n, 0);
    int v = 0;
    int tm = 0;
    vector<int> b(n);
    vector<bool> u(n, false);
    show(last);
    show(g);
    show(a);
    for (int i = 0; i < last; ++i) {
        show(i, v);
        while (ind[v] < g[v].size()) {
            if (u[g[v][ind[v]]]) {
                ++ind[v];
            } else {
                v = g[v][ind[v]];
            }
        }
        u[v] = true;
        b[v] = i;
        total += lvl[v];
        v = par[v];
        ++tm;
    }

    function<void(int)> dfs2 = [&](int v) {
        b[v] = tm;
        ++tm;
        for (int k : g[v]) {
            if (!u[k]) {
                dfs2(k);
            }
        }
    };
    if (!u[0])
        dfs2(0);

    if (was) {
        show(was);
        show(a, b);
        v = 0;
        ind.assign(n, 0);
        if (!u[0]) {
            while (ind[v] < g[v].size() && was) {
                if (b[g[v][ind[v]]] < b[v]) {
                    ++ind[v];
                } else {
                    swap(b[v], b[g[v][ind[v]]]);
                    v = g[v][ind[v]];
                    --was;
                }
            }
        }
        if (was != 0) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    show(a, b);
    show(a0);

    if (a0 == b) {
        int tm = 0;
        vector<int> c(n);
        function<void(int)> dfs3 = [&](int v) {
            c[v] = tm;
            ++tm;
            for (int k : g[v]) {
                dfs3(k);
            }
        };
        dfs3(0);
        cout << "YES\n";
        ++c;
        cout << total << '\n';
        cout << c << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}