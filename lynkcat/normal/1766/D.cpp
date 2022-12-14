// Problem: D. Lucky Chains
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/D
// Memory Limit: 512 MB
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
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 10000005
using namespace std;
mt19937_64 rnd(time(0));
int n;
int tot[N];
int vis[N][10];
void BellaKira()
{
	cin>>n;
	map<pa,int>Mp;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		if (y-x==1) 
		{
			cout<<-1<<'\n';
			continue;
		}
		if (__gcd(x,y)!=1) 
		{
			cout<<0<<'\n';
			continue;
		}
		int z=y-x;
		int ans=inf;
		for (int j=1;j<=tot[z];j++)
		{
			int u=vis[z][j];
			ans=min(ans,(u-x%u)%u);
		}
		cout<<ans<<'\n';
	}
}
signed main()
{
	for (int i=2;i<N;i++)
		if (!tot[i])
		{
			for (int j=i;j<N;j+=i)
			{
				vis[j][++tot[j]]=i;
			}
		}
	// return 0;
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}