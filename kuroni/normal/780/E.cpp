#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool chk[200005];
int i, j, t, k, n, m, u, v, save[200005];
vector <int> adj[200005], p;

void DFS(int u)
{
    chk[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (chk[v])
            continue;
        p.push_back(u);
        DFS(v);
    }
    p.push_back(u);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int j = 2 * n - 1;
    for (i = 1; i <= k; i++)
    {
        save[i] = j / (k - i + 1);
        j -= save[i];
    }
    DFS(1);
    j = 0;
    for (i = 1; i <= k; i++)
    {
        printf("%d ", save[i]);
        while (save[i]--)
            printf("%d ", p[j++]);
        printf("\n");
    }
}