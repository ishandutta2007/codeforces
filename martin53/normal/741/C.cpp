#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
pair<int,int> p[nmax];
vector<int> adj[nmax];
int been[nmax];
void dfs(int node,int col)
{
    if(been[node])return;
    been[node]=col;
    for(auto k:adj[node])
        dfs(k,3-col);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n;
for(int i=1;i<=n;i++)
{
cin>>p[i].first>>p[i].second;
adj[p[i].first].push_back(p[i].second);
adj[p[i].second].push_back(p[i].first);
}

for(int i=1;i<=2*n;i=i+2)
    adj[i].push_back(i+1),adj[i+1].push_back(i);

for(int i=1;i<=2*n;i++)
    if(been[i]==0)
        dfs(i,1);

for(int i=1;i<=n;i++)
    cout<<been[p[i].first]<<" "<<been[p[i].second]<<endl;
return 0;
}