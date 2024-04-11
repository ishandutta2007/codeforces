// Lynkcat.
// Problem: D. Lena and Matrix
// URL: https://codeforces.com/contest/1689/problem/D
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
#define N 1005
using namespace std;
int n,m,zs[N][N],zx[N][N],ys[N][N],yx[N][N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if (ch=='B')
			{
				zs[i][j]=-i-j;
				zx[i][j]=i-j;
				ys[i][j]=-i+j;
				yx[i][j]=i+j;
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			zs[i][j]=max({zs[i-1][j],zs[i][j-1],zs[i][j]});
		}
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)
		{
			zx[i][j]=max({zx[i][j-1],zx[i+1][j],zx[i][j]});
		}
	for (int i=1;i<=n;i++)
		for (int j=m;j>=1;j--)
			ys[i][j]=max({ys[i][j],ys[i][j+1],ys[i-1][j]});
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
			yx[i][j]=max({yx[i][j],yx[i+1][j],yx[i][j+1]});
	int ans=inf,ansx=0,ansy=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int now=max({i+j+zs[i][j],-i+j+zx[i][j],i-j+ys[i][j],-i-j+yx[i][j]});
			if (ans>now)
			{
				ans=now;
				ansx=i,ansy=j;
			}
			zs[i][j]=zx[i][j]=ys[i][j]=yx[i][j]=zs[0][0];
		}
	cout<<ansx<<" "<<ansy<<" "<<endl;
		
	
}
signed main()
{
	memset(zs,-0x3f,sizeof(zs));
	memset(zx,-0x3f,sizeof(zx));
	memset(ys,-0x3f,sizeof(ys));
	memset(yx,-0x3f,sizeof(yx));
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}