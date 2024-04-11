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

int fast(int n, int m, vector<int> a, vector<int> b, vector<pii> edges) {
    vector<vector<pii>> g(n + 1);
    int eid = 0;
    for (auto [u, v] : edges) {
        g[u].emplace_back(v, eid++);
        g[v].emplace_back(u, eid++);
    }
    auto check = [&](ll x) -> bool {
        vector<int> used(n + 1);
        used[1] = 1;
        while (count(used.begin() + 1, used.end(), 0)) {
            vector<int> was(eid), on_path(n + 1);
            vector<int> path;
            function<bool(int, int, ll)> dfs = [&](int v, int e, ll power) -> bool {
                power += b[v];
                was[e] = 1;
                path.push_back(v); on_path[path.back()] = 1;
                for (auto [to, ne] : g[v]) {
                    if ((ne ^ e) == 1)
                        continue;
                    if (used[to] || on_path[to])
                        return true;
                }
                for (auto [to, ne] : g[v]) {
                    if ((ne ^ e) == 1 || was[ne])
                        continue;
                    if (power > a[to] && dfs(to, ne, power))
                        return true;
                }
                on_path[path.back()] = 0; path.pop_back();
                return false;
            };
            int any = 0;
            for (int s = 1; s <= n && !any; s++) {
                if (!used[s])
                    continue;
                for (auto [to, e] : g[s]) {
                    if (used[to] || was[e] || x <= a[to])
                        continue;
                    path.clear();
                    if (dfs(to, e, x)) {
                        any = 1;
                        break;
                    }
                }
            }
            if (!any)
                return false;
            for (int v : path) {
                used[v] = 1;
                x += b[v];
            }
        }
        return true;
    };
    int bl = 0, br = inf + 10, bm;
    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        if (check(bm)) br = bm;
        else bl = bm;
    }
    return br;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 2; i <= n; i++)
            cin >> a[i];
        for (int i = 2; i <= n; i++)
            cin >> b[i];
        vector<pii> edges(m);
        for (auto& [u, v] : edges)
            cin >> u >> v;
        int res = fast(n, m, a, b, edges);
        cout << res << "\n";
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