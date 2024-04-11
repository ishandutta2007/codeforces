#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
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


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vec<vec<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    ll ans = 0;
    for (int rep = 0; rep < 2; rep++) {
        vec<pair<int, int>> vals;
        for (int i = 0; i < n; i++) {
            vals.emplace_back(a[i], i);
        }
        sort(all(vals));
        vec<char> active(n);
        vec<int> par(n);
        iota(all(par), 0);
        vec<int> sz(n, 1);
        auto get_par = y_combinator([&](auto get_par, int v) -> int {
            return par[v] == v ? v : par[v] = get_par(par[v]);
        });
        auto unite = [&](int v, int u) {
            if (!active[v] || !active[u]) return false;
            v = get_par(v), u = get_par(u);
            if (v == u) return false;
            if (sz[v] < sz[u]) swap(v, u);
            par[u] = v;
            sz[v] += sz[u];
            return true;
        };
        auto size = [&](int v) {
            if (!active[v]) return 0;
            return sz[get_par(v)];
        };
        for (auto [val, v] : vals) {
            int sum = 0;
            for (auto u : g[v]) {
                sum += size(u);
            }
            for (auto u : g[v]) {
                ans += ll(val) * (sum - size(u)) * size(u);
                ans += ll(val) * size(u) * 2;
            }
            active[v] = 1;
            for (auto u : g[v]) {
                unite(u, v);
            }
        }
        for (auto &x : a) {
            x *= -1;
        }
    }
    cout << ans / 2 << '\n';
}