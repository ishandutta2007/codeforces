#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005;

vector<int> adj[N], ret[N], ans;
int n, p[N], s[N];
bool vis[N];

void get_ans(int u)
{
    vis[u] = true;
    ans.push_back(u);
    for (int v : adj[u])
        if (!vis[v])
            get_ans(v);
}

bool DFS(int u)
{
    int deg = (p[u] != 0);
    for (int v : adj[u])
        if (!DFS(v))
            ++deg;
    if ((deg & 1) || u == 0)
        return false;
    else
    {
        get_ans(u);
        return true;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", p + i);
        adj[p[i]].push_back(i);
    }
    DFS(0);
    if (ans.size() < n)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int v : ans)
            printf("%d\n", v);
    }
}