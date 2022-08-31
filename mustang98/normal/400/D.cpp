#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

const int max_n = 100111, max_k = 511, inf = 1000 * 1000 * 1000 + 1111;

vector<pair<int,int> > v[max_n];
vector<int> color;
vector<int> firstc;
vector<int> countc;
int d[max_k][max_k];
int vis[max_n];
int n, m, k;

int curcol, curcnt;

void DFS(int a)
{
    vis[a] = true;
    if (color[a] == curcol)
    {
        curcnt++;
    }
    for (int i = 0; i < v[a].size(); ++i)
    {
        int to = v[a][i].F;
        int dist = v[a][i].S;
        if (dist == 0 && !vis[to])
        {
            DFS(to);
        }
        d[color[a]][color[to]] = min(d[color[a]][color[to]], dist);
    }
}


int main()
{
    int a, b, x;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &a);
        countc.push_back(a);
        firstc.pb(color.size());
        for (int j = 0; j < a; ++j)
        {
            color.pb(i);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &a, &b, &x);
        a--, b--;
        v[a].pb(mp(b, x));
        v[b].pb(mp(a, x));
    }

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }

    for (int col = 0; col < k; ++col)
    {
        for (int i = 0; i < n; ++i)
        {
            vis[i] = 0;
        }
        curcnt = 0;
        curcol = col;
        DFS(firstc[col]);
        if (curcnt < countc[col])
        {
            printf("No\n");
            return 0;
        }
    }
    for (int p = 0; p < k; ++p)
    {
        for (int i = 0; i < k; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
            }
        }
    }

    printf("Yes\n");
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            printf("%d ", d[i][j] == inf ? -1 : d[i][j]);
        }
        printf("\n");
    }

    return 0;
}