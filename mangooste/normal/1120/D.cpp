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
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    constexpr ll INF = 1e18;
    vector<array<ll, 2>> dp(n, {INF, INF});

    y_combinator([&](auto dfs, int v) -> void {
        if (g[v].empty()) {
            dp[v][0] = c[v];
            dp[v][1] = 0;
            return;
        }

        ll sum0 = 0;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            sum0 += dp[u][0];
        }

        dp[v][0] = sum0;
        for (auto u : g[v]) {
            dp[v][0] = min(dp[v][0], sum0 - dp[u][0] + dp[u][1] + c[v]);
            dp[v][1] = min(dp[v][1], sum0 - dp[u][0] + dp[u][1]);
        }
    })(0);

    vector<int> answer;
    vector<array<bool, 2>> used(n, {false, false});

    y_combinator([&](auto dfs, int v, int type) -> void {
        if (used[v][type])
            return;

        used[v][type] = true;
        if (g[v].empty()) {
            if (type == 0)
                answer.push_back(v);

            return;
        }

        ll sum0 = 0;
        for (auto u : g[v])
            sum0 += dp[u][0];

        if (type == 0) {
            int down = 0;
            for (auto u : g[v])
                if (dp[v][0] == sum0 - dp[u][0] + dp[u][1] + c[v])
                    down++;

            if (down != 0)
                answer.push_back(v);

            if (dp[v][0] == sum0)
                for (auto u : g[v])
                    dfs(u, 0);

            for (auto u : g[v]) {
                int new_down = down - (dp[v][0] == sum0 - dp[u][0] + dp[u][1] + c[v]);
                if (new_down != 0)
                    dfs(u, 0);

                if (new_down != down)
                    dfs(u, 1);
            }
        } else {
            int down = 0;
            for (auto u : g[v])
                down += dp[v][1] == sum0 - dp[u][0] + dp[u][1];

            for (auto u : g[v]) {
                int new_down = down - (dp[v][1] == sum0 - dp[u][0] + dp[u][1]);
                if (new_down != 0)
                    dfs(u, 0);

                if (new_down != down)
                    dfs(u, 1);
            }
        }
    })(0, 0);

    sort(all(answer));
    cout << dp[0][0] << ' ' << len(answer) << '\n';
    for (int i = 0; i < len(answer); i++)
        cout << answer[i] + 1 << " \n"[i == len(answer) - 1];
}