#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,STOP=100;
int n,m;
vector<int> adj[nmax];
int ans[nmax];
int parent[nmax];
int depth[nmax];
void dfs(int node,int par)
{
    parent[node]=par;
    for(auto k:adj[node])
    if(k!=par)
    {
    ans[k]=ans[node]+1;
    depth[k]=depth[node]+1;
    dfs(k,node);
    }
}
int up[nmax][20];
void precompute()
{
    for(int i=1;i<=n;i++)up[i][0]=parent[i];
    for(int h=1;h<20;h++)
        for(int i=1;i<=n;i++)
        up[i][h]=up[up[i][h-1]][h-1];
}
int to_colour[nmax];
int pos=0;
queue< pair<int/*node*/,int/*time*/> >q,idle;
void bfs()
{
    q=idle;
    for(int i=1;i<=pos;i++)q.push({to_colour[i],0});
    while(q.size())
    {
         pair<int/*node*/,int/*time*/> now=q.front();
         q.pop();
         if(ans[now.first]<=now.second)continue;
         ans[now.first]=now.second;
         for(auto k:adj[now.first])
            q.push({k,now.second+1});
    }
}

int find_lca(int a,int b)
{
    if(depth[a]<depth[b])swap(a,b);
    int d=depth[a]-depth[b];
    for(int i=19;i>=0;i--)
        if((d&(1<<i)))
        {
        a=up[a][i];
        d=d-(1<<i);
        }
    if(a==b)return a;
    for(int i=19;i>=0;i--)
        if(up[a][i]!=up[b][i])
        {
        a=up[a][i];
        b=up[b][i];
        }
    return parent[a];
}
int dist(int u,int v)
{
int lca=find_lca(u,v);
return depth[u]+depth[v]-2*depth[lca];
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
int x,y;
for(int i=1;i<n;i++)
{
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

dfs(1,1);
precompute();

int type,v;
for(int i=1;i<=m;i++)
{
    cin>>type>>v;
    if(type==1)
    {
        pos++;
        to_colour[pos]=v;
        if(pos==STOP)
        {
            bfs();
            pos=0;
        }
    }
    else
    {
        int outp=ans[v];
        for(int j=1;j<=pos;j++)
            outp=min(outp,dist(v,to_colour[j]));
        cout<<outp<<endl;
    }
}
return 0;
}