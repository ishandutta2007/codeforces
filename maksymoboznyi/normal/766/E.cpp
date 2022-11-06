#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int L = 30;

int ans = 0;
int n, dp[N][L], a[N], go[N][L][2];
vector<int> g[N];

void dfs(int v, int p = -1) {
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p)
            dfs(g[v][i], v);
    for (int b = 0; b < 27; b++) {
        dp[v][b] = 0;
        int k0 = 1, k1 = 0;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (to != p)
                k0 += go[to][b][0], k1 += go[to][b][1];
        }
        if ((a[v] >> b) & 1) {
            go[v][b][0] = k1;
            go[v][b][1] = k0;
        } else {
            go[v][b][0] = k0;
            go[v][b][1] = k1;
        }
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (to != p)
            {
                k0 -= go[to][b][0];
                k1 -= go[to][b][1];
                if ((a[v] >> b) & 1)
                    dp[v][b] += go[to][b][0] * k0 + go[to][b][1] * k1;
                else
                    dp[v][b] += go[to][b][0] * k1 + go[to][b][1] * k0;
            }
        }
        if ((a[v] >> b) & 1)
            dp[v][b]++;
        ans += dp[v][b] * (1 << b);
    }

}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    cout << ans;
    return 0;
}