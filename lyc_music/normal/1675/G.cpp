// Lynkcat.
// Problem: G. Sorting Pancakes
// URL: https://codeforces.com/contest/1675/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

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
#define N 255
using namespace std;
int n,m,a[N];
int f[N][N][N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
	}
	for (int i=1;i<=n-i+1;i++)
		swap(a[i],a[n-i+1]);
	for (int i=1;i<=n;i++) a[i]=a[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			int mn=inf;
			for (int k=0;j+k<=m;k++)
			{
				mn=min(mn,f[i-1][j][k]);
				f[i][j+k][k]=min(f[i][j+k][k],mn+abs(a[i]-(j+k)));
				// cout<<i<<" "<<j+k<<" "<<k<<" "<<f[i][j+k][k]<<endl;
			}
		}
	}
	int ans=inf;
	for (int i=1;i<=m;i++)
		ans=min(ans,f[n][m][i]);
	cout<<ans<<endl;
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}