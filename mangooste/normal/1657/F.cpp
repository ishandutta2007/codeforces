#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

#ifdef LOCAL
constexpr int N = 228;
#else
constexpr int N = 4e5 + 228;
#endif
constexpr int A = 26, V = 2 * N + 4 * N;

vector<int> tree[N];
int dep[N], par[N];
vector<char> good[N];

vector<int> g[V], ig[V];
bool used[V];
int scc_num[V];

void add_edge(int from, int to) {
    g[from].push_back(to);
    ig[to].push_back(from);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    
    y_combinator([&](auto dfs, int v) -> void {
        for (auto u : tree[v]) {
            tree[u].erase(find(all(tree[u]), v));
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs(u);
        }
    })(0);

    auto get_path = [&](int from, int to) {
        vector<int> left, right;
        for (; dep[from] > dep[to]; from = par[from]) {
            left.push_back(from);
        }
        for (; dep[to] > dep[from]; to = par[to]) {
            right.push_back(to);
        }

        while (from != to) {
            left.push_back(from);
            from = par[from];
            right.push_back(to);
            to = par[to];
        }
        left.push_back(from);

        reverse(all(right));
        for (auto x : right) left.push_back(x);
        return left;
    };

    struct info {
        int from, to;
        string s;
        vector<int> path;
    };
    vector<info> queries(q);
    for (auto &[from, to, s, path] : queries) {
        cin >> from >> to >> s;
        from--, to--;
        path = get_path(from, to);
        assert(len(path) == len(s));

        for (int rot = 0; rot < 2; rot++, reverse(all(path))) {
            for (int pos = 0; pos < len(path); pos++) {
                good[path[pos]].push_back(s[pos]);
            }
        }
    }

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        sort(all(good[i]));
        good[i].resize(unique(all(good[i])) - good[i].begin());
        pref[i + 1] = pref[i] + len(good[i]);
    }

    for (int i = 0; i < q; i++) {
        for (int rot = 0; rot < 2; rot++, reverse(all(queries[i].path))) {
            for (int pos = 0; pos < len(queries[i].path); pos++) {
                int v = queries[i].path[pos];
                int cur_c = lower_bound(all(good[v]), queries[i].s[pos]) - good[v].begin();
                add_edge(2 * N + pref[v] + cur_c, (i << 1) ^ rot);
                add_edge((i << 1) ^ rot ^ 1,  2 * N + pref.back() + pref[v] + cur_c);
                for (int c = 0; c < len(good[v]); c++) {
                    if (cur_c == c) continue;
                    add_edge((i << 1) ^ rot ^ 1, 2 * N + pref[v] + c);
                    add_edge(2 * N + pref.back() + pref[v] + c, (i << 1) ^ rot);
                }
            }
        }
    }

    vector<int> ord;
    ord.reserve(V);
    fill(all(used), false);
    for (int v = 0; v < V; v++) {
        if (used[v]) continue;
        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            for (auto u : g[v]) {
                if (!used[u]) dfs(u);
            }
            ord.push_back(v);
        })(v);
    }
    reverse(all(ord));

    fill(all(used), false);
    int cur = 0;
    for (auto v : ord) {
        if (used[v]) continue;
        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            scc_num[v] = cur;
            for (auto u : ig[v]) {
                if (!used[u]) dfs(u);
            }
        })(v);
        cur++;
    }

    string ans(n, 'a');
    for (int i = 0; i < q; i++) {
        if (scc_num[i << 1] > scc_num[i << 1 | 1]) {
            reverse(all(queries[i].path));
        }
        for (int pos = 0; pos < len(queries[i].path); pos++) {
            ans[queries[i].path[pos]] = queries[i].s[pos];
        }
    }
    for (auto &[from, to, s, path] : queries) {
        for (int pos = 0; pos < len(path); pos++) {
            if (ans[path[pos]] != s[pos]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    cout << ans << '\n';
}