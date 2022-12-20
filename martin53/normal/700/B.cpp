#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,k;
vector<int> adj[nmax];
bool spec[nmax];
int SZ[nmax];
long long ans=0;
void dfs(int node,int par)
{
    SZ[node]=spec[node];
    for(auto k:adj[node])
    if(k!=par)
        {
            dfs(k,node);
            SZ[node]+=SZ[k];
        }
    ans=ans+min(SZ[node],2*k-SZ[node]);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
int x;
for(int i=1;i<=2*k;i++)
{
    cin>>x;
    spec[x]=1;
}
int y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
dfs(1,0);
cout<<ans<<endl;
return 0;
}