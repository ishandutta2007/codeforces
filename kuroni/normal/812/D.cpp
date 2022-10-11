#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int root[100005], toy[100005], d[100005], h[100005], child[100005], i, a, b, n, m, q, k;
vector <int> adj[100005], par[100005];

int DFS(int a, int p)
{
    child[a] = 1;
    if (p == 0)
        root[a] = a;
    else root[a] = root[p];
    if (p == 0)
        h[a] = 0;
    else h[a] = h[p] + 1;
    if (p != 0)
        par[a].push_back(p);
    for (int i = 1; (1 << i) <= h[a]; i++)
        par[a].push_back(par[par[a][i - 1]][i - 1]);
    for (int i = 0; i < adj[a].size(); i++)
        if (root[adj[a][i]] == 0)
            child[a] += DFS(adj[a][i], a);
    return child[a];
}

int solve(int a, int b)
{
    if (toy[b] == 0)
        return 0;
    b = toy[b];
    if (root[a] != root[b])
        return 0;
    if (h[a] > h[b])
        return 0;
    int tmp = h[b] - h[a] + 1;
    for (int i = 0; (1 << i) <= h[b] - h[a]; i++)
        if (((h[b] - h[a]) >> i) & 1)
            b = par[b][i];
    if (a != b)
        return 0;
    else return child[a];
}

int main()
{
    memset(toy, 0, sizeof(toy));
    memset(d, 0, sizeof(d));
    scanf("%d%d%d%d", &n, &m, &q, &k);
    while (q--)
    {
        scanf("%d%d", &a, &b);
        if (toy[b] != 0)
        {
            d[a]++;
            adj[toy[b]].push_back(a);
        }
        toy[b] = a;
    }
    for (i = 1; i <= n; i++)
        if (d[i] == 0)
            DFS(i, 0);
    while (k--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", solve(a, b));
    }
}