// Problem: K. Torus Path
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/K
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
#define int ll
#define N 205
using namespace std;
int n,a[N][N],s[N][N],f[N][N],ans;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			s[i][j]=s[i][j-1]+a[i][j];
		}
	memset(f,-0x3f,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[1][i]=s[1][i]+s[2][n]-s[2][i-1];
		if (i==n-1) ans=max(ans,f[1][i]);
	}
	for (int i=2;i<n;i++)
		for (int x=1;x<=n;x++)
		{
			for (int y=x+1;y<=n;y++)
				f[i][x]=max(f[i][x],f[i-1][y]+s[i][x]+s[i+1][n]-s[i+1][x-1]);
			if (i==n-1) ans=max(ans,f[i][x]);
		}
	
	for (int i=1;i<=n-i+1;i++)
		for (int j=1;j<=n-j+1;j++)
			swap(a[i][j],a[n-i+1][n-j+1]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			s[i][j]=s[i][j-1]+a[i][j];
	memset(f,-0x3f,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[1][i]=s[1][i]+s[2][n]-s[2][i-1];
		if (i==n-1) ans=max(ans,f[1][i]);
	}
	for (int i=2;i<n;i++)
		for (int x=1;x<=n;x++)
		{
			for (int y=x+1;y<=n;y++)
				f[i][x]=max(f[i][x],f[i-1][y]+s[i][x]+s[i+1][n]-s[i+1][x-1]);
			if (i==n-1) ans=max(ans,f[i][x]);
		}
	cout<<ans<<'\n';
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