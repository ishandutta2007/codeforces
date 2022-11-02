#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int MOD = 1e9 + 7;

int n, x[MAXN], dp[MAXN][2];
vector<int> adj[MAXN];

int exp(int b, int e) {
    if (!e) return 1;
    if (e&1) return ll(b)*exp(b, e-1)%MOD;
    int res = exp(b, e/2);
    return ll(res)*res%MOD;
}

void dfs(int cur) {
    if (x[cur]) {
        dp[cur][1] = 1;
        for (int i=0; i<adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            dfs(nxt);
            dp[cur][1] = ll(dp[cur][1])*((dp[nxt][0]+dp[nxt][1])%MOD)%MOD;
        }
    } else {
        int sum = 0;
        dp[cur][0] = 1;
        for (int i=0; i<adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            dfs(nxt);
            dp[cur][0] = ll(dp[cur][0])*((dp[nxt][0]+dp[nxt][1])%MOD)%MOD;
            sum = (sum+ll(dp[nxt][1])*exp((dp[nxt][0]+dp[nxt][1])%MOD, MOD-2)%MOD)%MOD;
        }
        dp[cur][1] = ll(dp[cur][0])*sum%MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    for (int i=0; i<n; i++) cin >> x[i];

    dfs(0);
    cout << dp[0][1] << '\n';
}