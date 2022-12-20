#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
set<int> adj[nmax];
int value[nmax];
vector<int> active;

int c=0;
int when[nmax];
void dfs_second(int node)
{
    if(when[node]==c)return;
    when[node]=c;
    active.push_back(node);
    for(auto k:adj[node])
        dfs_second(k);
}
int SZ[nmax];
void dfs(int node,int parent)
{
    SZ[node]=1;
    for(auto k:adj[node])
        if(k!=parent)
        {
        dfs(k,node);
        SZ[node]=SZ[node]+SZ[k];
        }
}
void solve(int h)
{
    //cout<<h<<" -> ";for(auto k:active)cout<<k<<" ";cout<<endl;
    if(active.size()==1)
    {
        value[active[0]]=h;
        return;
    }

    dfs(active[0],0);
    int node=active[0],parent=0;
    while(1)
    {
        bool good=1;
        for(auto k:adj[node])
            if(k!=parent&&SZ[k]>active.size()/2)
            {
            good=0;
            parent=node;
            node=k;
            break;
            }
        if(good)break;
    }
    //cout<<"node= "<<node<<endl;

    value[node]=h;

    for(auto k:adj[node])
    {
        adj[k].erase(node);
        //adj[node].erase(k);
        active={};
        c++;
        dfs_second(k);
        //cout<<"k= "<<k;cout<<" active= ";for(auto p:active)cout<<p<<" ";cout<<endl;
        solve(h+1);
    }
    adj[node]={};
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
cin>>x>>y;
adj[x].insert(y);
adj[y].insert(x);
}
for(int i=1;i<=n;i++)active.push_back(i);
solve(0);
for(int i=1;i<=n;i++)cout<<char(value[i]+'A')<<" ";cout<<endl;
return 0;
}