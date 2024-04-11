#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].pb(u);
        G[u].pb(v);
    }
    vector<int> sz(n, 0);
    vector<ll> dp(n, 0);
    Fun<void(int, int)> Calc = [&](int v, int pr) {
        sz[v] = 1;
        for (auto u : G[v]) {
            if (u != pr) {
                Calc(u, v);
                sz[v] += sz[u];
                dp[v] += dp[u];
            }
        }
        dp[v] += sz[v];
    };
    Calc(0, 0);
    ll ans = 0;
    Fun<void(int, int)> Dfs = [&](int v, int pr) {
        ans = max(ans, dp[v]);
        for (auto u : G[v]) {
            if (u != pr) {
                sz[v] -= sz[u];
                dp[v] -= sz[u] + dp[u];
                sz[u] += sz[v];
                dp[u] += dp[v] + sz[v];
                Dfs(u, v);
                dp[u] -= dp[v] + sz[v];
                sz[u] -= sz[v];
                dp[v] += sz[u] + dp[u];
                sz[v] += sz[u];
            }
        }
    };
    Dfs(0, 0);
    cout << ans << '\n';
}