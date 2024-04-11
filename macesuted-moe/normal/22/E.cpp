#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int son[maxn], deg[maxn];
int vis[maxn];
vector<int> head, tail;

int dfs(int x)
{
    vis[x] = true;
    if (!vis[son[x]])
        return vis[x] = dfs(son[x]);
    else
        return vis[x] = x;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &son[i]);
        deg[son[i]]++;
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
        {
            k++;
            head.push_back(i);
            tail.push_back(dfs(i));
        }
    int kk = k;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            k++;
            head.push_back(i);
            tail.push_back(dfs(i));
        }
    if (k == 1 && !kk)
        k = 0;
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
        printf("%d %d\n", tail[i], head[(i + 1) % k]);
    return 0;
}