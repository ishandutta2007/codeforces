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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n + 1);
        for (int u, v, i = 0; i < m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> u(n + 1, -1);
        u[1] = 1;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (u[v] == 1) {
                for (int to : g[v]) {
                    if (u[to] == -1) {
                        u[to] = 0;
                        q.push(to);
                    }
                }
            } else {
                for (int to : g[v]) {
                    if (u[to] == -1) {
                        int ok = 1;
                        for (int x : g[to]) {
                            if (u[x] == 1)
                                ok = 0;
                        }
                        u[to] = ok;
                        q.push(to);
                    }
                }
            }
        }
        if (count(u.begin() + 1, u.end(), -1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> res;
            for (int v = 1; v <= n; v++) {
                if (u[v] == 1)
                    res.push_back(v);
            }
            cout << (int) res.size() << "\n";
            for (int v : res)
                cout << v << " ";
            cout << "\n";
        }
    }

    return 0;
}