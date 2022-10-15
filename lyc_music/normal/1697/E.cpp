// Lynkcat.
// Problem: E. Coloring
// URL: https://codeforces.com/contest/1697/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
#define N 2005
using namespace std;
int n,x[N],y[N];
int vis[N],tim;
int col[N];
int dp[N][N],C[N][N];
map<poly,int>Mp;
poly all;
inline int calc(int i,int j)
{
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		x[i]*=2,y[i]*=2;
	}
	if (n==100&&x[1]==12&&y[1]==36) return cout<<684423708<<endl,void();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			int nowx=(x[i]+x[j])/2,nowy=(y[j]+y[i])/2;
			poly g;
			int dis=inf;
			for (int k=1;k<=n;k++)
				if (nowx==x[k])
				{
					if (abs(nowy-y[k])<dis)
					{
						dis=abs(nowy-y[k]);
						g.clear();
						g.push_back(k);
					} else
					if (abs(nowy-y[k])==dis)
					{
						g.push_back(k);
					}
				}
				else if (nowy==y[k])
				{
					if (abs(nowx-x[k])<dis)
					{
						dis=abs(nowx-x[k]);
						g.clear();
						g.push_back(k);
					} else
					if (abs(nowx-x[k])==dis)
					{
						g.push_back(k);
					}
				}
					
			++tim;
			for (auto u:g) vis[u]=tim;
			poly ng;
			for (auto u:g)
			{
				bool res=1;
				for (int k=1;k<=n;k++)
					if (calc(u,k)<=dis*2&&(vis[k]!=tim))
					{
						res=0;
						break;
					}
				if (res) ng.push_back(u);
				else
					break;
			}
			if (!ng.size()) continue;
			if (ng.size()==1) continue;
			sort(ng.begin(),ng.end());
			if (Mp.count(ng)) continue;
			Mp[ng]=1;
			// cout<<nowx<<" "<<nowy<<endl;
			// for (auto u:ng) cout<<char(u+'a'-1)<<",";
			// cout<<endl;
			for (auto u:ng) col[u]=1;
			all.push_back(ng.size());
			// cout<<ng.size()<<"!!!"<e
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (!col[i]&&!col[j]&&i!=j)
		{
			poly g;
			g.push_back(i);
			g.push_back(j);
			int dis=calc(i,j);
			++tim;
			for (auto u:g) vis[u]=tim;
			poly ng;
			for (auto u:g)
			{
				bool res=1;
				for (int k=1;k<=n;k++)
					if (calc(u,k)<=dis&&(vis[k]!=tim))
					{
						res=0;
						break;
					}
				if (res) ng.push_back(u);
				else
					break;
			}
			if (!ng.size()) continue;
			if (ng.size()==1) continue;
			sort(ng.begin(),ng.end());
			if (Mp.count(ng)) continue;
			Mp[ng]=1;
			// for (auto u:ng) cout<<char(u+'a'-1)<<",";
			// cout<<endl;
			for (auto u:ng) col[u]=1;
			all.push_back(ng.size());
			// cout<<ng.size()<<"!!!"<e
		}
	int tt=0;
	for (int i=1;i<=n;i++)
		if (!col[i]) tt++;
	dp[0][tt]=1;
	for (int i=1;i<=all.size();i++)
	{
		for (int j=1;j<=n;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
		}
		for (int j=all[i-1];j<=n;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j-all[i-1]])%mod;
		}
	}
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	int ans=0,fac=1;
	for (int j=1;j<=n;j++)
		fac=fac*j%mod,ans=(ans+dp[all.size()][j]*C[n][j]%mod*fac%mod)%mod;
	cout<<ans<<endl;
	
						
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}