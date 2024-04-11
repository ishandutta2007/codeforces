#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector<int> adj[nmax];
int SZ_comp[nmax],which_comp[nmax];
int paths_comp[nmax];
bool used[nmax];
int comp=0;
void dfs(int node)
{
if(used[node])return;
SZ_comp[comp]++;
which_comp[node]=comp;
used[node]=1;
for(auto k:adj[node])
    dfs(k);
}
int main()
{
cin>>n>>m;
int x,y;
for(int i=1;i<=m;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
for(int i=1;i<=n;i++)
    if(used[i]==0)
    {
    comp++;
    dfs(i);
    }
for(int i=1;i<=n;i++)
    paths_comp[which_comp[i]]+=adj[i].size();
int ans=0;
for(int i=1;i<=comp;i++)
    if(paths_comp[i]/2<SZ_comp[i])ans++;
cout<<ans<<endl;
return 0;
}