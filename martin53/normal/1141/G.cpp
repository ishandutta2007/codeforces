#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+42;
int n,k;
vector< pair<int/*to*/,int/*colour*/> > adj[nmax];
int order[nmax];
bool cmp(int a,int b)
{
    return adj[a].size()>adj[b].size();
}
int output[nmax];
bool bad[nmax];
void dfs(int node,int parent,int colour_in)
{
    int colour=1;
    while(colour==colour_in)colour++;

    for(auto k:adj[node])
        if(k.first!=parent)
        {
            if(bad[node])
            {
                output[k.second]=colour_in;
                dfs(k.first,node,colour_in);
            }
            else
            {
                output[k.second]=colour;
                dfs(k.first,node,colour);
                colour++;
                while(colour==colour_in)colour++;
            }
        }

}
int main()
{
cin>>n>>k;
int u,v;
for(int i=1;i<n;i++)
{
    cin>>u>>v;
    adj[u].push_back({v,i});
    adj[v].push_back({u,i});
}

for(int i=1;i<=n;i++)order[i]=i;
sort(order+1,order+n+1,cmp);

for(int i=1;i<=k;i++)bad[order[i]]=1;

dfs(order[k+1],0,0);

cout<<adj[order[k+1]].size()<<endl;
for(int i=1;i<n;i++)cout<<output[i]<<" ";cout<<endl;
return 0;
}