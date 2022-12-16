#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
vector<int> adj[nmax];
vector<int> g[nmax];
int comp[nmax];
int colour[nmax];
bool been[nmax];
int c=0;
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    comp[node]=c;
    for(auto k:adj[node])
        if(colour[node]==colour[k])dfs(k);
}
int dist[nmax];
void second_dfs(int node,int d)
{
    if(dist[node]!=-1)return;
    dist[node]=d;
    for(auto k:g[node])
        second_dfs(k,d+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>colour[i];
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
        if(been[i]==0)
        {
            c++;
            dfs(i);
        }

    for(int i=1;i<=n;i++)
        for(auto k:adj[i])
            if(comp[i]!=comp[k])
            {
            g[comp[i]].push_back(comp[k]);
            //cout<<comp[i]<<" with "<<comp[k]<<endl;
            }
    memset(dist,-1,sizeof(dist));
    second_dfs(1,0);
    int u=1;
    for(int i=2;i<=c;i++)
        if(dist[u]<dist[i])u=i;
    memset(dist,-1,sizeof(dist));
    second_dfs(u,0);
    for(int i=1;i<=c;i++)
        if(dist[u]<dist[i])u=i;
    cout<<(dist[u]+1)/2<<endl;
    return 0;
}