#include<bits/stdc++.h>
using namespace std;
const int nmax=2*200+42;
int n;
int a[nmax];
vector<int> adj[nmax];
bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int parent[nmax];
int flow[nmax][nmax];
void dfs(int node,int par)
{
if(parent[node]!=-1)return;
parent[node]=par;
for(auto k:adj[node])
    if(flow[node][k])dfs(k,node);
}
set<int> matched[nmax];
vector<int> path[nmax];
bool been[nmax];
int pos=0;
void make_path(int node)
{
if(been[node])return;
been[node]=1;
path[pos].push_back(node);
for(auto k:adj[node])
    make_path(k);
}
int main()
{
cin>>n;
int even=0,odd=0;
for(int i=1;i<=n;i++)
{
cin>>a[i];
if(a[i]%2==0)even++;
else odd++;
}
if(even!=odd)
{
cout<<"Impossible"<<endl;
return 0;
}

for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(a[i]%2==1&&a[j]%2==0&&prime(a[i]+a[j]))
    {
        adj[i].push_back(j+n);
        adj[j+n].push_back(i);
        flow[i][j+n]=1;
    }

for(int i=1;i<=n;i++)
    if(a[i]%2==1)
    {
    adj[0].push_back(i);
    flow[0][i]=2;
    }

for(int j=1;j<=n;j++)
    if(a[j]%2==0)
    {
    adj[n+j].push_back(2*n+1);
    flow[n+j][2*n+1]=2;
    }

int f=0;
while(1)
{
    memset(parent,-1,sizeof(parent));
    dfs(0,0);
    if(parent[2*n+1]==-1)break;
    f++;
    int node=2*n+1,t=0;
    while(node)
    {
        if(node!=2*n+1&&parent[node]!=0)
        {
            if(t%2==0)
            {
            matched[node].erase(parent[node]);
            }
            else
            {
            matched[parent[node]].insert(node);
            }
        }
        t++;
        flow[parent[node]][node]--;
        flow[node][parent[node]]++;
        node=parent[node];
    }

}

if(f!=n)
{
cout<<"Impossible"<<endl;
return 0;
}

/*
for(int i=1;i<=n;i++)
    if(a[i]%2==1)
    {
    cout<<i<<" -> ";for(auto k:matched[i])cout<<k<<" ";cout<<endl;
    }
*/

for(int i=0;i<=2*n+1;i++)
    adj[i].clear();

for(int i=1;i<=n;i++)
    if(a[i]%2==1)
    {
        for(auto k:matched[i])
            {
            adj[i].push_back(k-n);
            adj[k-n].push_back(i);
            }
    }

memset(been,0,sizeof(been));
for(int i=1;i<=n;i++)
    if(been[i]==0)
    {
    pos++;
    make_path(i);
    }

cout<<pos<<endl;
for(int i=1;i<=pos;i++)
{
    cout<<path[i].size();
    for(auto k:path[i])cout<<" "<<k;cout<<endl;
}

return 0;
}