#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
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
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
        cin >> is[i];
    for(int i = 0; i < n; i++)
    {
        if(is[i])
        {
            dfs(i);
            break;
        }
    }
    for(int i = 0; i < n; i++)
        if(is[i] && !visited[i])
        {
            cout << -1;
            return 0;
        }
    if(f)
    {
        reverse(ans.begin() , ans.end());
        ans.pop_back();
        reverse(ans.begin() , ans.end());
    }
    cout << ans.size() << endl;
    for(auto v : ans)
        cout << v + 1 << " ";
}