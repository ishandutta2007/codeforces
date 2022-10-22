#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
ll k;
int a[Maxn];
vector <int> neigh[Maxn];
int tk[Maxn];
ll dp[Maxn];

ll Get(int v, int x)
{
    if (a[v] > x) return 0;
    if (tk[v] == 1) return k;
    if (tk[v] == 2) return dp[v];
    tk[v] = 1;
    dp[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++)
        dp[v] = max(dp[v], Get(neigh[v][i], x) + 1);
    tk[v] = 2;
    return dp[v];
}

bool Check(int x)
{
    fill(tk, tk + n + 1, 0);
    for (int i = 1; i <= n; i++) if (!tk[i])
        if (Get(i, x) >= k) return true;
    return false;
}

int main()
{
    scanf("%d %d %I64d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
    }
    int lef = 0, rig = 1000000007;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d\n", lef >= 1000000005? -1: lef);
    return 0;
}