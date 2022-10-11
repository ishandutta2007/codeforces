#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2005;

vector<int> adj[N], cur;
int n, u, num[N], low[N], cnt = 0, con = 0;
bool del[N];

void DFS(int u)
{
    num[u] = low[u] = ++cnt;
    cur.push_back(u);
    for (int v : adj[u])
        if (!del[v])
        {
            if (num[v] == 0)
            {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    if (num[u] == low[u])
    {
        ++con;
        while (!del[u])
        {
            del[cur.back()] = true;
            cur.pop_back();
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &u);
            if (u > 0 && i != j)
                adj[i].push_back(j);
        }
    for (int i = 1; i <= n; i++)
        if (!del[i])
            DFS(i);
    printf("%s", con == 1 ? "YES" : "NO");
}