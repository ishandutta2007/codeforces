#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        for (int u, v, i = 1; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> pr(n + 1, -1), depth(n + 1), sons(n + 1);
        function<void(int, int)> dfs = [&](int v, int par) {
            pr[v] = par;
            depth[v] = par == -1 ? 0 : depth[par] + 1;
            for (int to : g[v]) {
                if (to == par)
                    continue;
                sons[v]++;
                dfs(to, v);
            }
        };
        dfs(1, -1);
        set<pii> Q;
        for (int v = 2; v <= n; v++) {
            if ((int) g[v].size() == 1)
                Q.insert({depth[v], v});
        }
        vector<int> del(n + 1);
        int cnt = 0, sm = 0;
        while (!Q.empty()) {
            int leaf = (--Q.end())->second;
            Q.erase(--Q.end());
            int v = pr[leaf];
            if (v < 1)
                break;
            cnt++;
            sm += sons[v];
            if (v == 1)
                break;
            del[v] = 1;
            for (int to : g[v]) {
                if (to == pr[v] || del[to])
                    continue;
                del[to] = 1;
                Q.erase({depth[to], to});
            }
            int u = pr[v];
            sons[u]--;
            if (sons[u] == 0)
                Q.insert({depth[u], u});
        }
        cout << sm - (cnt - 1) << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}