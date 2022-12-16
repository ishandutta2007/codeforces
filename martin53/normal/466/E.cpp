#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector<int> adj[nmax];
struct query
{
    int type,x,y;
};
query all[nmax];
bool ok[nmax];
vector< pair<int/*person*/,int/*id*/> > seen[nmax];
int parent[nmax];
int up[nmax][20];
int in[nmax];
int height[nmax];
void dfs(int node,int p,int h)
{
    up[node][0]=p;
    height[node]=h;
    for(auto k:adj[node])
        dfs(k,node,h+1);
}
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
int lca(int a,int b)
{
    if(height[a]<height[b])swap(a,b);
    for(int i=19;i>=0;i--)
        if(height[a]-(1<<i)>=height[b])a=up[a][i];
    if(a==b)return a;
    for(int i=19;i>=0;i--)
        if(up[a][i]!=up[b][i])a=up[a][i],b=up[b][i];
    return up[a][0];
}
int main()
{
cin>>n>>m;
int id=0;
for(int i=1;i<=m;i++)
{
    cin>>all[i].type>>all[i].x;
    if(all[i].type!=2)cin>>all[i].y;
    if(all[i].type==1)
    {
        in[all[i].x]++;
        adj[all[i].y].push_back(all[i].x);
    }
    if(all[i].type==3)
    {
        id++;
        seen[all[i].y].push_back({all[i].x,id});
    }
}

for(int i=1;i<=n;i++)
    if(in[i]==0)
        dfs(i,i,0);

for(int j=1;j<20;j++)
    for(int i=1;i<=n;i++)
        up[i][j]=up[up[i][j-1]][j-1];
for(int i=1;i<=n;i++)parent[i]=i;

int other=0;
for(int i=1;i<=m;i++)
    if(all[i].type==1)
    {
        parent[root(all[i].x)]=root(all[i].y);
    }
    else if(all[i].type==2)
    {
        other++;
        int person=all[i].x;
        for(auto k:seen[other])
            if(root(person)==root(k.first)&&lca(person,k.first)==k.first)
            ok[k.second]=1;
    }

for(int i=1;i<=id;i++)
    if(ok[i]==0)cout<<"NO\n";
    else cout<<"YES\n";
return 0;
}