/*
    author:  Maksim1744
    created: 11.05.2021 12:03:25
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

vector<int> scc(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> topsort; topsort.reserve(n);
    vector<bool> u(n, false);
    function<void(int)> scc_dfs1 = [&](int v) {
        u[v] = true;
        for (auto k : g[v])
            if (!u[k])
                scc_dfs1(k);
        topsort.push_back(v);
    };
    for (int i = 0; i < n; ++i)
        if (!u[i])
            scc_dfs1(i);
    vector<vector<int>> gi(n);
    for (int i = 0; i < n; ++i)
        for (auto j : g[i])
            gi[j].push_back(i);
    int color = 0;
    vector<int> comp(n, -1);
    reverse(topsort.begin(), topsort.end());
    function<void(int, int)> scc_dfs2 = [&](int v, int color) {
        comp[v] = color;
        for (auto k : gi[v])
            if (comp[k] == -1)
                scc_dfs2(k, color);
    };
    for (auto v : topsort)
        if (comp[v] == -1)
            scc_dfs2(v, color++);
    return comp;
}

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

const int N = 2000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<bitset<N>> mt(n, 0);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            mt[i][j] = (s[j] == '1');
            if (mt[i][j])
                g[i].pb(j);
        }
    }

    auto col = scc(g);
    vector<vector<int>> comps(maxe(col) + 1);
    for (int i = 0; i < n; ++i) {
        comps[col[i]].pb(i);
    }

    if (comps.size() == 1) {
        cout << 0 << ' ' << 1 << '\n';
        return 0;
    }
    int c1 = 0;
    for (int i = 1; i + 1 < comps.size(); ++i) {
        c1 += comps[i].size();
    }

    show(comps);

    for (int it = 0; it < 2; ++it) {
        if (comps[0].size() > 1) {
            vector<bitset<N>> mt2(comps[0].size(), 0);
            for (int i = 0; i < comps[0].size(); ++i) {
                for (int j = 0; j < comps[0].size(); ++j) {
                    mt2[i][j] = mt[comps[0][i]][comps[0][j]];
                }
            }
            int m = comps[0].size();
            for (int v = 0; v < comps[0].size(); ++v) {
                for (int i = 0; i < m; ++i) {
                    mt2[i].flip(v);
                }
                mt2[v].flip();
                bitset<N> u = 0;
                for (int i = 0; i < m; ++i) {
                    u[i] = 1;
                }
                auto dfs = y_combinator([&](auto dfs, int v) -> void {
                    u[v] = 0;
                    // auto b = (u & mt2[v]);
                    for (int i = (u & mt2[v])._Find_first(); i < m; i = (u & mt2[v])._Find_next(i)) {
                    // for (int i = 0; i < m; ++i) {
                        if (mt2[v][i] && u[i])
                            dfs(i);
                    }
                });
                dfs(v);
                if (u.count() == 0) ++c1;
                for (int i = 0; i < m; ++i) {
                    mt2[i].flip(v);
                }
                mt2[v].flip();
            }
        }

        for (int i = 0; i < n; ++i) {
            mt[i].flip();
            mt[i][i] = 0;
        }
        g.clear();
        g.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mt[i][j])
                    g[i].pb(j);
            }
        }
        col = scc(g);
        comps.assign(comps.size(), {});
        for (int i = 0; i < n; ++i) {
            comps[col[i]].pb(i);
        }
    }

    if (c1 != 0) {
        cout << 1 << ' ' << c1 << '\n';
        return 0;
    }

    if (comps[0].size() == 1 || comps.back().size() == 1) {
        cout << -1 << '\n';
    } else {
        cout << "2 " << comps[0].size() * comps.back().size() * 2 << '\n';
    }

    return 0;
}