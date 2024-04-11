#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Edge {
    int u = 0;
    int v = 0;
    int aux = 0;

    int get_to(int x) const {
        return u == x ? v : u;
    }
};

vector<int> find_max_matching(int n, vector<Edge> edges, vector<vector<int>> g) {
    vector<vector<int>> dp(n + 1, vector<int>(2));
    vector<int> used(n + 1);
    function<void(int, int)> dfs = [&](int v, int par) {
        used[v] = 1;
        for (int eid : g[v]) {
            auto e = edges[eid];
            int to = e.get_to(v);
            if (to == par)
                continue;
            dfs(to, v);
            dp[v][0] += max(dp[to][0], dp[to][1]);
        }
        for (int eid : g[v]) {
            auto e = edges[eid];
            int to = e.get_to(v);
            if (to == par)
                continue;
            dp[v][1] = max(dp[v][1], 1 + dp[to][0] + dp[v][0] - max(dp[to][0], dp[to][1]));
        }
    };
    vector<int> matching;
    function<void(int, int, int)> go = [&](int v, int par, int in) {
        if (!in) {
            for (int eid : g[v]) {
                auto e = edges[eid];
                int to = e.get_to(v);
                if (to == par)
                    continue;
                go(to, v, dp[to][0] < dp[to][1] ? 1 : 0);
            }
        } else {
            int best = -1, best_value = 0;
            for (int eid : g[v]) {
                auto e = edges[eid];
                int to = e.get_to(v);
                if (to == par)
                    continue;
                int tmp_value = 1 + dp[to][0] + dp[v][0] - max(dp[to][0], dp[to][1]);
                if (best == -1 || best_value < tmp_value) {
                    best = to;
                    best_value = tmp_value;
                }
            }
            for (int eid : g[v]) {
                auto e = edges[eid];
                int to = e.get_to(v);
                if (to == par)
                    continue;
                if (to == best) {
                    matching.push_back(eid);
                    go(to, v, 0);
                } else {
                    go(to, v, dp[to][0] < dp[to][1] ? 1 : 0);
                }
            }
        }
    };
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            dfs(v, -1);
            go(v, -1, dp[v][0] < dp[v][1] ? 1 : 0);
        }
    }
    return matching;
}

vector<pii> fast(int n, vector<Edge> edges) {
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < (int) edges.size(); i++) {
        auto e = edges[i];
        g[e.u].push_back(i);
        g[e.v].push_back(i);
    }
    vector<int> used(n + 1), tin(n + 1), fup(n + 1), is_bridge(edges.size());
    int timer = 0;
    function<void(int, int)> dfs = [&](int v, int from) {
        used[v] = 1;
        tin[v] = fup[v] = timer++;
        for (int eid : g[v]) {
            auto e = edges[eid];
            int to = e.get_to(v);
            if (to == from)
                continue;
            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
            } else {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (tin[v] < fup[to])
                    is_bridge[eid] = 1;
            }
        }
    };
    dfs(1, -1);
    vector<int> deg(n + 1);
    for (int v = 1; v <= n; v++) {
        for (int eid : g[v]) {
            if (!is_bridge[eid])
                continue;
            deg[v]++;
        }
    }
    vector<vector<int>> forest(n + 1), M(n + 1);
    for (int v = 1; v <= n; v++) {
        for (int eid : g[v]) {
            if (!is_bridge[eid])
                continue;
            int to = edges[eid].get_to(v);
            if (deg[v] % 2 == 1 && deg[to] % 2 == 1)
                M[v].push_back(eid);
        }
    }
    vector<int> matching = find_max_matching(n, edges, M);
    vector<int> in_matching(edges.size());
    for (int eid : matching)
        in_matching[eid] = 1;
    for (int v = 1; v <= n; v++) {
        for (int eid : g[v]) {
            if (!is_bridge[eid] || in_matching[eid])
                continue;
            forest[v].push_back(eid);
        }
    }
    for (int cur = -1, v = 1; v <= n; v++) {
        if ((int) forest[v].size() % 2) {
            if (cur == -1) {
                cur = v;
            } else {
                Edge e = {cur, v, 1};
                forest[v].push_back((int) edges.size());
                forest[cur].push_back((int) edges.size());
                edges.push_back(e);
                cur = -1;
            }
        }
    }
    vector<Edge> euler;
    vector<int> del(edges.size());
    function<void(int, int)> go = [&](int v, int from) {
        while (!forest[v].empty()) {
            int eid = forest[v].back();
            forest[v].pop_back();
            if (del[eid])
                continue;
            del[eid] = 1;
            auto e = edges[eid];
            int to = e.get_to(v);
            go(to, eid);
        }
        if (from != -1) {
            auto e = edges[from];
            if (e.u != v)
                swap(e.u, e.v);
            euler.push_back(e);
        }
    };
//    cout << "\n";
//    for (int v = 1; v <= n; v++) {
//        for (int eid : forest[v]) {
//            cout << v << " " << edges[eid].get_to(v) << "\n";
//        }
//    }
//    cout << "\n";
    vector<pii> res;
    for (int v = 1; v <= n; v++) {
        if (forest[v].empty())
            continue;
        euler.clear();
        go(v, -1);
//        for (auto e : euler) {
//            cout << "(" << e.u << " -> " << e.v << ") ";
//        }
//        cout << "\n";
        for (int it = 0; it + 1 < (int) euler.size(); it++) {
            if (euler[it].aux) {
                rotate(euler.begin(), euler.begin() + it + 1, euler.end());
                break;
            }
        }
        for (int last = euler[0].u, it = 0; it < (int) euler.size(); it++) {
            auto e = euler[it];
            if (e.aux) {
                if (last != e.u)
                    res.emplace_back(last, e.u);
                last = e.v;
            }
        }
    }
    return res;
}

void work() {
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        vector<Edge> edges;
        for (int iter = 0; iter < m; iter++) {
            int sz;
            cin >> sz;
            for (int v = 0, u, i = 0; i < sz; i++) {
                cin >> u;
                if (i > 0)
                    edges.push_back(Edge{v, u, 0});
                v = u;
            }
        }
        vector<pii> fs = fast(n, edges);
        cout << (int) fs.size() << "\n";
        for (auto [u, v] : fs)
            cout << u << " " << v << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}