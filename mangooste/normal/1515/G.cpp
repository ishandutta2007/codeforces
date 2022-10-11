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
    const Fun _fun;
public:
    explicit y_combinator(const Fun&& fun) : _fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    inline decltype(auto) operator()(Args&&... args) const {
        return _fun(std::ref(*this), std::forward<Args>(args)...);
    }
};


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<pair<int, int>>> rev_g(n);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].emplace_back(u, w);
        rev_g[u].emplace_back(v, w);
    }

    vector<char> used(n);
    vector<int> order;

    for (int i = 0; i < n; i++)
        if (!used[i])
            y_combinator([&](auto dfs, int v) -> void {
                used[v] = 1;
                for (const auto [u, l] : g[v])
                    if (!used[u])
                        dfs(u);

                order.push_back(v);
            })(i);

    reverse(all(order));
    vector<int> which(n, -1);
    int current = 0;

    for (auto v : order)
        if (which[v] == -1) {
            y_combinator([&](auto dfs, int v) -> void {
                which[v] = current;
                for (const auto [u, l] : rev_g[v])
                    if (which[u] == -1)
                        dfs(u);
            })(v);
            current++;
        }

    vector<ll> data(n);
    vector<ll> dist(n, -1);

    for (int i = 0; i < n; i++)
        if (dist[i] == -1) {
            dist[i] = 0;
            y_combinator([&](auto dfs, int v) -> void {
                for (const auto [u, w] : g[v]) {
                    if (which[u] != which[v])
                        continue;

                    if (dist[u] == -1) {
                        dist[u] = dist[v] + w;
                        dfs(u);
                    } else {
                        data[which[v]] = gcd(data[which[v]], abs(dist[v] + w - dist[u]));
                    }
                }
            })(i);
        }

    dbg(which);
    dbg(data);

    int q;
    cin >> q;
    while (q--) {
        int v, s, t;
        cin >> v >> s >> t;
        v--, s = (t - s) % t;
        cout << (s % gcd(data[which[v]], t) == 0 ? "YES" : "NO") << '\n';
    }
}