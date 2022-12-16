#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,m,k;
vector<int> adj[nmax];
bool been[nmax];
vector<int> t;
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    t.push_back(node);
    for(auto p:adj[node])
        if(been[p]==0)
        {
        dfs(p);
        t.push_back(node);
        }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m>>k;
int x,y;
for(int i=1;i<=m;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
dfs(1);
int p=0,SZ=t.size(),cmax=(2*n+k-1)/k;
for(int i=1;i<=k;i++)
{
    if(p==SZ)
    {
        cout<<1<<" "<<1<<endl;
        continue;
    }
    int now=min(SZ-p,cmax);
    cout<<now;
    for(int j=1;j<=now;j++)
    {
        cout<<" "<<t[p];
        p++;
    }
    cout<<endl;
}
return 0;
}