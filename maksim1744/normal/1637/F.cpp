/*
    author:  Maksim1744
    created: 12.02.2022 18:12:22
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);
    cin >> h;
    int root = maxi(h);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const ll inf = 1e18;
    vector<array<ll, 2>> dp(n, {inf, inf});
    vector<int> mx(n);
    y_combinator([&](auto dfs, int v, int p) -> void {
        mx[v] = -1;
        vector<ll> deltas;
        ll base = 0;
        for (int k : g[v]) {
            if (k == p) continue;
            dfs(k, v);
            mx[v] = max(mx[v], mx[k]);
            deltas.pb(dp[k][0] - dp[k][1]);
            base += dp[k][1];
        }
        sort(deltas.begin(), deltas.end());

        if (h[v] >= mx[v]) {
            mx[v] = h[v];
            dp[v][0] = base;
            for (int i = 0; i + 1 < deltas.size(); ++i)
                dp[v][0] += deltas[i];
            dp[v][0] += h[v];
            dp[v][1] = base;
            for (int i = 0; i + 1 < deltas.size(); ++i)
                dp[v][1] += deltas[i];
        } else {
            dp[v][0] = base;
            for (ll x : deltas)
                dp[v][0] += x;
            dp[v][1] = base;
            for (int i = 0; i + 1 < deltas.size(); ++i)
                dp[v][1] += deltas[i];
        }
    })(root, -1);

    ll ans = 0;
    if (g[root].size() == 1) {
        ans = dp[g[root][0]][1] + h[root] * 2;
    } else {
        vector<ll> deltas;
        for (int k : g[root]) {
            ans += dp[k][1];
            deltas.pb(dp[k][0] - dp[k][1]);
        }
        sort(deltas.begin(), deltas.end());
        for (int i = 0; i + 2 < deltas.size(); ++i)
            ans += deltas[i];
        ans += h[root] * 2;
    }

    cout << ans << '\n';

    return 0;
}