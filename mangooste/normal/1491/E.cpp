#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

#define prev prevv

int n;
vec<pr<int>> edges;
vec<vec<pr<int>>> g;
vec<char> used;
vec<int> sz;
vec<int> prev;

void init(int v, int par) {
    sz[v] = 1;
    for (auto [u, i] : g[v])
        if (u != par && !used[i]) {
            init(u, v);
            sz[v] += sz[u];
        }
}

int find(int v, int par, int n) {
    for (auto [u, i] : g[v])
        if (u != par && !used[i]) {
            if (sz[u] == prev[n] || sz[u] == n - prev[n])
                return i;
            int cur = find(u, v, n);
            if (cur != -1)
                return cur;
        }
    return -1;
}

bool solve(int v) {
    init(v, v);
    if (sz[v] == 1)
        return true;
    int e = find(v, v, sz[v]);
    if (e == -1)
        return false;
    used[e] = 1;
    return solve(edges[e].first) && solve(edges[e].second);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        edges.emplace_back(v, u);
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }

    prev.resize(n + 1);
    int f1 = 1, f2 = 1;
    while (f2 <= n) {
        prev[f2] = f1;
        f2 += f1;
        f1 = f2 - f1;
    }

    used.resize(n - 1);
    sz.resize(n);
    cout << (solve(0) ? "Yes\n" : "No\n");
}