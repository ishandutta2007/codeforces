#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = 1e3 + 20;
vector<int> adj[maxn];
bool visited[maxn];
int res , _max = -1 , a[maxn] , b , ans , anss;
void dfs(int v)
{
    res++;
    visited[v] = 1;
    ans += adj[v].size();
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            dfs(u);
    }
}
main()
{
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i] , a[i]--;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[--x].pb(--y);
        adj[y].pb(x);
    }
    for(int i = 0; i < k; i++)
    {
        res = 0;
        ans = 0;
        dfs(a[i]);
        _max = max(_max , res);
        anss -= (res * (res - 1)) / 2 - (ans / 2);
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ans = 0;
            res = 0;
            dfs(i);
            b += res;
            anss += ans / 2;
        }
    }
    cout << (b * (b - 1)) / 2 + b * _max - anss;
}