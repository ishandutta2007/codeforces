#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mod=1e9+7;
long long inv(long long a)
{
    long long b=mod-2,ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}
int n,m;
vector<int> adj[nmax],actual[nmax];
int parent[nmax];
int in[nmax],t=0;
void dfs(int node,int par)
{
    if(parent[node])return;
    parent[node]=par;
    t++;
    in[node]=t;
    for(auto k:adj[node])
        dfs(k,node);
}
int comp[nmax],c=0,prod[nmax];
void make_cycle(int where,int en)
{
    c++;
    prod[c]=2;
    while(where!=en)
    {
        comp[where]=c;
        where=parent[where];
    }
    comp[where]=c;
}
int depth[nmax],total[nmax];
void run(int node,int par,int d,int p)
{
    parent[node]=par;
    depth[node]=d;
    total[node]=p;
    for(auto k:actual[node])
        if(k!=par)
            run(k,node,d+1,p*prod[k]%mod);
}
int up[nmax][20];
int lca(int a,int b)
{
    if(depth[a]>depth[b])swap(a,b);
    for(int i=19;i>=0;i--)
        if(depth[b]-(1<<i)>=depth[a])b=up[b][i];
    if(a==b)return a;
    for(int i=19;i>=0;i--)
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    return parent[a];
}
int main()
{
scanf("%i%i",&n,&m);
int a,b;
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
}

dfs(1,-1);

for(int i=1;i<=n;i++)
    for(auto j:adj[i])
    if(in[i]<in[j])
    {
        if(parent[j]==i)continue;
        make_cycle(j,i);
    }

for(int i=1;i<=n;i++)
    if(comp[i]==0)
    {
        c++;
        comp[i]=c;
        prod[c]=1;
    }
/*
for(int i=1;i<=n;i++)
    cout<<comp[i]<<" ";cout<<endl;
for(int i=1;i<=c;i++)
    cout<<prod[i]<<" ";cout<<endl;
*/
for(int i=1;i<=n;i++)
    for(auto j:adj[i])
    if(comp[i]!=comp[j])
        {
        actual[comp[i]].push_back(comp[j]);
        }

run(1,1,0,prod[1]);

for(int i=1;i<=c;i++)
    up[i][0]=parent[i];

for(int j=1;j<20;j++)
    for(int i=1;i<=c;i++)
    up[i][j]=up[up[i][j-1]][j-1];

int k,x,y;
scanf("%i",&k);
for(int i=1;i<=k;i++)
{
    scanf("%i%i",&x,&y);
    x=comp[x];
    y=comp[y];
    int u=lca(x,y);
    long long print=1LL*total[x]*inv(total[u])%mod*total[y]%mod*inv(total[u])%mod*prod[u]%mod;
    printf("%lld\n",print);
}
return 0;
}