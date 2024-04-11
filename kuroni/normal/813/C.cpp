#include <cstdio>
#include <vector>
using namespace std;

int h[200005], p[200005], ans = 0, deep[200005], n, i, x, u, v;
vector <int> adj[200005];

int DFS(int x, int a)
{
    if (a != 0)
    {
        h[x] = h[a] + 1;
        p[x] = a;
    }
    else
    {
        h[x] = 0;
        p[x] = -1;
    }
    deep[x] = h[x];
    for (int i = 0; i < adj[x].size(); i++)
        if (p[adj[x][i]] == 0)
            deep[x] = max(deep[x], DFS(adj[x][i], x));
    return deep[x];
}

int main()
{
    scanf("%d%d", &n, &x);
    for (i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    int tmp = x;
    while (h[x] - h[p[tmp]] < h[p[tmp]])
        tmp = p[tmp];
    printf("%d", 2 * deep[tmp]);
}