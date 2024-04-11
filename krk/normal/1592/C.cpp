#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];
vector <int> neigh[Maxn];
int xr[Maxn];
int dp[Maxn][2];
int nd;

void Traverse(int v, int p)
{
    xr[v] = a[v];
    dp[v][0] = 0, dp[v][1] = -Maxn;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        xr[v] ^= xr[u];
        int n0 = max(dp[v][0] + dp[u][0], dp[v][1] + dp[u][1]);
        int n1 = max(dp[v][0] + dp[u][1], dp[v][1] + dp[u][0]);
        dp[v][0] = n0;
        dp[v][1] = n1;
    }
    int n0 = dp[v][0], n1 = dp[v][1];
    if (xr[v] == nd) n1 = max(n1, dp[v][0] + 1);
    else if (xr[v] == 0) n0 = max(n0, dp[v][1] + 1);
    dp[v][0] = n0;
    dp[v][1] = n1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        nd = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            nd ^= a[i];
            neigh[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        if (nd == 0) {
            printf("YES\n");
            continue;
        }
        Traverse(1, 0);
        printf("%s\n", dp[1][1] >= 3 && k >= 3? "YES": "NO");
    }
    return 0;
}