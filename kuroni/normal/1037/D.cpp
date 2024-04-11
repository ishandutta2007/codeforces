#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int N = 200005;

int n, u, v, pt = 2, a[N];
set<int> adj[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    if (a[1] != 1)
    {
        printf("No\n");
        return 0;
    }
    adj[a[1]].insert(0);
    for (int i = 1; i <= n; i++)
    {
        int u = a[i], sz = adj[u].size();
        for (int j = 1; j < sz; j++, pt++)
        {
            if (adj[u].find(a[pt]) == adj[u].end())
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
}