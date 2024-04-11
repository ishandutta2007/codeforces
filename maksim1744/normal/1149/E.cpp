/*
    author:  Maksim1744
    created: 28.05.2021 12:51:39
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

namespace y_combinator_ns {
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
}
using namespace y_combinator_ns;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    cin >> h;
    vector<vector<int>> g(n);
    vector<vector<int>> gi(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        gi[v].pb(u);
    }

    vector<bool> u(n, false);
    vector<int> order;
    auto dfs = y_combinator([&](auto dfs, int v) -> void {
        u[v] = true;
        for (int k : gi[v])
            if (!u[k])
                dfs(k);
        order.pb(v);
    });
    for (int i = 0; i < n; ++i)
        if (!u[i])
            dfs(i);

    reverse(order.begin(), order.end());
    vector<int> lvl(n, 0);
    for (int v : order) {
        set<int> s;
        for (int k : g[v])
            s.insert(lvl[k]);
        while (s.count(lvl[v]))
            ++lvl[v];
    }

    int tot = maxe(lvl) + 1;
    vector<vector<int>> by_lvl(tot);
    for (int i = 0; i < n; ++i)
        by_lvl[lvl[i]].pb(i);

    for (int i = tot - 1; i >= 0; --i) {
        ll x = 0;
        for (int v : by_lvl[i])
            x ^= h[v];
        if (x == 0) continue;
        cout << "WIN\n";
        for (int v : by_lvl[i]) {
            if ((h[v] ^ x) < h[v]) {
                set<int> done;
                h[v] ^= x;
                for (int k : g[v]) {
                    if (done.count(lvl[k])) continue;
                    done.insert(lvl[k]);
                    int y = 0;
                    for (int v : by_lvl[lvl[k]])
                        y ^= h[v];
                    h[k] ^= y;
                }
                cout << h << '\n';
                return 0;
            }
        }
        assert(false);
    }
    cout << "LOSE\n";

    return 0;
}