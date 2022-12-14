// Lynkcat.
// Problem: D2. Tree Queries (Hard Version)
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
poly G[N];
int dp[N];
int ans;
int len;
int n;
int vis[N];
int sum[N],mn[N],mn1[N];
map<int,int>Mp;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	len++;
	int tt=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		tt++;
	}
	if (tt!=1)
	{
		Mp[k]++;
		return;
	}
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
void BellaKira()
{
	cin>>n;
	if (n==1)
	{
		return cout<<0<<endl,void();
	}
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		ad(x,y);
		ad(y,x);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (G[i].size()==1)
		{
			len=0;
			dfs(i,0);
			if (len==n)
			{
				cout<<1<<endl;
				ans=-1;
				break;
			}
			ans++;
		}
	if (ans!=-1)
		cout<<ans-(int)Mp.size()<<endl;
	Mp.clear();
	for (int i=1;i<=n;i++) G[i].clear();
	
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}