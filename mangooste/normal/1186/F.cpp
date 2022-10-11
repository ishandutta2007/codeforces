#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int n, m;
vec<pr<int>> edges;
vec<vec<int>> g;
vec<int> head;
vec<char> used;
vec<int> cycle;

inline int another(int i, int v) {
    return edges[i].first ^ edges[i].second ^ v;
}

void dfs(int v, int par) {
    for (; head[v] < len(g[v]); head[v]++) {
        int i = g[v][head[v]];
        if (used[i])
            continue;
        used[i] = 1;
        int u = another(i, v);
        dfs(u, i);
    }
    if (par != -1)
        cycle.push_back(par);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(i);
        g[u].push_back(i);
        edges.emplace_back(v, u);
    }
    for (int i = 0; i < n; i++)
        if (len(g[i]) % 2) {
            g[i].push_back(m);
            g[n].push_back(m);
            m++;
            edges.emplace_back(i, n);
        }

    head.resize(n + 1);
    used.resize(m);
    vec<pr<int>> ans;
    for (int i = 0; i < n; i++)
        if (!head[i]) {
            cycle.clear();
            dfs(i, -1);
            if (!len(cycle))
                continue;
            if (len(cycle) % 2)
                cycle.push_back(cycle[0]);
            for (auto i : cycle)
                used[i] = 0;
            for (int i = 1; i < len(cycle); i += 2)
                if (edges[cycle[i]].first < n && edges[cycle[i]].second < n) {
                    ans.push_back(edges[cycle[i]]);
                    used[cycle[i]] = 1;
                }
            for (int i = 1; i < len(cycle); i += 2)
                if (edges[cycle[i]].first == n || edges[cycle[i]].second == n) {
                    int v = edges[cycle[i]].first;
                    if (v == n)
                        v = edges[cycle[i]].second;
                    for (auto num : g[v])
                        if (!used[num]) {
                            int u = another(num, v);
                            if (u == n)
                                continue;
                            used[num] = 1;
                            ans.emplace_back(v, u);
                            break;
                        }
                }
        }

    assert(len(ans) <= (n + m + 1) / 2);
    cout << len(ans) << '\n';
    for (auto [v, u] : ans)
        cout << v + 1 << ' ' << u + 1 << '\n';
}