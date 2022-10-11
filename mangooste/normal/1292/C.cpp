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

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    inline decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].emplace_back(u, 0);
        g[u].emplace_back(v, 0);
    }

    vector<vector<int>> dist(n, vector<int>(n));
    y_combinator([&](auto dfs, int v, int parent) -> vector<pair<int, int>> {
        vector<pair<int, int>> current{{v, 0}};
        for (auto &[u, d] : g[v])
            if (u != parent) {
                auto sons = dfs(u, v);
                d = len(sons);
                for (const auto &[a, da] : sons)
                    for (const auto &[b, db] : current)
                        dist[a][b] = dist[b][a] = da + 1 + db;

                for (const auto &[a, da] : sons)
                    current.emplace_back(a, da + 1);
            }

        for (auto &[u, d] : g[v])
            if (u == parent)
                d = n - len(current);

        return current;
    })(0, -1);

    vector<vector<ll>> dp(n, vector<ll>(n));
    vector<vector<int>> left(n, vector<int>(n));
    vector<vector<int>> right(n, vector<int>(n));
    for (int v = 0; v < n; v++)
        for (const auto &[u, d] : g[v]) {
            dp[v][u] = d * (n - d);
            left[v][u] = n - d;
            right[v][u] = d;
        }

    vector<vector<pair<int, int>>> pairs(n);
    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
            pairs[dist[v][u]].emplace_back(v, u);

    for (int d = 1; d < n; d++)
        for (const auto &[v, u] : pairs[d]) {
            for (const auto &[w, d] : g[u])
                if (dist[v][u] != dist[v][w] + 1) {
                    left[v][w] = left[v][u];
                    right[v][w] = d;
                    dp[v][w] = max(dp[v][w], dp[v][u] + left[v][u] * d);
                }

            for (const auto &[w, d] : g[v])
                if (dist[v][u] != dist[u][w] + 1) {
                    left[w][u] = d;
                    right[w][u] = right[v][u];
                    dp[w][u] = max(dp[w][u], dp[v][u] + d * right[v][u]);
                }
        }

    ll answer = 0;
    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
            answer = max(answer, dp[v][u]);

    cout << answer << '\n';
}