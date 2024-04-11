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


template<typename T>
inline bool setmin(T &a, const T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
inline bool setmax(T &a, const T b) { if (a < b) { a = b; return true; } return false; }


struct graph {
    int n;
    vec<vec<int>> g;
    vec<int> pre;
    vec<ar<int, 2>> dp;
    vec<ar<pair<int, int>, 2>> par;

    graph(int n) : n(n), g(n), pre(n), dp(n), par(n) {}

    inline void read() {
        for (int i = 1; i < n; i++) {
            int v, u;
            cin >> v >> u, v--, u--;
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }

    vec<int> ord;

    void dfs(int v) {
        ord.push_back(v);
        int all_blocked = 0;
        for (auto u : g[v]) {
            if (u == pre[v]) continue;
            pre[u] = v;
            dfs(u);
            all_blocked += dp[u][0];
        }
        dp[v][0] = dp[v][1] = all_blocked + 1;
        par[v][0] = par[v][1] = {-1, -1};
        int min_delta = 1;
        int who = -1;
        for (auto u : g[v]) {
            if (u == pre[v]) continue;
            int cur_delta = dp[u][1] - dp[u][0];
            if (setmin(dp[v][0], all_blocked + cur_delta + min_delta - 1)) par[v][0] = {u, who};
            if (setmin(dp[v][1], all_blocked + cur_delta)) par[v][1] = {u, -1};
            if (setmin(min_delta, cur_delta)) who = u;
        }
        if (setmin(dp[v][0], dp[v][1])) par[v][0] = par[v][1];
    }

    inline void solve() {
        dfs(0);
        cout << dp[0][0] - 1 << '\n';
        vec<int> which(n);
        vec<pair<int, int>> ends;
        vec<char> used(n);
        for (auto i : ord) {
            if (used[i]) continue;
            used[i] = 1;
            ends.emplace_back(i, i);
            which[i] = len(ends) - 1;
            for (int v = par[i][0].first; v != -1; v = par[v][1].first) {
                which[v] = len(ends) - 1;
                used[v] = 1;
                ends.back().first = v;
            }
            for (int v = par[i][0].second; v != -1; v = par[v][1].first) {
                which[v] = len(ends) - 1;
                used[v] = 1;
                ends.back().second = v;
            }
        }
        y_combinator([&](auto dfs, int v) -> void {
            for (auto u : g[v]) {
                if (u == pre[v]) continue;
                dfs(u);
                if (which[u] != which[v]) {
                    cout << v + 1 << ' ' << u + 1 << ' ' << ends[which[v]].first + 1 << ' ' << ends[which[u]].first + 1 << '\n';
                    ends[which[v]].first = ends[which[u]].second;
                }
            }
        })(0);
    }
};

inline void solve() {
    int n;
    cin >> n;
    graph g(n);
    g.read();
    g.solve();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}