#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

vector<int> adj[N];
int n, u, v, rt = 0, cur = 1, ans = 0, sub[N], h[N], cnt[N];

int DFS(int u, int p)
{
    h[u] = h[p] + 1;
    for (int v : adj[u])
        if (v != p)
            sub[u] = max(sub[u], DFS(v, u));
    return sub[u] = max(sub[u], h[u]);
}

void HLD(int u, int p)
{
    cnt[cur]++;
    int mc = 0;
    for (int v : adj[u])
        if (v != p && sub[v] > sub[mc])
            mc = v;
    if (mc != 0)
        HLD(mc, u);
    for (int v : adj[u])
        if (v != p && v != mc)
        {
            ++cur;
            HLD(v, u);
        }
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
    h[0] = -1;
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
        if (h[i] > h[rt])
            rt = i;
    fill(sub + 1, sub + n + 1, 0);
    DFS(rt, 0);
    HLD(rt, 0);
    sort(cnt + 1, cnt + cur + 1, greater<int>());
    printf("1 ");
    for (int i = 1; i < n; i++)
        printf("%d ", ans += cnt[i]);
}