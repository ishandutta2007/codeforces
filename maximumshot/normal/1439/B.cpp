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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<unordered_set<int>> g(n + 1);
    for (int u, v, i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    set<pii> q;
    for (int v = 1; v <= n; v++) {
        q.insert({(int) g[v].size(), v});
    }

    while (!q.empty() && q.begin()->first < k) {
        int v = q.begin()->second;

        if ((int) g[v].size() == k - 1) {
            vector<int> clique = {v};
            for (auto x : g[v])
                clique.push_back(x);
            int ok = 1;
            for (int v1 : clique) {
                for (int v2 : clique) {
                    if (v1 >= v2)
                        continue;
                    if (!g[v1].count(v2)) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                    break;
            }
            if (ok) {
                cout << 2 << "\n";
                for (int x : clique)
                    cout << x << " ";
                cout << "\n";
                return;
            }
        }

        q.erase(q.begin());
        for (int to : g[v]) {
            q.erase({(int) g[to].size(), to});
            g[to].erase(v);
            q.insert({(int) g[to].size(), to});
        }
        g[v].clear();
    }

    if (!q.empty()) {
        cout << 1 << " " << (int) q.size() << "\n";
        for (auto u : q)
            cout << u.second << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}