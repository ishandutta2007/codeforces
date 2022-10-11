#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1E9 + 7, N = 200005;

int n, u, v, a[N], mx[N];
long long su[N];
vector<int> ve, adj[N];

void DFS(int u, int p = 0)
{
    mx[u] = -INF;
    for (int &v : adj[u])
        if (v != p)
        {
            DFS(v, u);
            su[u] += su[v];
            mx[u] = max(mx[u], mx[v]);
        }
    if (mx[u] == -INF)
        su[u] = mx[u] = a[u];
    else if (mx[u] > a[u])
    {
        su[u] -= mx[u] - a[u];
        mx[u] = a[u];
    }
}

void trace(int u, int p = 0, bool get = true)
{
    int cur = -INF;
    bool mul = false;
    for (int &v : adj[u])
        if (v != p)
        {
            if (mx[v] > cur)
            {
                cur = mx[v];
                mul = false;
            }
            else if (mx[v] == cur)
                mul = true;
        }
    if (a[u] == mx[u] && get)
        ve.push_back(u);
    for (int &v : adj[u])
        if (v != p)
            if (a[u] == mx[u])
                trace(v, u, mx[v] < cur || mul || (a[u] == cur && get));
            else
                trace(v, u, mx[v] < cur || get || mul);
}   

int main()
{
    mx[0] = -INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    trace(1);
    sort(ve.begin(), ve.end());
    printf("%lld %d\n", su[1], ve.size());
    for (int &v : ve)
        printf("%d ", v);
}