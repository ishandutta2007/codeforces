/*
    author:  Maksim1744
    created: 28.02.2021 17:25:35
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

    set<int> fibs;
    fibs.insert(1);
    int a = 1, b = 1;
    while (*--fibs.end() <= n * 3 + 20) {
        int c = a + b;
        fibs.insert(c);
        a = b;
        b = c;
    }

    vector<int> u(n, -1);
    int ustep = 0;
    vector<char> dead(n, false);
    vector<int> sz(n);

    vector<char> is_fib(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        is_fib[i] = fibs.count(i);
    }

    vector<pair<int, pair<int, int>>> prs;
    auto check = y_combinator([&](auto check, int v, int s) -> bool {
        if (!is_fib[s]) return false;
        if (s <= 3) return true;

        ++ustep;
        prs.clear();
        auto dfs = y_combinator([&](auto dfs, int v) -> void {
            u[v] = ustep;
            sz[v] = 1;
            for (int k : g[v]) {
                if (u[k] != ustep && !dead[k]) {
                    dfs(k);
                    sz[v] += sz[k];
                    if (is_fib[sz[k]] && is_fib[s - sz[k]]) {
                        prs.eb(v, mp(k, sz[k]));
                    }
                }
            }
        });
        dfs(v);

        for (auto [a, bs] : prs) {
            auto [b, s0] = bs;
            dead[a] = true;
            if (check(b, s0)) {
                dead[a] = false;
                dead[b] = true;
                bool ok = false;
                if (check(a, s - s0)) {
                    ok = true;
                }
                dead[b] = false;
                if (ok) {
                    return true;
                }
            } else {
                dead[a] = false;
            }
        }
        return false;
    });

    if (check(0, n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}