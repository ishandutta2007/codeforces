#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> table(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
            table[i][j] -= i + j;
        }
    const ll INF = 2e18;

    auto get_dp = [&](ll val) {
        vector<vector<ll>> dp(n, vector<ll>(m, INF));
        if (table[0][0] < val)
            return INF;
        dp[0][0] = table[0][0] - val;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i + j == 0 || table[i][j] < val)
                    continue;
                ll del = table[i][j] - val;
                ll frm = INF;
                if (j != 0)
                    frm = min(frm, dp[i][j - 1]);
                if (i != 0)
                    frm = min(frm, dp[i - 1][j]);
                if (frm != INF)
                    dp[i][j] = frm + del;
            }
        return dp[n - 1][m - 1];
    };

    ll ans = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = min(ans, get_dp(table[i][j]));
    assert(ans != INF);
    cout << ans << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}