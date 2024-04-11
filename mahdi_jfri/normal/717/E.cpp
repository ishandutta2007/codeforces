#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
bool visited[maxn] , is[maxn] , f;
vector<int> ans , adj[maxn];
void dfs(int v , int p = -1)
{
    visited[v] = 1;
    ans.pb(v);
    is[v] = 1 - is[v];
    for(auto u : adj[v])
        if(!visited[u])
            dfs(u , v) , ans.pb(v) , is[v] = 1 - is[v];
    if(is[v])
    {
        if(p == -1)
            f = 1;
        else
            is[p] = 1 - is[p] , ans.pb(p) , ans.pb(v);
    }
}
int main()
{
    int n , m;
    cin >> n;
    m = n - 1;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == -1)
            is[i] = 1;
    }
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    is[0] = 1 - is[0];
    dfs(0);
    for(int i = 0; i < n; i++)
        if(is[i] && !visited[i])
        {
            cout << -1;
            return 0;
        }
    if(f)
    {
        ans.pop_back();
    }
    for(auto v : ans)
        cout << v + 1 << " ";
}