#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

//#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

vector<vector<int>> G;
vector<int> col, dp, ans;

void dfs1(int v, int pr) {
    dp[v] = col[v];
    for (int u : G[v]) if (u != pr) {
        dfs1(u, v);
        dp[v] += max(0, dp[u]);
    }
    // dp[v] = max(0, dp[v]);
}

void dfs2(int v, int pr, int mxCan) {
    ans[v] = dp[v] + mxCan;
    int cur = col[v] + mxCan;
    for (int u : G[v]) if (u != pr) cur += max(0, dp[u]);
    for (int u : G[v]) if (u != pr) dfs2(u, v, max(0, cur - max(0, dp[u])));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    col.resize(n);
    forn(i, n) cin >> col[i];
    forn(i, n) if (col[i] == 0) col[i] = -1;
    G.resize(n);
    forn(i, n - 1) {
        int v, u;
        cin >> v >> u, v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dp.resize(n);
    dfs1(0, 0);
    // forn(i, n) cout << dp[i] << ' '; cout << '\n';
    ans.resize(n);
    dfs2(0, 0, 0);
    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';
}