#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,STOP=2000;
int n,m;
int a[nmax];
int SZ[nmax];
int pos=0;
int in[nmax],out[nmax];
int depth[nmax];
vector<int> adj[nmax];
void dfs(int node,int par)
{
pos++;
in[node]=pos;
for(auto k:adj[node])
    if(k!=par)
    {
    depth[k]=depth[node]+1;
    dfs(k,node);
    }
pos++;
out[node]=pos;
}
pair<int/*node*/,int/*value*/> queries[nmax];
int depth_queries[nmax];
int add[nmax];

void dfs_update(int node,int par)
{
a[node]=a[node]+add[node];
for(auto k:adj[node])
    if(k!=par)
    {
    add[k]=add[k]-add[node];
    dfs_update(k,node);
    }
add[node]=0;
}

void update()
{
    for(int i=1;i<=n;i++)add[i]=0;
    for(int i=1;i<=pos;i++)
    {
        add[queries[i].first]+=queries[i].second;
    }
    dfs_update(1,0);
    pos=0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];

int x,y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
dfs(1,0);
pos=0;

int type,val;
for(int i=1;i<=m;i++)
{
    cin>>type;
    if(type==1)
    {
        cin>>x>>val;
        pos++;
        queries[pos]={x,val};
        depth_queries[pos]=depth[x]%2;
        if(pos==STOP)update();
    }
    else
    {
        cin>>x;
        int ans=a[x],h=depth[x]%2;
        for(int j=1;j<=pos;j++)
            if(in[queries[j].first]<=in[x]&&out[x]<=out[queries[j].first])
            {
                if(depth_queries[j]==h)ans=ans+queries[j].second;
                else ans=ans-queries[j].second;
            }
            cout<<ans<<endl;
    }
}
return 0;
}