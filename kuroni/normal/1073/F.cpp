#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int n, u, v;
pair<int, int> dst[N][2];
vector<int> adj[N];

void upd(int u, pair<int, int> d)
{
    if (dst[u][0] < d)
    {
        dst[u][1] = dst[u][0];
        dst[u][0] = d;
    }
    else if (dst[u][1] < d)
        dst[u][1] = d;
}

void DFS_1(int u, pair<int, int> d, int p = 0)
{
    if (adj[u].size() >= 3)
    {
        upd(u, d);
        return;
    }
    d.fi++;
    for (int &v : adj[u])
        if (v != p)
            DFS_1(v, d, u);
}

pair<int, int> DFS_2(int u, int p = 0)
{
    pair<int, int> ret = make_pair(dst[u][0].fi == -N ? -N : 0, u);
    for (int &v : adj[u])
        if (v != p)
        {
            pair<int, int> tmp = DFS_2(v, u);
            tmp.fi++;
            if (tmp.fi > ret.fi || (tmp.fi == ret.fi && dst[tmp.se][0].fi + dst[tmp.se][1].fi > dst[ret.se][0].fi + dst[ret.se][1].fi))
                ret = tmp;
        }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        fill(dst[i], dst[i] + 2, make_pair(-N, -N));
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1)
            DFS_1(i, make_pair(0, i));
    for (int i = 1; i <= n; i++)
        if (dst[i][0].fi != -N)
        {
            pair<int, int> l = DFS_2(i);
            pair<int, int> r = DFS_2(l.se);
            printf("%d %d\n%d %d\n", dst[l.se][0].se, dst[r.se][0].se, dst[l.se][1].se, dst[r.se][1].se);
            break;
        }
}