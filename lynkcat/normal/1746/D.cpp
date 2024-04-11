// Problem: D. Paths on the Tree
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.ml/contest/1746/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n,m;
poly G[N];
int s[N];
map<int,int>Mp[N];
int dfs(int k,int y)
{
	// cout<<"?"<<k<<" "<<y<<endl;
	if (y==0) return 0;
	if (Mp[k].count(y)) return Mp[k][y];
	int &res=Mp[k][y];
	poly x;
	res=y*s[k];
	if (G[k].size()==0) return res;
	for (auto u:G[k])
	{
		res+=dfs(u,y/G[k].size());
	}
	if (y%G[k].size()==0) return res;
	for (auto u:G[k])
		x.push_back(dfs(u,y/G[k].size()+1)-dfs(u,y/G[k].size()));
	sort(x.begin(),x.end());
	for (int i=1;i<=y%G[k].size();i++) res+=x.back(),x.pop_back();
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		G[x].push_back(i);
	}
	for (int i=1;i<=n;i++)
		cin>>s[i];
	cout<<dfs(1,m)<<'\n';
	for (int i=1;i<=n;i++) poly().swap(G[i]),Mp[i].clear();
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}