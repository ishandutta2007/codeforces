#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int n;
vector <int> neigh[Maxn];
int cnt[Maxn], P[Maxn];
int cur, lef[Maxn], rig[Maxn];
int my[Maxn][Maxn];
ll dp[Maxn][Maxn];
ll res;

void Mark(int root, int col, int v)
{
    my[root][v] = col;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u) continue;
        Mark(root, col, u);
    }
}

void Traverse(int v)
{
    cnt[v] = 1;
    lef[v] = ++cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u) continue;
        P[u] = v;
        Traverse(u);
        cnt[v] += cnt[u];
    }
    rig[v] = cur;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u) continue;
        Mark(v, u, u);
    }
}

ll Solve(int a, int b)
{
    if (a > b) swap(a, b);
    if (a == b) return 0;
    if (dp[a][b] < 0) {
        int v = a, u = b;
        if (lef[u] <= lef[v] && rig[v] <= rig[u])
            swap(v, u);
        if (lef[v] <= lef[u] && rig[u] <= rig[v])
            dp[a][b] = ll(n - cnt[my[v][u]]) * cnt[u] +
                       max(Solve(v, P[u]), Solve(my[v][u], u));
        else dp[a][b] = ll(cnt[v]) * cnt[u] +
                        max(Solve(v, P[u]), Solve(P[v], u));
    }
    return dp[a][b];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    fill((ll*)dp, (ll*)dp + Maxn * Maxn, -1ll);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            res = max(res, Solve(i, j));
    printf("%I64d\n", res);
    return 0;
}