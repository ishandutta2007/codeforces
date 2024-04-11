#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m,parent[nmax];
vector<int> adj[nmax];
int modulo[nmax];
int ROOT=-1;

vector<int> path;

void add(int node)
{
    path.push_back(node);
    modulo[node]=!modulo[node];
}
void dfs(int node,int parent)
{
    add(node);

    for(auto k:adj[node])
        if(k!=parent)
        {
            dfs(k,node);
            add(node);
        }

    if(modulo[node])
    {
        if(node!=ROOT)
        {
            add(parent);
            add(node);
            return;
        }
        path.erase(path.begin(),path.begin()+1);
        modulo[node]=!modulo[node];
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
cin>>n>>m;
for(int i=1;i<=n;i++)parent[i]=i;

int u,v;
for(int i=1;i<=m;i++)
{
    cin>>u>>v;
    if(root(u)!=root(v))
    {
        parent[root(u)]=root(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

for(int i=1;i<=n;i++)cin>>modulo[i];

for(int i=1;i<=n;i++)
    if(modulo[i])
    {
        if(ROOT==-1)ROOT=root(i);
        else if(root(i)!=ROOT)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

dfs(ROOT,0);

//cout<<ROOT<<endl;

cout<<path.size()<<endl;
for(auto k:path)cout<<k<<" ";cout<<endl;
return 0;
}