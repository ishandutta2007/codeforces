#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int color[maxn] , sz , res , c;
vector<int> adj[maxn] , in[maxn] , out[maxn] , topol , nodes;
bool visited[maxn] , vis[maxn];
void dfs1(int v)
{
    nodes.pb(v);
    visited[v] = 1;
    for(auto u : adj[v])
        if(!visited[u])
            dfs1(u);
}
void dfs(int v)
{
    if(vis[v])
        return;
    vis[v] = 1;
    for(auto u : out[v])
        dfs(u);
    topol.pb(v);
}
void sfd(int v)
{
    if(color[v] != -1)
        return;
    color[v] = c;
    for(auto u : in[v])
        sfd(u);
}
int main()
{
    int n , m;
    cin >> n >> m;
    fill(color , color + maxn , -1);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        in[b].pb(a);
        out[a].pb(b);
    }
    for(int i = 0; i < n; i++)
        if(!visited[i])
        {
            topol.clear();
            c = 0;
            dfs1(i);
            for(auto v : nodes)
                dfs(v);
            for(int j = topol.size() - 1; j > -1; j--)
            {
                int v = topol[j];
                if(color[v] == -1)
                    c++ , sfd(v);
            }
            if(c == nodes.size())
                res += nodes.size() - 1;
            else
                res += nodes.size();
            nodes.clear();
        }
    cout << res;
}