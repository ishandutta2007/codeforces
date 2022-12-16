#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,m;
vector< int > adj[nmax];
map< pair<int,int>, bool> there;
bool been[nmax];
int parent[nmax];
pair<int,int> edges[nmax];
int d[nmax];
int dfs(int node,int par)
{
    if(been[node])return 0;
    been[node]=1;
    int sum=d[node];
    for(auto k:adj[node])
        sum=sum+dfs(k,node);
    if(sum%2==1)
        {
        //cout<<node<<" "<<par<<endl;
        there[{par,node}]=1;
        there[{node,par}]=1;
        }
    return sum;
}
vector<int> output;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>d[i];
int x,y;
for(int i=1;i<=m;i++)
{
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    edges[i]={x,y};
}
int _=0,one=0;
for(int i=1;i<=n;i++)
    if(d[i]==-1)_=i;
    else if(d[i]==1)one++;
if(one%2==1)
{
    if(_==0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    d[_]=1;
}
for(int i=1;i<=n;i++)
    if(d[i]==-1)d[i]=0;

dfs(1,0);

for(int i=1;i<=m;i++)
{
    int x=edges[i].first,y=edges[i].second;
    if(there.count({x,y})&&there[{x,y}])
    {
        output.push_back(i);
        there[{x,y}]=0;
        there[{y,x}]=0;
    }
}
cout<<output.size()<<endl;
for(auto k:output)cout<<k<<" ";cout<<endl;
return 0;
}