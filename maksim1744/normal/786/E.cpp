/*
    author:  Maksim1744
    created: 17.05.2021 18:21:32
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> edge_num;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge_num[{u, v}] = edge_num[{v, u}] = i;
    }

    vector<pair<int, int>> paths(m);
    cin >> paths;
    --paths;

    vector<int> lvl(n);
    vector<int> par(n);
    y_combinator([&](auto dfs, int v, int p = -1) -> void {
        par[v] = p;
        for (int k : g[v]) {
            if (k != p) {
                lvl[k] = lvl[v] + 1;
                dfs(k, v);
            }
        }
    })(0);

    vector<pair<int, int>> matching;

    {
        vector<bool> u(n + m, false);
        vector<int> from(n + m, -1);

        auto dfs = y_combinator([&](auto dfs, int v) -> bool {
            u[v] = true;
            auto [x, y] = paths[v];
            while (x != y) {
                int k;
                if (lvl[x] > lvl[y]) {
                    k = x;
                    x = par[x];
                } else {
                    k = y;
                    y = par[y];
                }
                k += m;
                if (from[k] == -1 || (!u[from[k]] && dfs(from[k]))) {
                    from[k] = v;
                    return true;
                }
            }
            return false;
        });

        for (int v = 0; v < m; ++v)
            if (dfs(v))
                u.assign(n + m, false);
        for (int v = 0; v < from.size(); ++v) {
            if (from[v] != -1) {
                matching.emplace_back(from[v], v);
            }
        }
    }

    vector<int> ans;

    {
        vector<bool> u(n + m, false);
        vector<bool> take(n + m, false);
        vector<int> with(n + m, -1);

        auto dfs = y_combinator([&](auto dfs, int v) -> void {
            u[v] = true;
            auto [x, y] = paths[v];
            while (x != y) {
                int k;
                if (lvl[x] > lvl[y]) {
                    k = x;
                    x = par[x];
                } else {
                    k = y;
                    y = par[y];
                }
                k += m;
                take[k] = true;
                if (!u[with[k]])
                    dfs(with[k]);
            }
        });

        for (auto edge : matching) {
            with[edge.first] = edge.second;
            with[edge.second] = edge.first;
        }
        for (int v = 0; v < m; ++v)
            if (with[v] == -1)
                dfs(v);
        for (auto e : matching)
            if (!take[e.second])
                take[e.first] = true;
        ans.resize(matching.size());
        for (int i = 0; i < matching.size(); ++i) {
            if (take[matching[i].second]) ans[i] = matching[i].second;
            else ans[i] = matching[i].first;
        }
    }

    show(ans);

    vector<int> v1, v2;
    for (int k : ans) {
        if (k < m)
            v1.pb(k);
        else
            v2.pb(edge_num[{k - m, par[k - m]}]);
    }

    show(v1, v2);
    cout << ans.size() << '\n';
    ++v1; ++v2;
    cout << v1.size() << ' ';
    cout << v1 << '\n';
    cout << v2.size() << ' ';
    cout << v2 << '\n';

    return 0;
}