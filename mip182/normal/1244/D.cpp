#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;
vector <vector <int> > g;
vector <int> path;
vector <bool> used;

void dfs(int s)
{
path.pb(s);
used[s]=1;
for (auto to:g[s])
{
if (used[to]==0){
dfs(to);
}
}
}

int main() {
mipletsplay;
int n;
cin>>n;
used=vector <bool>(n,false);
g=vector <vector <int> >(n);
vector <ll> c[3];
c[0].resize(n);
c[1].resize(n);
c[2].resize(n);
for (int i=0;i<3;i++)
{
for (int j=0;j<n;j++)
cin>>c[i][j];
}
for (int i=0;i<n-1;i++)
{
int x,y;
cin>>x>>y;
x--,y--;
g[x].pb(y);
g[y].pb(x);
}
for (int i=0;i<n;i++)
{
if (g[i].size()>2)
{
cout<<-1;
return 0;
}
}
int a=INF,b=-1;
for (int i=0;i<n;i++)
{
if (g[i].size()==1)
{
a=min(a,i);
b=max(b,i);
}
}
dfs(a);
vector <pair <ll,vector <int> > > costs;
for (int i=0;i<3;i++)
{
for (int j=0;j<3;j++)
{
if (i!=j)
{
ll sum=0;
vector <int> color(n);
sum+=c[i][path[0]]+c[j][path[1]];
color[path[0]]=i;
color[path[1]]=j;
for (int i=2;i<n;i++)
{
color[path[i]]=1+2-color[path[i-1]]-color[path[i-2]];
sum+=c[color[path[i]]][path[i]];
}
costs.pb({sum,color});

}
}
}
sort(costs.begin(),costs.end());
cout<<costs[0].first<<endl;
for (int i=0;i<costs[0].second.size();i++)
cout<<costs[0].second[i]+1<<" ";}