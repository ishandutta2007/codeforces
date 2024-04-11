#include <bits/stdc++.h>
using namespace std;

const int N = 400005, Q = 400005;

int n, q, par[N], h[N];
char can[N][2], s[N];
vector<int> adj[N];

struct two_sat {
    int n;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    two_sat(int _n) {
        n = _n;
        adj.resize(n); adj_t.resize(n);
    }

    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2*a ^ na;
        b = 2*b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

void DFS(int u, int p = 0) {
    par[u] = p;
    h[u] = h[p] + 1;
    for (int v : adj[u]) {
        if (v != p) {
            DFS(v, u);
        }
    }
}

vector<pair<char, int>> walk(int u, int v, string &s) {
    vector<pair<char, int>> ans;
    int l = 0, r = s.size() - 1;
    if (h[u] < h[v]) {
        swap(u, v);
    }
    while (h[u] > h[v]) {
        ans.push_back({s[l++], u}); u = par[u];
    }
    while (u != v) {
        ans.push_back({s[l++], u}); u = par[u];
        ans.push_back({s[r--], v}); v = par[v];
    }
    ans.push_back({s[l], u});
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        can[i][0] = can[i][1] = 'a';
        s[i] = 'a';
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    vector<tuple<int, bool, int, char>> vec;
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        string s; cin >> s;
        vector<pair<char, int>> tfi = walk(u, v, s);
        reverse(s.begin(), s.end());
        vector<pair<char, int>> tse = walk(u, v, s);
        for (int j = 0; j < tfi.size(); j++) {
            int u = tfi[j].second;
            can[u][0] = tfi[j].first; can[u][1] = tse[j].first;
            vec.push_back({i + n, false, u, can[u][0]});
            vec.push_back({i + n, true, u, can[u][1]});
        }
    }
    two_sat solver(2 * (n + q + 5));
    for (auto [a, na, b, c] : vec) {
        for (int nb = 0; nb <= 1; nb++) {
            if (c != can[b][nb]) {
                solver.add_disjunction(a, na, b, 1 - nb);
            }
        }
    }
    if (solver.solve_2SAT()) {
        cout << "YES\n";
        for (auto [a, na, b, c] : vec) {
            if (na == solver.assignment[a]) {
                s[b] = c;
            }
        }
        cout << (s + 1) << '\n';
    } else {
        cout << "NO\n";
    }
}