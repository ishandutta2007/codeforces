#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m,k;
bool spec[nmax];
struct edge
{
int u,v,w;
};
edge all[nmax];
int parent[nmax];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
vector< pair<int/*where*/,int/*cost*/> > adj[nmax];
int sum[nmax];
int ans=0;
void dfs(int node,int par)
{
    sum[node]=spec[node];
    for(auto p:adj[node])
        if(p.first!=par)
        {
        dfs(p.first,node);
        sum[node]=sum[node]+sum[p.first];
        if(sum[p.first]&&sum[p.first]!=k)ans=max(ans,p.second);
        }
}
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
int main()
{
scanf("%i%i%i",&n,&m,&k);
for(int i=1;i<=n;i++)parent[i]=i;
int s;
for(int i=1;i<=k;i++)
{
    scanf("%i",&s);
    spec[s]=1;
}

for(int i=1;i<=m;i++)
{
    scanf("%i%i%i",&all[i].u,&all[i].v,&all[i].w);
}

sort(all+1,all+m+1,cmp);
for(int i=1;i<=m;i++)
{
    if(root(all[i].u)!=root(all[i].v))
    {
        parent[root(all[i].u)]=root(all[i].v);
        adj[all[i].u].push_back({all[i].v,all[i].w});
        adj[all[i].v].push_back({all[i].u,all[i].w});
    }
}

dfs(1,0);

for(int i=1;i<=k;i++)
    printf("%i ",ans);
return 0;
}