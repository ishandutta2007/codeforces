#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int u[N], v[N], w[N];
ll ans[N], dis[510][510], dis2[N], dis3[N];
int main() 
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                dis[i][j] = 0x3f3f3f3f, dis[i][i] = 0;
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d%d", u + i, v + i, w + i);
            dis[u[i]][v[i]] = 1;
            dis[v[i]][u[i]] = 1;
        }
        for(int k = 1; k <= n; k ++)
            for(int i = 1; i <= n; i ++)
                for(int j = 1; j <= n; j ++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for(int i = 1; i <= n; i ++) dis2[i] = dis[1][i] + dis[n][i];
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                dis2[j] = min(dis2[j], dis2[i] + dis[i][j]);
        ll ans = 1e18;
        for(int i = 1; i <= m; i ++)
            dis3[i] = min(min(dis2[u[i]], dis2[v[i]]) + 2, min(dis[1][u[i]] + dis[n][v[i]],  dis[n][u[i]] + dis[1][v[i]]) + 1);
        for(int i = 1; i <= m; i ++)
            ans = min(ans, 1LL * dis3[i] * w[i]);
        printf("%lld\n", ans);
    }
    return 0;
}