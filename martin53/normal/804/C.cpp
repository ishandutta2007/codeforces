#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,m;
vector< int > colour[nmax];
vector< int > adj[nmax];
int output[nmax];
bool been[nmax];
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    set<int> seen={};
    for(auto k:colour[node])
        if(output[k])seen.insert(output[k]);
    int now=1;
    for(auto k:colour[node])
        if(output[k]==0)
        {
            while(seen.count(now))now++;
            output[k]=now;
            now++;
        }
    for(auto k:adj[node])
        dfs(k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n>>m;
    int x,y,s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=s;j++)
        {
            cin>>x;
            colour[i].push_back(x);
        }
    }
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ind=1;
    for(int i=2;i<=n;i++)
        if(colour[ind].size()<colour[i].size())ind=i;
    dfs(ind);
    cout<<max(1u,colour[ind].size())<<endl;
    for(int i=1;i<=m;i++)
        cout<<max(1,output[i])<<" ";cout<<endl;
}