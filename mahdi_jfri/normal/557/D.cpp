#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = 1e5 + 20;
vector<int>adj[maxn];
bool visited[maxn] , x;
ll res , a[3];
int cmp[maxn];
void dfs(int v , int c)
{
    visited[v] = 1;
    cmp[v] = c;
    a[c]++;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            dfs(u , 1 - c);
        else if(cmp[u] != 1 - c)
            x = 1;
    }
}
main()
{
    int n , m;
    cin >> n >> m;
    if(!m)
    {
        cout << 3 << " " << (n * (n - 1) * (n - 2)) / 6;
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        if(adj[i].size() > 1)
            x = 1;
    if(!x)
    {
        cout << 2 << " " << (n - 2) * m;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            x = 0;
            dfs(i , 0);
            if(x)
            {
                cout << 0 << " " << 1;
                return 0;
            }
            res += ((a[0] * (a[0] - 1)) + (a[1] * (a[1] - 1))) / 2;
            a[0] = a[1] = 0;
        }
    }
    cout << 1 << " " << res;
}