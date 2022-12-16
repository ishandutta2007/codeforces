#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,m;
int q;
pair<int,int> inp[nmax];
vector<int> adj[nmax];
bool been[nmax];
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    for(auto k:adj[node])
        dfs(k);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n>>m>>q;
for(int i=1;i<=q;i++)
{
cin>>inp[i].first>>inp[i].second;
inp[i].second+=n;
adj[inp[i].first].push_back(inp[i].second);
adj[inp[i].second].push_back(inp[i].first);
}

int ans=0;
for(int i=1;i<=n+m;i++)
    if(been[i]==0){dfs(i);ans++;}
cout<<ans-1<<endl;
return 0;
}