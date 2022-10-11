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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    auto add = [](vector<int> &a, const vector<int> &b) {
        int n = len(a);
        for (int i = 0; i < n; i++)
            a[(i + 1) % n] ^= b[i];
    };

    vector<vector<int>> dp(n, vector<int>(2 * k));

    y_combinator([&](auto dfs, int v) -> void {
        dp[v][0] = a[v];
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            add(dp[v], dp[u]);
        }
    })(0);

    vector<int> answer(n);

    y_combinator([&](auto dfs, int v) -> void {
        for (int i = k; i < 2 * k; i++)
            answer[v] ^= dp[v][i];

        for (auto u : g[v]) {
            add(dp[v], dp[u]);
            add(dp[u], dp[v]);
            dfs(u);
            add(dp[u], dp[v]);
            add(dp[v], dp[u]);
        }
    })(0);

    for (int i = 0; i < n; i++)
        cout << (answer[i] > 0) << " \n"[i == n - 1];
}