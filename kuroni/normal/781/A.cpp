#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 2e5 + 10;

int n, col[maxN], ans = 0, parent[maxN];
vector<int> g[maxN];

void DFS(int U)
{
    int cnt = 1;
    for (int i = 0; i < g[U].size(); ++i)
    {
        int u = g[U][i];
        if (parent[u]) continue;
        parent[u] = U;
        while (cnt == col[U] || cnt == col[parent[U]]) ++cnt;
        col[u] = cnt++;
        DFS(u);
        int c1 = col[U], c2 = col[u], tmp = 0;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i]; if (v == U) continue;
            ++tmp; 
            while (tmp == c1 || tmp == c2) ++tmp;
            col[v] = tmp;
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        int tmp = g[i].size(); ++tmp;
        ans = max(ans, tmp);
    }
    parent[1] = 1; col[1] = 1;
    DFS(1);
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", col[i]);
//        cout << parent[i] << ' ';
}