#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e2 + 20;
set<int> adj[maxn] , st[maxn];
vector<int> path[maxn][maxn];
ll ans , res , node;
bool visited[maxn] , del[maxn];
void dfs(int v , int p = -1 , ll t = 0)
{
    if(ans <= t)
    {
        ans = t;
        node = v;
    }
    visited[v] = 1;
    for(auto u : adj[v])
        if(u != p && !del[u])
            dfs(u , v , t + 1);
}
void adfs(int v , int x , int p = -1)
{
    if(p != -1)
        path[v][x] = path[p][x];
    path[v][x].pb(v);
    for(auto u : adj[v])
        if(u != p)
            adfs(u , x , v);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].insert(--b);
        adj[b].insert(a);
    }
    for(int i = 0; i < n; i++)
        adfs(i , i);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            ans = 0;
            ll anss = 0;
            for(auto x : path[i][j])
                del[x] = 1;
            fill(visited , visited + maxn , 0);
            for(int k = 0; k < n; k++)
                if(!visited[k] && !del[k])
                {
                    ans = 0;
                    dfs(k);
                    ans = 0;
                    dfs(node);
                    anss = max(anss , ans);
                }
            for(auto x : path[i][j])
                del[x] = 0;
            res = max(res , anss * (ll)(path[i][j].size() - 1));
        }
    cout << res;
}