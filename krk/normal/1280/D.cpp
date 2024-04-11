#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;

const int Maxn = 3005;

int T;
int n, m;
int st[Maxn];
vector <int> neigh[Maxn];
int cnt[Maxn];
ill dp[Maxn][Maxn];
int res;

void Traverse(int v, int p = 0)
{
    cnt[v] = 0;
    dp[v][0] = ill(0, st[v]);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        int lim = cnt[v];
        for (int i = 0; i < cnt[u]; i++)
            dp[v][++cnt[v]] = ill(-Maxn, 0);
        for (int a = lim; a >= 0; a--) {
            ill my = dp[v][a]; dp[v][a] = ill(-Maxn, 0);
            for (int b = 0; b <= cnt[u]; b++)
                dp[v][a + b] = max(dp[v][a + b], ill(my.first + dp[u][b].first,
                                                     my.second + dp[u][b].second));
        }
    }
    dp[v][++cnt[v]] = ill(-Maxn, 0);
    if (v == 1)
        if (dp[v][m - 1].second > 0) res = dp[v][m - 1].first + 1;
        else res = dp[v][m - 1].first;
    else for (int a = cnt[v] - 1; a >= 0; a--)
        if (dp[v][a].second > 0)
            dp[v][a + 1] = max(dp[v][a + 1], ill(dp[v][a].first + 1, 0ll));
        else dp[v][a + 1] = max(dp[v][a + 1], ill(dp[v][a].first, 0ll));
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &st[i]);
            st[i] = -st[i];
            neigh[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int w; scanf("%d", &w);
            st[i] += w;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Traverse(1);
        printf("%d\n", res);
    }
    return 0;
}