#include<bits/stdc++.h>
using namespace std;
const int nmax=2e2+42,inf=1e9;
int n,m;
int flow[nmax][nmax];
int a[nmax],b[nmax];
int parent[nmax];
vector<int> adj[nmax];
void dfs(int node,int par)
{
if(parent[node]!=-1)return;
parent[node]=par;
for(auto k:adj[node])
    if(flow[node][k])dfs(k,node);
}

int outp[nmax][nmax];

int main()
{
cin>>n>>m;
int sum=0,target=0;
for(int i=1;i<=n;i++)
{
cin>>a[i];
sum=sum+a[i];
flow[0][i]=a[i];
adj[0].push_back(i);
}

for(int i=1;i<=n;i++)
{
cin>>b[i];
target=target+b[i];
flow[n+i][2*n+1]=b[i];
adj[n+i].push_back(2*n+1);
}

if(sum!=target)
{
cout<<"NO"<<endl;
return 0;
}

int x,y;
for(int i=1;i<=n;i++)
{
adj[i].push_back(n+i);
adj[n+i].push_back(i);
flow[i][n+i]=inf;
}
for(int i=1;i<=m;i++)
{
cin>>x>>y;
flow[x][n+y]=inf;
flow[y][n+x]=inf;
adj[x].push_back(n+y);
adj[y].push_back(n+x);

adj[n+x].push_back(y);
adj[n+y].push_back(x);

}

while(1)
{
memset(parent,-1,sizeof(parent));
dfs(0,0);
    if(parent[2*n+1]==-1)break;
    target--;
    int node=2*n+1,par;
    while(node)
    {
    par=parent[node];
        if(1<=par&&par<=n&&n+1<=node&&node<=2*n)outp[par][node-n]++;
        else outp[node][par-n]--;
    flow[par][node]--;
    flow[node][par]++;
    node=par;
    }

}

if(target)
{
cout<<"NO"<<endl;
return 0;
}

cout<<"YES"<<endl;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)cout<<outp[i][j]<<" ";
    cout<<endl;
}
return 0;
}