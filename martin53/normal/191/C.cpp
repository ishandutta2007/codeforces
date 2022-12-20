#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
pair<int,int> inp[nmax];
vector<int> adj[nmax];
int parent[nmax],height[nmax];
void dfs(int node,int p)
{
    parent[node]=p;
    for(auto k:adj[node])
        if(k!=p)
        {
        height[k]=height[node]+1;
        dfs(k,node);
        }
}
int up[nmax][20];
int find_lca(int x,int y)
{
    if(height[x]<height[y])swap(x,y);
    for(int j=19;j>=0;j--)
        if(height[x]-(1<<j)>=height[y])x=up[x][j];
    if(x==y)return x;
    for(int i=19;i>=0;i--)
        if(up[x][i]!=up[y][i])
        {
        x=up[x][i];
        y=up[y][i];
        }
    return parent[x];
}
map< pair<int,int>,int> seen;
int add[nmax];
void dfs_solve(int node,int p)
{
    for(auto k:adj[node])
        if(k!=p)
        {
        dfs_solve(k,node);
        }
    seen[{node,p}]+=add[node];
    seen[{p,node}]+=add[node];
    add[p]+=add[node];
    add[node]=0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n;
int x,y;
for(int i=1;i<n;i++)
{
cin>>inp[i].first>>inp[i].second;
adj[inp[i].first].push_back(inp[i].second);
adj[inp[i].second].push_back(inp[i].first);
}
dfs(1,1);
for(int i=1;i<=n;i++)up[i][0]=parent[i];
for(int h=1;h<20;h++)
    for(int j=1;j<=n;j++)
    up[j][h]=up[up[j][h-1]][h-1];
int k;
cin>>k;
for(int i=1;i<=k;i++)
{
    cin>>x>>y;
    add[find_lca(x,y)]-=2;
    add[x]+=1;
    add[y]+=1;
}
dfs_solve(1,1);
for(int i=1;i<n;i++)cout<<seen[inp[i]]<<" ";cout<<endl;
return 0;
}