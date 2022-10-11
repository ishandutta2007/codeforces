#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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


void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<int> value(n);
    for (auto &x : value)
        cin >> x;

    vector<int> need(n);
    for (auto &x : need)
        cin >> x;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> color(n, -1);
    color[0] = 0;
    bool ok = true;

    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : g[v])
            if (color[u] == -1) {
                color[u] = color[v] ^ 1;
                dfs(u);
            } else if (color[u] == color[v]) {
                ok = false;
            }
    })(0);

    if (!ok) {
        int have = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            have ^= value[i] & 1;
            tot ^= need[i] & 1;
        }
        cout << (have == tot ? "YES\n" : "NO\n");
        return;
    }

    array<ll, 2> sums{0, 0};
    for (int i = 0; i < n; i++)
        sums[color[i]] += need[i] - value[i];

    cout << (sums[0] == sums[1] ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve_case();
}