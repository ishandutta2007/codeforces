#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int test, n, m, x, y, deg[1111], ct, dp[1111], ord[1111], a[1111];
vector<int> v, g[1111], rg[1111];
bool f;
void topo()
{
    queue<int> q; ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!deg[i]) q.push(i);
    }
    while(!q.empty())
    {
        x = q.front();
        ord[++ct] = x;
        q.pop();
        for (int i = 0; i < g[x].size(); i++)
        {
            int to = g[x][i];
            if (!--deg[to]) q.push(to);
        }
    }
}
void add(int &x, int y)
{
    x += y;
    if (x >= mod) x -= mod;
}
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            rg[i].clear();
            deg[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            rg[y].push_back(x);
            deg[y]++;
        }
        f = 0;
        for (int i = 1; i <= n; i++)
        {
            v.clear();
            for (int j = 1; j <= n; j++)
            {
                if (a[j]) v.push_back(j);
            }
            if (v.empty()) 
            {
                f = 1;
                printf("%d\n", i - 1);
                break;
            }
            for (int j = 0; j < v.size(); j++)
            {
                a[v[j]] --;
                for (int k = 0; k < g[v[j]].size(); k++)
                {
                    a[g[v[j]][k]] ++;
                }
            }
        }
        if (f) continue;
        topo();
        for (int i = 1; i <= n; i++)
        {
            dp[ord[i]] = a[ord[i]] % mod;
            for (int j = 0; j < rg[ord[i]].size(); j++)
            {
                add(dp[ord[i]], dp[rg[ord[i]][j]]); 
            }
        }
        printf("%d\n", (dp[ord[n]] + n) % mod);
    }
    return 0;
}