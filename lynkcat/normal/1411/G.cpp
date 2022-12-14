// LUOGU_RID: 93605804
// Lynkcat.
// Problem: C. No Game No Life
// Contest: Codeforces - 11.11
// URL: https://codeforces.com/gym/409566/problem/C
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
#define inf 1e9
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
int n,m;
poly G[N],all[N];
int sg[N];
int cnt1[N];
int dp[N];
int f[1005][1005];
int ru[N];
int cnt[N];
inline int calc(poly &g)
{
	for (auto u:g)
		cnt[u]++;
	int res=0;
	for (int i=0;;i++)
		if (!cnt[i])
		{
			res=i;
			break;
		}
	for (auto u:g)
		cnt[u]--;
	return res;
}	
inline int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	int z=quickPower(n+1,mod-2);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[y].push_back(x);
		ru[x]++;
	}
	queue<int>q;
	for (int i=1;i<=n;i++)
		if (!ru[i])
			q.push(i);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		sg[u]=calc(all[u]);cnt1[sg[u]]++;
		// cout<<"?"<<u<<" "<<sg[u]<<'\n';
		for (auto v:G[u])
		{
			ru[v]--;
			all[v].push_back(sg[u]);
			if (!ru[v]) q.push(v);
		}
	}
	for (int i=1;i<512;i++)
	{
		for (int j=0;j<512;j++)
		{
			f[i][j]=z*cnt1[i^j]%mod;
		}
		f[i][i]=(f[i][i]+mod-1)%mod;
	}
	for (int i=0;i<512;i++) f[0][i]=1;
	f[0][512]=1;
	// for (int i=0;i<512;i++)
	// {
		// for (int j=0;j<=512;j++)
		// {
			// cout<<f[i][j]<<" ";
		// }
		// cout<<'\n';
	// }
	for (int i=0;i<512;i++)
	{
		if (!f[i][i])
		{
			for (int j=i+1;j<512;j++)
				if (f[j][i])
				{
					for (int k=0;k<=512;k++)
						swap(f[i][k],f[j][k]);
					break;
				}
		}
		int nw=quickPower(f[i][i],mod-2);
		for (int j=0;j<=512;j++) f[i][j]=f[i][j]*nw%mod;
		for (int j=i+1;j<512;j++)
			if (i!=j)
			{
				int p=f[j][i];
				for (int k=0;k<=512;k++)
					f[j][k]=(f[j][k]-p*f[i][k]%mod+mod)%mod;
			}
	}
	// for (int i=0;i<512;i++)
	// {
		// for (int j=0;j<=512;j++)
		// {
			// cout<<f[i][j]<<" ";
		// }
		// cout<<'\n';
	// }
	int ans=0;
	for (int i=511;i>=0;i--)
	{
		dp[i]=f[i][512]*quickPower(f[i][i],mod-2);
		// if (dp[i])
			// cout<<i<<" "<<dp[i]<<'\n';
		if (i)
		ans=(ans+dp[i])%mod;
		for (int j=i-1;j>=0;j--)
			f[j][512]=(f[j][512]-(f[j][i]*dp[i]%mod)+mod)%mod;
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}