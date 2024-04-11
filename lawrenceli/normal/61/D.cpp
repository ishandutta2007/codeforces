#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100100;

int n;
vector<pii> adj[MAXN];
ll dp[MAXN][2];

void dfs(int cur, int p) {
    ll imin = 0;

    for (int i=0; i<adj[cur].size(); i++) {
        pii nxt = adj[cur][i];
        if (nxt.fi == p) continue;
        dfs(nxt.fi, cur);
        dp[cur][0] += 2*nxt.se + dp[nxt.fi][0];
        imin = min(imin, dp[nxt.fi][1] - dp[nxt.fi][0] - nxt.se);
    }

    dp[cur][1] = dp[cur][0] + imin;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back(pii(y, w));
        adj[y].push_back(pii(x, w));
    }

    dfs(0, 0);

    cout << dp[0][1] << '\n';
    return 0;
}