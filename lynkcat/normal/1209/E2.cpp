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
#define N 12 
using namespace std;
int n,m,a[N][2005];
int g[(1<<N)],dp[(1<<N)];
int p[2005];
int mx[2005];
void BellaKira()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	for (int j=0;j<(1<<n);j++) dp[j]=-inf;
	dp[0]=0;
	for (int i=1;i<=m;i++)
	{
		p[i]=i;
		mx[i]=0;
		for (int j=0;j<n;j++)
			mx[i]=max(mx[i],a[j][i]);
		// cout<<i<<" "<<mx[i]<<endl;
	}
	sort(p+1,p+m+1,[&](int x,int y)
	{
		return mx[x]>mx[y];
	});
	for (int i=1;i<=min(n,m);i++)
	{
		int u=p[i];
		for (int j=0;j<(1<<n);j++)
		{
			g[j]=0;
			for (int k=0;k<n;k++)
			{
				int now=0;
				for (int x=0;x<n;x++)
					if ((j>>x)&1)
						now=(now+a[(x+k)%n][u]);
				g[j]=max(g[j],now);
			}
		}
		for (int j=(1<<n)-1;j>=0;j--)
			for (int k=(1<<n)-1-j;k;k=(k-1)&((1<<n)-1-j))
			{
				// cout<<j<<" "<<k<<" "<<dp[j]<<" "<<g[k]<<endl;
				dp[j+k]=max(dp[j+k],dp[j]+g[k]);
			}
	}
	cout<<dp[(1<<n)-1]<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}