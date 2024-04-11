#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int P[Maxn];
int dp[Maxn][2];
int res[Maxn];
int seq[Maxn], slen;

void Add(int v, int val)
{
    if (val > dp[v][0]) dp[v][1] = dp[v][0], dp[v][0] = val;
    else if (val > dp[v][1]) dp[v][1] = val;
}

void Traverse(int v, int p)
{
    P[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
    }
    seq[slen++] = v;
}

int Solve(int x)
{
    int res = 0;
    for (int i = 0; i < slen; i++) {
        int v = seq[i];
        dp[v][0] = dp[v][1] = 0;
        for (int j = 0; j < neigh[v].size(); j++) {
            int u = neigh[v][j];
            if (u == P[v]) continue;
            Add(v, dp[u][0]);
        }
        if (dp[v][0] + 1 + dp[v][1] >= x) {
            res++;
            dp[v][0] = 0;
        } else dp[v][0]++;
    }
    return res;
}

int getRes(int x)
{
    if (res[x] == -1)
        res[x] = Solve(x);
    return res[x];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    fill(res, res + n + 1, -1);
    Traverse(1, 0);
    int i = 1;
    while (i <= n) {
        int cur = getRes(i);
        if (cur == 0) {
            for (int j = i; j <= n; j++)
                res[j] = 0;
            break;
        }
        int l = i + 1, r = n / cur;
        while (l <= r) {
            int m = l + r >> 1;
            if (getRes(m) == cur)
                l = m + 1;
            else r = m - 1;
        }
        for (int j = i; j < l; j++)
            res[j] = cur;
        i = l;
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", res[i]);
    return 0;
}