// Problem: F. Chemistry Lab
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/F
// Memory Limit: 512 MB
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
#define double long double
#define int ll
#define N 5005
using namespace std;
int n,m;
double x[N],w[N],c[N],dp[N];
int p[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>w[i]>>c[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int x,int y)
	{
		return ::x[x]<::x[y];
	});
	double ans=0;
	for (int i=1;i<=n;i++)
	{
		int u=p[i];
		dp[i]=-w[u];
		for (int j=1;j<i;j++)
		{
			int v=p[j];
			dp[i]=max(dp[i],dp[j]+1.0*m*(x[u]-x[v])*(c[u]+c[v])/200-w[u]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<fixed<<setprecision(15)<<ans<<'\n';
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}