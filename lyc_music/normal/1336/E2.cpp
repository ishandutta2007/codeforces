// Problem: CF1336E2 Chiori and Doll Picking (hard version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1336E2
// Memory Limit: 500 MB
// Time Limit: 3000 ms

//~~
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
#define N 55
using namespace std;
int f[N],C[N][N];
int tot;
int g[N];
poly G;
int ans[N];
int gg[N][N];
int a[200005];
int n,m;
int ff[N];
int quickPower(int x,int y)
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
void ins(int x)
{
	for (int j=m-1;j>=0;j--)
		if ((x>>j)&1)
		{
			if (!f[j])
			{
				f[j]=x;
				// cout<<j<<" "<<x<<endl;
				tot++;
				break;
			} else
			{
				x=x^f[j];
			}
		}
}
void work()
{
	for (int i=m-1;i>=0;i--)
	{
		if (!f[i]) continue;
		for (int j=i+1;j<m;j++)
			if ((f[j]>>i)&1)
				f[j]^=f[i];
	}
	for (int i=0;i<m;i++)
	{
		if (!f[i])
		{
			g[i]=(1ll<<i);
			for (int j=0;j<m;j++)
				if (f[j])
				{
					if ((f[j]>>i)&1) g[i]|=(1ll<<j);
				}
			G.push_back(g[i]);
		}
		// cout<<i<<" "<<f[i]<<" "<<g[i]<<endl;
	}
	
}
void dfs(int k,int x)
{
	if (k==G.size())
	{
		ff[__builtin_popcountll(x)]++;
		return;
	}
	dfs(k+1,x);
	dfs(k+1,x^G[k]);
}
void BellaKira()
{
	cin>>n>>m;
	C[0][0]=1;
	for (int i=1;i<=m;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int i=1;i<=n;i++) cin>>a[i],ins(a[i]);
	if (tot<=26)
	{
		for (int i=0;i<m;i++) 
			if (f[i]) G.push_back(f[i]);
		dfs(0,0);	
		for (int i=0;i<=m;i++)
			ans[i]=ff[i];
	} else
	{
		work();
		dfs(0,0);
		for (int i=0;i<=m;i++)
			for (int j=0;j<=m;j++)
			{
				int now=0,x=1;
				for (int k=0;k<=i;k++)
				{
					now=(now+x*C[j][k]%mod*C[m-j][i-k]%mod)%mod;
					x=mod-x;
				}
				gg[i][j]=now;
			}
		for (int i=0;i<=m;i++)
			for (int j=0;j<=m;j++)
			{
				ans[j]=(ans[j]+ff[i]*gg[j][i]%mod)%mod;
			}
		for (int i=0;i<=m;i++)
			ans[i]=(ans[i]*quickPower(2,tot)%mod*(quickPower(quickPower(2,m),mod-2))%mod)%mod;
	}
	for (int i=0;i<=m;i++) 
		cout<<ans[i]*quickPower(2,n-tot)%mod<<" ";
	cout<<endl;
					
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/