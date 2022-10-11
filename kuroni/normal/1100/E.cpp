#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005;

int n, m, c, u[N], v[N], vis[N], cnt[N];
vector<pair<int, int>> adj[N];
vector<int> tpo;

bool DFS(int u, int lim)
{
    if (vis[u] == 2)
        return true;
    if (vis[u] == 1)
        return false;
    vis[u] = 1;
    for (pair<int, int> &v : adj[u])
        if (v.second >= lim && !DFS(v.first, lim))
            return false;
    tpo.push_back(u);
    vis[u] = 2;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", u + i, v + i, &c);
        adj[u[i]].push_back(make_pair(v[i], c));
    }
    int le = 1, ri = 1E9;
    while (le <= ri)
    {
        bool chk = true;
        int md = (le + ri) / 2;
        fill(vis + 1, vis + n + 1, 0);
        tpo.clear();
        for (int i = 1; i <= n; i++)
            if (!DFS(i, md))
            {
                chk = false;
                break;
            }
        if (chk)
            ri = md - 1;
        else
            le = md + 1;
    }
    fill(vis + 1, vis + n + 1, 0);
    tpo.clear();
    for (int i = 1; i <= n; i++)
        DFS(i, le);
    for (int i = n - 1; i >= 0; i--)
        cnt[tpo[i]] = n - i;
    printf("%d ", ri);
    int ret = 0;
    for (int i = 1; i <= m; i++)
        if (cnt[u[i]] > cnt[v[i]])
            ret++;
    printf("%d\n", ret);
    for (int i = 1; i <= m; i++)
        if (cnt[u[i]] > cnt[v[i]])
            printf("%d ", i);
}