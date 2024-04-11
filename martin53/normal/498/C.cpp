#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e2+42,inf=1e9;
int n,m;
int a[nmax];
map<int,int> seen;
void update(int x)
{
for(int i=2;i*i<=x;i++)
    if(x%i==0)
    {
        seen[i]++;
        while(x%i==0)x=x/i;
    }
if(x!=1)seen[x]++;
}
vector<int> adj[nmax];
int parent[nmax];

int flow[nmax][nmax];
void dfs(int node,int par)
{
//cout<<"dfs "<<node<<" "<<par<<endl;
if(parent[node]!=-1)return;
parent[node]=par;
for(auto k:adj[node])
    if(flow[node][k])dfs(k,node);
}
int query(int x)
{
//cout<<"query "<<x<<endl;
memset(flow,0,sizeof(flow));
for(int i=1;i<=n;i++)
    for(auto k:adj[i])
    {
    flow[i][k]=inf;
    }
for(int i=1;i<=n;i++)
{
int cop=a[i];
    while(cop%x==0)
    {
    if(i%2==1)flow[0][i]++;
    else flow[i+n][2*n+1]++;
    cop=cop/x;
    }
}
/*
for(int i=0;i<=2*n+1;i++)
{
    for(int j=0;j<=2*n+1;j++)
        cout<<flow[i][j]<<" ";
    cout<<endl;
}

for(int i=0;i<=2*n+1;i++)
{
    cout<<i<<" -> ";for(auto k:adj[i])cout<<k<<" ";cout<<endl;
}
*/
int f=0;
while(1)
{
memset(parent,-1,sizeof(parent));
dfs(0,0);
    if(parent[2*n+1]==-1)break;
    int node=2*n+1;
    while(node)
    {
    int par=parent[node];
    flow[par][node]--;
    flow[node][par]++;
    node=par;
    }
    f++;
}
return f;
}
int main()
{
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>a[i];
update(a[i]);
}

int x,y;
for(int i=1;i<=m;i++)
{
cin>>x>>y;
if(x%2==0)swap(x,y);
adj[x].push_back(n+y);
adj[n+y].push_back(x);

adj[0].push_back(x);
adj[n+y].push_back(2*n+1);
}
int ans=0;
for(auto k:seen)
    if(k.second>1)
    ans=ans+query(k.first);
cout<<ans<<endl;
return 0;
}