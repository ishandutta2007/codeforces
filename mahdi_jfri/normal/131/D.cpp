#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
const int maxn = 3e3 + 20;
vi adj[maxn];
bool visited[maxn];
int a , b;
int grandpa[maxn];
int q[maxn],h,t;
int n;
int dist[maxn];
void bfs()
{
    while(t < h)
    {
        for(int i = 0; i < adj[q[t]].size(); i++)
        {
            int u = adj[q[t]][i];
            if(dist[u] != -1)
                continue;
            q[h++] = u;
            dist[u] = dist[q[t]] + 1;
        }
        t++;
    }
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
    exit(0);
}
void bfs1(int v,int u)
{
    fill(dist,dist + n,-1);
    while(u != v)
    {
        q[h++] = u;
        dist[u] = 0;
        u = grandpa[u];
    }
    q[h++] = v;
    dist[v] = 0;
    bfs();
}
void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(!visited[u])
            grandpa[u] = v, dfs(u);
        else if(grandpa[v] != u)
        {
            bfs1(u,v);
        }
    }
}
int main()
{
    cin >> n;
    int nn = n;
    while(nn--)
    {
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    grandpa[0] = -1;
    dfs(0);
}