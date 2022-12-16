#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,m,q;
int parent[nmax],ans[nmax];
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
void my_merge(int u,int v)
{
    if(root(u)==root(v))return;
    u=root(u);
    v=root(v);
    parent[v]=u;

    ans[u]=max((ans[u]+1)/2+(ans[v]+1)/2+1,max(ans[u],ans[v]));

    //cout<<"roots: ";for(int i=1;i<=n;i++)cout<<root(i)<<" ";cout<<endl;
    //cout<<"ans:   ";for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;

}
vector<int> adj[nmax];
vector<int> interesting;
int dist[nmax];
bool been[nmax];
void dfs(int node,int d)
{
    if(dist[node]!=-1)return;
    dist[node]=d;
    been[node]=1;
    interesting.push_back(node);
    for(auto k:adj[node])
        dfs(k,d+1);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m>>q;
for(int i=1;i<=n;i++){parent[i]=i;ans[i]=0;}
//cout<<"roots: ";for(int i=1;i<=n;i++)cout<<root(i)<<" ";cout<<endl;

int u,v;
for(int i=1;i<=m;i++)
{
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    parent[root(v)]=root(u);
}
memset(dist,-1,sizeof(dist));

for(int i=1;i<=n;i++)
    if(been[i]==0)
    {
        interesting.clear();
        dfs(i,0);
        int v=i;
        for(auto k:interesting)
            if(dist[k]>dist[v])v=k;
        for(auto k:interesting)dist[k]=-1;
        interesting.clear();
        dfs(v,0);
        int w=i;
        for(auto k:interesting)
            if(dist[k]>dist[w])w=k;
        int now=dist[w];
        for(auto k:interesting)
        {
        ans[k]=now;
        dist[k]=-1;
        }
    }
int type;
for(int i=1;i<=q;i++)
{
    cin>>type;
    if(type==1)
    {
        cin>>u;
        u=root(u);
        cout<<ans[u]<<endl;
    }
    else
    {
        cin>>u>>v;
        my_merge(u,v);
    }
}
return 0;
}