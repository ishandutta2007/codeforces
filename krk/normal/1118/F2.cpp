#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;
const int mod = 998244353;

int n, k;
int a[Maxn];
vector <int> neigh[Maxn];
int P[Maxn], L[Maxn];
set <ii> S[Maxn];
int dp[Maxn][2];
int res;

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        P[u] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
}

void Solve(int v, int p)
{
    if (a[v] > 0) { dp[v][0] = 0, dp[v][1] = 1; return; }
    dp[v][0] = 1, dp[v][1] = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v);
        int ways0 = ll(dp[v][0]) * (ll(dp[u][0]) + ll(dp[u][1])) % mod;
        int ways1 = (ll(dp[v][0]) * ll(dp[u][1]) + ll(dp[v][1]) * (ll(dp[u][0]) + ll(dp[u][1]))) % mod;
        dp[v][0] = ways0;
        dp[v][1] = ways1;
    }
}

void Compute(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Compute(u, v);
        if (a[v] > 0 && a[v] != a[u]) {
            Solve(u, v);
            res = ll(res) * (ll(dp[u][0]) + ll(dp[u][1])) % mod;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    for (int i = 1; i <= n; i++) if (a[i])
        S[a[i]].insert(ii(L[i], i));
    for (int i = 1; i <= k; i++)
        while (S[i].size() > 1) {
            ii p = *S[i].rbegin();
            S[i].erase(p);
            int v = P[p.second];
            if (a[v] > 0 && a[v] != i) {
                printf("0\n"); return 0;
            }
            a[v] = i;
            S[i].insert(ii(L[v], v));
        }
    int root = 1;
    while (a[root] == 0) root++;
    res = 1;
    Compute(root, 0);
    printf("%d\n", res);
    return 0;
}