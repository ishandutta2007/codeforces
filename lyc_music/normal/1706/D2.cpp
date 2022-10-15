// Lynkcat.
// Problem: D1. Chopping Carrots (Easy Version)
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/D1
// Memory Limit: 64 MB
// Time Limit: 4000 ms

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
#define N 100005
using namespace std;
int n,m,a[N];
poly g[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		g[a[i]].push_back(i);
	}
	int ans=100000;
	int mn=a[1];
	for (int i=100000;i>=0;i--)
	{
		ans=min(ans,i-mn);
		// if (i-mn<=10) cout<<i<<" "<<mn<<endl;
		if (i==0)
		{
			g[i].clear();
			break;
		}
		bool bl=0;
		for (auto u:g[i])
		{
			int x=a[u]/i+1;
			if (x>m)
			{
				bl=1;
				break;
			}
			mn=min(mn,a[u]/x);
			// cout<<"?"<<a[u]<<" "<<i<<" "<<m<<" "<<a[i]/x<<endl;
			g[a[u]/x].push_back(u);
		}
		vector<int>().swap(g[i]);
		if (bl) break;
	}
	for (int i=100000;i>=0;i--) 
		vector<int>().swap(g[i]);
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