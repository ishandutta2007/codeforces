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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        adj[i].push_back(-1);
        adj[i].push_back(n);
        sort(all(adj[i]));
    }

    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i);

    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
        if (st.count(i))
            y_combinator([&](auto dfs, int v) -> void {
                st.erase(v);
                for (int i = 1; i < len(adj[v]); i++) {
                    int left = adj[v][i - 1] + 1;
                    int right = adj[v][i];
                    while (true) {
                        auto it = st.lower_bound(left);
                        if (it == st.end() || *it >= right)
                            break;

                        g[v].push_back(*it);
                        g[*it].push_back(v);
                        dfs(*it);
                    }
                }
            })(i);

    vector<int> p(n, -1);
    vector<int> q(n, -1);
    int current = 1;

    vector<int> deg(n);
    vector<int> que;
    que.reserve(n);
    for (int i = 0; i < n; i++) {
        deg[i] = len(g[i]);
        if (deg[i] == 1)
            que.push_back(i);
    }

    for (int st = 0; st < len(que); st++) {
        int v = que[st];
        if (p[v] != -1)
            continue;

        int u = -1;
        for (auto w : g[v])
            if (p[w] == -1) {
                assert(u == -1);
                u = w;
            }

        p[u] = current;
        for (auto w : g[u])
            if (p[w] == -1) {
                if (deg[w] == 1) {
                    q[w] = current++;
                    p[w] = current;
                }
                if (--deg[w] == 1)
                    que.push_back(w);
            }

        q[u] = current++;
    }

    for (int i = 0; i < n; i++)
        if (p[i] == -1)
            p[i] = q[i] = current++;

    for (int i = 0; i < n; i++)
        cout << p[i] << " \n"[i == n - 1];

    for (int i = 0; i < n; i++)
        cout << q[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}