#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
ii dp[Maxn][2];
int res[Maxn];

void Traverse(int v, int p)
{
    dp[v][0] = ii(0, -1);
    dp[v][1] = ii(1, -int(neigh[v].size()));
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        ii add = max(dp[u][0], dp[u][1]);
        dp[v][0].first += add.first;
        dp[v][0].second += add.second;
        dp[v][1].first += dp[u][0].first;
        dp[v][1].second += dp[u][0].second;
    }
}

void Solve(int v, int p, int col)
{
    res[v] = col? neigh[v].size(): 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (col == 1 || dp[u][0] > dp[u][1]) Solve(u, v, 0);
        else Solve(u, v, 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    if (n == 2) {
        printf("2 2\n");
        printf("1 1\n");
        return 0;
    }
    Traverse(1, 0);
    ii mx = max(dp[1][0], dp[1][1]);
    printf("%d %d\n", mx.first, -mx.second);
    if (dp[1][0] > dp[1][1]) Solve(1, 0, 0);
    else Solve(1, 0, 1);
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}