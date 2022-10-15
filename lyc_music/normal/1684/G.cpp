// Lynkcat.
// Problem: G. Euclid Guess
// URL: https://codeforces.com/contest/1684/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
#define N 1005
using namespace std;
int n,m,a[N];
poly G[N];
int mth[N];
int vis[N];
int dfs(int x)
{
	for (auto u:G[x])
	{
		if (vis[u]) continue;
		vis[u]=1;
		if (!mth[u])
		{
			mth[x]=u;
			mth[u]=x;
			return 1;
		}
		int v=dfs(mth[u]);
		if (!v) continue;
		mth[u]=x;
		mth[x]=u;
		return 1;
	}
	return 0;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
		if (a[i]*3>m)
		{
			if (a[i]*2>m) return cout<<-1<<endl,void();
			for (int j=1;j<=n;j++)
				if (a[j]<a[i]&&a[i]%a[j]==0&&(a[i]*2+a[j]<=m))
				{
					G[i].push_back(j);
				}
			memset(vis,0,sizeof(vis));
			int v=dfs(i);
			if (!v) return cout<<-1<<endl,void();
		}
		
	// for (int i=1;i<=n;i++) cout<<a[i]<<" "<<a[mth[i]]<<endl;
	vector<pa>ans;
	for (int i=1;i<=n;i++)
		if (mth[i]&&a[i]>a[mth[i]])
		{
			ans.push_back(mp(a[i]*2+a[mth[i]],a[i]+a[mth[i]]));
		} else 
		if (!mth[i])
		{
			ans.push_back(mp(a[i]*3,a[i]*2));
		}
	cout<<ans.size()<<endl;
	for (auto u:ans) 
		cout<<u.fi<<" "<<u.se<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}