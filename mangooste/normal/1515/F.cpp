#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

    int n, m, x;
    cin >> n >> m >> x;
    vec<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vec<ar<int, 2>> edges(m);
    for (auto &[v, u] : edges) {
        cin >> v >> u, v--, u--;
    }
    if (accumulate(all(a), 0ll) < ll(n - 1) * x) {
        cout << "NO\n";
        return 0;
    }
    vec<set<int>> out(n);
    for (int i = 0; i < m; i++) {
        out[edges[i][0]].insert(i);
        out[edges[i][1]].insert(i);
    }
    vec<int> par(n);
    iota(all(par), 0);
    set<pair<ll, int>, greater<>> open;
    for (int i = 0; i < n; i++) {
        open.emplace(a[i], i);
    }
    auto get_par = y_combinator([&](auto get_par, int v) -> int {
        return v == par[v] ? v : par[v] = get_par(par[v]);
    });
    auto unite = [&](int v, int u) {
        v = get_par(v), u = get_par(u);
        if (v == u || a[v] + a[u] < x) return false;
        if (len(out[v]) < len(out[u])) swap(v, u);
        for (auto i : out[u]) {
            out[v].insert(i);
        }
        set<int>().swap(out[u]);
        open.erase({a[u], u});
        open.erase({a[v], v});
        par[u] = v;
        a[v] += a[u] - x;
        open.emplace(a[v], v);
        return true;
    };
    int free = m - 1;
    vec<int> ord;
    while (len(open) > 1) {
        if (open.begin()->first >= x) {
            int v = open.begin()->second;
            assert(get_par(v) == v);
            while (true) {
                assert(len(out[v]));
                int i = *out[v].begin();
                out[v].erase(out[v].begin());
                ar<int, 2> pars = {get_par(edges[i][0]), get_par(edges[i][1])};
                assert(pars[0] == v || pars[1] == v);
                if (pars[0] == v && pars[1] == v) continue;
                ord.push_back(i);
                assert(unite(v, (pars[0] == v ? edges[i][1] : edges[i][0])));
                break;
            }
        } else {
            while (true) {
                assert(free >= 0);
                int cur = free--;
                if (unite(edges[cur][0], edges[cur][1])) {
                    ord.push_back(cur);
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    for (auto x : ord) {
        cout << x + 1 << '\n';
    }
}