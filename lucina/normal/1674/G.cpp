#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
vector <int> g[nax];
int n, m;
int dp[nax];
int in[nax];
int out[nax];
/**
    dp[x] is the maximum path size if starting at x
    and the following children have at least
    1 outgoing and 1 incoming edges
    outside the path
*/

int calc(int v) {
    if (dp[v] != -1) return dp[v];
    dp[v] = 1;
    for (int to : g[v]) {
        calc(to);
        if (out[v] >= 2 && in[to] >= 2) {
            dp[v] = max(dp[v], dp[to] + 1);
        }
    }
    return dp[v];
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1, u, v ; i <= m ; ++ i) {
        cin >> u >> v;
        out[u] += 1;
        in[v] += 1;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        calc(i);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

}