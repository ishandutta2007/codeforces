#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1E6 + 5;

int n, cnt = 0, it = 1, a[N], b[N], mat[N], vis[2 * N];
vector<int> ve, adj[2 * N];

int idx(int u)
{
    return distance(ve.begin(), lower_bound(ve.begin(), ve.end(), u));
}

bool DFS(int u)
{
    if (vis[u] == it)
        return false;
    vis[u] = it;
    for (int &v : adj[u])
        if (mat[v] == -1)
        {
            mat[v] = u;
            return true;
        }
    for (int &v : adj[u])
        if (DFS(mat[v]))
        {
            mat[v] = u;
            return true;
        }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", a + i, b + i);
        ve.push_back(a[i]);
        ve.push_back(b[i]);
    }
    sort(ve.begin(), ve.end());
    ve.resize(distance(ve.begin(), unique(ve.begin(), ve.end())));
    for (int i = 1; i <= n; i++)
    {
        adj[idx(a[i])].push_back(i);
        adj[idx(b[i])].push_back(i);
        mat[i] = -1;
    }
    int m = ve.size();
    for (int i = 0; i < m; i++)
        if (DFS(i))
        {
            ++it;
            ++cnt;
            if (cnt == n)
            {
                printf("%d\n", ve[i]);
                return 0;
            }
        }
    printf("-1");
}