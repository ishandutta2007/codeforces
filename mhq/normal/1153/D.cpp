#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int tp[maxN];
vector < int > g[maxN];
int deg[maxN];
int n;
int dp[maxN];
int le = 0;
const int INF = (int)1e9;
void dfs(int v) {
    for (int to : g[v]) dfs(to);
    if (deg[v] == 0) {
        dp[v] = 1;
    }
    else {
        if (tp[v] == 0) {
            dp[v] = 0;
            for (int to : g[v]) {
                dp[v] += dp[to];
            }
        }
        else {
            dp[v] = dp[g[v][0]];
            for (int to : g[v]) {
                dp[v] = min(dp[v], dp[to]);
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tp[i];
    }
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        deg[x]++;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) le++;
    }
    for (int i = 1; i <= n; i++) dp[i] = INF;
    dfs(1);
    cout << le + 1 - dp[1];
    return 0;
}