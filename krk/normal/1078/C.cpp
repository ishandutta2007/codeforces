#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int mod = 998244353;

int n;
vector <int> neigh[Maxn];
int dp[Maxn][3];

void Traverse(int v, int p)
{
    int w0 = 1, w1 = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        int waysignore = (2ll * ll(dp[u][0]) + ll(dp[u][1])) % mod;
        int waystake = (dp[u][1] + dp[u][2]) % mod;
        int nw0 = ll(w0) * waysignore % mod;
        int nw1 = (ll(w1) * waysignore + ll(w0) * waystake) % mod;
        w0 = nw0; w1 = nw1;
    }
    dp[v][0] = w1;
    w0 = 1, w1 = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        int waysignore = (dp[u][0] + dp[u][1]) % mod;
        int waystake = dp[u][0];
        int nw0 = ll(w0) * waysignore % mod;
        int nw1 = (ll(w1) * (waysignore + waystake) + ll(w0) * waystake) % mod;
        w0 = nw0; w1 = nw1;
    }
    dp[v][1] = w0; dp[v][2] = w1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    printf("%d\n", (dp[1][0] + dp[1][1]) % mod);
    return 0;
}