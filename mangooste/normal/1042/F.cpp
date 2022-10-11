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

    int root = 0;
    while (len(g[root]) == 1)
        root++;

    vector<int> depth(n);
    int answer = 0;

    y_combinator([&](auto dfs, int v) -> int {
        if (g[v].empty())
            return depth[v];

        int limit = k + 2 * depth[v];
        vector<int> current;
        current.reserve(len(g[v]));

        for (auto u : g[v]) {
            depth[u] = depth[v] + 1;
            g[u].erase(find(all(g[u]), v));
            current.push_back(dfs(u));
        }

        sort(all(current));
        int when = 0;
        while (when + 1 < len(current) && current[when] + current[when + 1] <= limit)
            when++;

        answer += len(current) - when - 1;
        return current[when];
    })(root);

    cout << answer + 1 << '\n';
}