// Lynkcat.
// Problem: D. Inconvenient Pairs
// URL: https://codeforces.com/contest/1569/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define N 300005
using namespace std;
int n,m,q;
int x[N],y[N];
int c[N];
poly sum[N],sum1[N];
void BellaKira()
{
	int ans=0;
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
		cin>>x[i];
	for (int i=1;i<=m;i++)
		cin>>y[i];
	for (int i=1;i<=q;i++)
	{
		int nowx,nowy;
		cin>>nowx>>nowy;
		int o=upper_bound(x+1,x+n+1,nowx)-x-1;
		int p=upper_bound(y+1,y+m+1,nowy)-y-1;
		if (x[o]==nowx) 
		{
			if (y[p]==nowy) continue;
			sum[p].push_back(o);
			continue;
		}
		sum1[o].push_back(p);
	}
	
	for (int i=1;i<=m;i++)
	{
		int now=0;
		ans+=1ll*sum[i].size()*(sum[i].size()-1)/2;
		// cout<<"?"<<i<<" "<<ans<<endl;
		for (auto u:sum[i])
		{
			ans-=c[u];
			c[u]++;
		} 
		// cout<<"?"<<i<<" "<<ans<<endl;
		for (auto u:sum[i]) c[u]--;
		sum[i].clear();
	}
	for (int i=1;i<=n;i++)
	{
		int now=0;
		ans+=1ll*sum1[i].size()*(sum1[i].size()-1)/2;
		for (auto u:sum1[i])
		{
			ans-=c[u];
			c[u]++;
		} 
		for (auto u:sum1[i]) c[u]--;
		sum1[i].clear();
	}
	for (int i=1;i<=max(n+1,m+1);i++) sum[i].clear(),sum1[i].clear();
	cout<<ans<<endl;
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