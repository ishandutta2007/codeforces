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
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<array<int, 2>> dp(n);

    auto by_max = [&](int v, int u) {
        int value_v = max(dp[v][0], dp[v][1]);
        int value_u = max(dp[u][0], dp[u][1]);
        if (value_v != value_u)
            return value_v > value_u;

        return v < u;
    };

    vector<set<int, decltype(by_max)>> best_by_max(n, set<int, decltype(by_max)>(by_max));

    auto by_zero = [&](int v, int u) {
        if (dp[v][0] != dp[u][0])
            return dp[v][0] > dp[u][0];

        return v < u;
    };

    vector<set<int, decltype(by_zero)>> best_by_zero(n, set<int, decltype(by_zero)>(by_zero));

    auto init = [&](int v) {
        int sz = len(best_by_max[v]);
        if (sz == 0) {
            dp[v][0] = 0;
            dp[v][1] = 1;
            return;
        }

        int u = *best_by_max[v].begin();
        dp[v][0] = sz - 1 + max(dp[u][0], dp[u][1]);
        dp[v][1] = 1 + dp[*best_by_zero[v].begin()][0];
    };

    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            best_by_max[v].insert(u);
            best_by_zero[v].insert(u);
        }
        init(v);
    })(0);

    cout << y_combinator([&](auto dfs, int v) -> int {
        int answer = max(dp[v][0], dp[v][1]);
        for (auto u : g[v]) {
            best_by_max[v].erase(u);
            best_by_zero[v].erase(u);
            init(v);

            best_by_max[u].insert(v);
            best_by_zero[u].insert(v);
            init(u);

            answer = max(answer, dfs(u));

            best_by_max[u].erase(v);
            best_by_zero[u].erase(v);
            init(u);

            best_by_max[v].insert(u);
            best_by_zero[v].insert(u);
            init(v);
        }
        return answer;
    })(0) << '\n';  
}