#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;
vector<int> adj[maxn] , in[maxn] , out[maxn] , topol;
bool visited[maxn] , vis[maxn];
int color[maxn] , c , check[maxn];
map<pair<int , int> , int> mp;
vector<pair<int , int> > ans;
inline void wait ( double seconds )
{
    double endtime = clock() + ( seconds * CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
void dfs1(int v)
{
    if(visited[v])
        return;
    visited[v] = 1;
    for(auto u : adj[v])
    {
        if(check[mp[{v , u}]] != -1)
            continue;
        in[u].pb(v);
        out[v].pb(u);
        check[mp[{v , u}]] = 1;
        ans.pb({v , u});
        dfs1(u);
    }//
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
    scanf("%d%d", &n , &m);
    fill(color , color + maxn , -1);
    for(int i = 0; i < m; i++)
    {
        int a , b;
        scanf("%d%d" , &a , &b);
        adj[--a].pb(--b);
        adj[b].pb(a);
        mp[{a , b}] = i;
        mp[{b , a}] = i;
        check[i] = -1;
    }
    for(int i = 0; i < n; i++)
        dfs1(i);
    for(int i = 0; i < n; i++)
        dfs(i);
    for(int i = n - 1; i > -1; i--)
        if(color[topol[i]] == -1)
            c++ , sfd(topol[i]);
    if(c != 1)
    {
        cout << 0;
        return 0;
    }
    wait(0.59);
    for(int i = 0; i < 69; i++)
    {
        // 4999 sho :((( :'(
    }
    for(auto e : ans)
        cout << e.first + 1 << " " << e.second + 1 << endl;
}