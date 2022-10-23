/*
    author:  Maksim1744
    created: 07.10.2022 18:12:44
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    const ll inf = 1e18;
    vector<vector<int>> g(n);
    vector<vector<ll>> dd(n, vector<ll>(n, inf));
    for (int i = 0; i < n; ++i) {
        dd[i][i] = 0;
    }
    vector<pair<pair<int, int>, ll>> e;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        dd[u][v] = dd[v][u] = 1;
        e.eb(mp(u, v), w);
        g[u].pb(v);
        g[v].pb(u);
    }

    // vector<vector<ll>> d(n, vector<ll>(n, inf));
    // auto getd = [&](int u, int v) -> ll& {
    //     if (u > v) swap(u, v);
    //     return d[u][v];
    // };
    // getd(0, n-1) = 0;
    // queue<pair<int, int>> q;
    // q.emplace(0, n - 1);
    // while (!q.empty()) {
    //     auto [u, v] = q.front();
    //     q.pop();

    //     for (int it = 0; it < 2; ++it) {
    //         for (int k : g[v]) {
    //             if (getd(u, k) > getd(u, v) + 1) {
    //                 getd(u, k) = getd(u, v) + 1;
    //                 q.emplace(min(u, k), max(u, k));
    //             }
    //         }
    //         swap(u, v);
    //     }
    // }
    // show(d);

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dd[i][j] = min(dd[i][j], dd[i][k] + dd[k][j]);
            }
        }
    }

    auto mul = [&](ll a, ll b) {
        if (a >= inf || b >= inf) return inf;
        return a * b;
    };

    ll ans = inf;
    for (auto [uv, w] : e) {
        auto [u, v] = uv;
        for (int it = 0; it < 2; ++it) {
            ans = min(ans, mul(dd[0][u] + dd[v][n-1] + 1, w));
            for (int k = 0; k < n; ++k) {
                ans = min(ans, mul(dd[k][u] + 1 + dd[0][k] + dd[k][n-1] + 1, w));
            }
            swap(u, v);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}