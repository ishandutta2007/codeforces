#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector<int> adj[nmax];
int parent[nmax];
int SZ[nmax];
int height[nmax];

void dfs(int node,int par)
{
SZ[node]=1;
parent[node]=par;
for(auto k:adj[node])
if(k!=par)
{
    height[k]=height[node]+1;
    dfs(k,node);
    SZ[node]=SZ[node]+SZ[k];
}

}
int go_up[nmax][20];
void precalc()
{
for(int i=1;i<=n;i++)
    go_up[i][0]=parent[i];
for(int h=1;h<20;h++)
    for(int i=1;i<=n;i++)
    go_up[i][h]=go_up[go_up[i][h-1]][h-1];
}
int go(int x,int h)
{
    for(int i=0;i<20;i++)
        if((h&(1<<i)))x=go_up[x][i];
    return x;
}

int find_lca(int x,int y)
{

if(height[x]<height[y])swap(x,y);
for(int i=19;i>=0;i--)
    if(height[x]-(1<<i)>=height[y])x=go_up[x][i];
if(x==y)return x;
for(int i=19;i>=0;i--)
    if(go_up[x][i]!=go_up[y][i])
    {
    x=go_up[x][i];
    y=go_up[y][i];
    }
return go_up[x][0];
}

int query(int x,int y)
{
if(x==y)return n;
int lca=find_lca(x,y);
int d=height[x]-height[lca]+height[y]-height[lca];
if(d%2)return 0;
if(height[x]==height[y])
{
    int x_=go(x,d/2-1);
    int y_=go(y,d/2-1);
    return n-SZ[x_]-SZ[y_];
}
if(height[x]<height[y])swap(x,y);
int x_=go(x,d/2-1);
int p=go(x,d/2);
return SZ[p]-SZ[x_];
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n;
int x,y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}

dfs(1,1);
precalc();

cin>>m;
for(int i=1;i<=m;i++)
{
cin>>x>>y;
cout<<query(x,y)<<endl;
}
return 0;
}