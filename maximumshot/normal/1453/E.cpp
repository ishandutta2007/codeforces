#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void read(int& n, vector<pii>& edges) {
    cin >> n;
    edges.resize(n - 1);
    for (int u, v, i = 0; i < n - 1; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
    }
}

int fast(int n, vector<pii> edges) {
    vector<vector<int>> g(n + 1);
    for (auto [u, v] : edges)
        g[u].push_back(v), g[v].push_back(u);
    vector<int> f(n + 1, inf), d(n + 1);
    int res = 0;
    function<void(int, int)> dfs = [&](int v, int par) {
        d[v] = par == -1 ? 0 : d[par] + 1;
        int child = 0;
        int mx = 0;
        for (int to : g[v]) {
            if (to == par)
                continue;
            dfs(to, v);
            f[v] = min(f[v], f[to]);
            mx = max(mx, f[to]);
            child++;
        }
        if (child == 0) {
            f[v] = d[v];
        } else if (child >= 2) {
            if (v > 1) {
                res = max(res, mx - d[v] + 1);
            } else {
                int mx1 = 0, mx2 = 0;
                for (int to : g[v]) {
                    if (to == par)
                        continue;
                    if (f[to] > mx1)
                        mx2 = mx1, mx1 = f[to];
                    else if (f[to] > mx2)
                        mx2 = f[to];
                }
                res = min(
                    max(res, mx1 - d[v] + 1),
                    max({res, mx2 - d[v] + 1, mx1})
                );
            }
        } else if (v == 1) {
            res = max(res, f[v]);
        }
    };
    dfs(1, -1);
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<pii> edges;
        read(n, edges);
        int fs = fast(n, edges);
        cout << fs << "\n";
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