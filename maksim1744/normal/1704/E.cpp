/*
    author:  Maksim1744
    created: 31.07.2022 17:24:52
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

const int mod = 998244353;

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    cin >> a;
    vector<vector<int>> g(n);
    vector<vector<int>> gi(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        gi[v].pb(u);
    }
    vector<int> order;
    {
        vector<bool> u(n, false);
        for (int i = 0; i < n; ++i) {
            if (!u[i]) {
                y_combinator([&](auto dfs, int v) -> void {
                    u[v] = true;
                    for (int k : g[v])
                        if (!u[k])
                            dfs(k);
                    order.pb(v);
                })(i);
            }
        }
    }

    auto is_good = [&]() {
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (a[i] != 0 && a[j] == 0)
                    return false;
            }
        }
        return true;
    };

    ll ans = 0;

    while (!is_good()) {
        ++ans;
        for (int v : order) {
            if (a[v] > 0) --a[v];
            for (int k : gi[v])
                if (a[k] > 0)
                    ++a[v];
        }
    }

    auto rev = order;
    reverse(rev.begin(), rev.end());
    vector<bool> dead(n, false);

    while (true) {
        for (ll& x : a) x = (x % mod + mod) % mod;
        if (sum(a) == 0) break;
        for (int v : rev) {
            dead[v] = true;
            if (a[v] > 0) dead[v] = false;
            for (int k : gi[v])
                if (!dead[k])
                    dead[v] = false;
        }

        ll steps = mod + 1;
        for (int i = 0; i < n; ++i) {
            if (dead[i]) continue;
            bool ok = true;
            for (int k : gi[i])
                if (!dead[k])
                    ok = false;
            if (!ok) continue;
            steps = min(steps, a[i]);
        }
        show(a, steps);

        for (int i : order) {
            if (dead[i]) continue;
            ll tot = 0;
            for (int k : gi[i])
                if (!dead[k])
                    ++tot;
            if (tot == 0) a[i] -= steps;
            else a[i] += steps * (tot - 1);
        }
        ans += steps;
    }

    cout << ans % 998244353 << '\n';
    cout.flush();
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