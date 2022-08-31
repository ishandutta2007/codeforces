/*
    author:  Maksim1744
    created: 18.12.2021 20:13:27
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> same;
    vector<pair<int, int>> dif;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        --x; --y;
        g[x].eb(y, v);
        g[y].eb(x, v);
        if (v != -1) {
            if (__builtin_popcount(v) % 2 == 0) {
                same.eb(x, y);
            } else {
                dif.eb(x, y);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        --a; --b;
        if (p % 2 == 0) {
            same.eb(a, b);
        } else {
            dif.eb(a, b);
        }
    }
    vector<vector<pair<int, int>>> gc(n);
    for (auto [u, v] : same) {
        gc[u].eb(v, 0);
        gc[v].eb(u, 0);
    }
    for (auto [u, v] : dif) {
        gc[u].eb(v, 1);
        gc[v].eb(u, 1);
    }
    show(g);
    show(same);
    show(dif);
    vector<int> col(n, -1);
    bool ok = true;
    {
        auto dfs = y_combinator([&](auto dfs, int v, int c) -> void {
            col[v] = c;
            for (auto [k, cc] : gc[v]) {
                if (col[k] == -1) {
                    dfs(k, c ^ cc);
                } else {
                    if (col[k] != (c ^ cc)) {
                        ok = false;
                    }
                }
            }
        });
        for (int i = 0; i < n; ++i) {
            if (col[i] == -1) {
                dfs(i, 0);
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    if (ok) {
        y_combinator([&](auto dfs, int v, int p) -> void {
            for (auto& [k, w] : g[v]) {
                if (k == p) continue;
                if (w == -1) {
                    w = (col[k] ^ col[v]);
                } else {
                    if (__builtin_popcount(w) % 2 != (col[k] ^ col[v])) {
                        assert(false);
                    }
                }
                ans.eb(mp(k, v), w);
                dfs(k, v);
            }
        })(0, -1);
    }
    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto [uv, w] : ans) {
        ++uv;
        cout << uv << ' ' << w << '\n';
    }
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