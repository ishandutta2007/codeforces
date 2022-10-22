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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n + 1, vector<int>(2));
        for (int i = 1; i <= n; i++)
            cin >> a[i][0] >> a[i][1];

        vector<vector<int>> g(n + 1);
        for (int u, v, i = 0; i < n - 1; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        function<void(int, int)> dfs = [&](int v, int par) {
            for (int to : g[v]) {
                if (to == par)
                    continue;
                dfs(to, v);
            }
            for (int x = 0; x < 2; x++) {
                for (int to : g[v]) {
                    if (to == par)
                        continue;
                    ll mx = 0;
                    for (int y = 0; y < 2; y++) {
                        mx = max(mx, dp[to][y] + abs(a[v][x] - a[to][y]));
                    }
                    dp[v][x] += mx;
                }
            }
        };
        dfs(1, -1);

        cout << max(dp[1][0], dp[1][1]) << "\n";
    }

    return 0;
}