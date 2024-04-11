#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int mod = 998244353;

int pw2[Maxn];
int n;
vector <int> neigh[Maxn];
int sz[Maxn];
int dp[Maxn][2];
int res;

void Traverse(int v, int p)
{
    sz[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        sz[v] += sz[u];
        int all = (dp[u][0] + dp[u][1]) % mod;
        dp[u][0] = (dp[u][0] + all) % mod;
    }
    dp[v][0] = dp[v][1] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        dp[v][1] = ll(dp[v][1]) * dp[u][0] % mod;
        dp[v][0] = ll(dp[v][0]) * (dp[u][0] + dp[u][1]) % mod;
    }
    dp[v][0] = (dp[v][0] - dp[v][1] + mod) % mod;
    res = (res + ll(dp[v][0]) * pw2[n - sz[v]]) % mod;
}

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    res = 2ll * res % mod;
    cout << res << endl;
    return 0;
}