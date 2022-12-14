// Problem: G. Anti-Increasing Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/G
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
#define N 2005
using namespace std;
int n,m,a[N][N],b[N][N];
int lf[N],rt[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			char ch;
			cin>>ch;
			if (ch=='0') a[i][j]=0;
			else a[i][j]=1;
			b[i][j]=0;
		}
	for (int j=0;j<=n-m+1;j++) lf[j]=rt[j]=0;
	for (int tim=1,l=1;tim<=n-m+1;tim++)
	{
		while (l<=n&&!a[l][l])
		{
			l++;
		}
		if (l>n)  return cout<<"NO\n",void();
		b[l][l]=1;
		lf[0]=rt[0]=l;
		int x=l;
		for (int j=1;j<=n-m+1-tim;j++)
		{
			lf[j]=max(lf[j],lf[j-1]);
			x=lf[j];
			while (x+j<=n&&!a[x+j][x])
			{
				x++;
			}
			if (x+j>n) return cout<<"NO\n",void();
			b[x+j][x]=1;
			lf[j]=x;
		}
		int y=l;
		for (int j=1;j<=n-m+1-tim;j++)
		{
			rt[j]=max(rt[j],rt[j-1]);
			y=rt[j];
			while (y+j<=n&&!a[y][y+j])
			{
				y++;
			}
			if (y+j>n) return cout<<"NO\n",void();
			b[y][y+j]=1;
			rt[j]=y;
		}
		for (int j=1;j<=n-m+1-tim;j++)
			lf[j-1]=max(lf[j-1],lf[j]+1),rt[j-1]=max(rt[j-1],rt[j]+1);
		l=max(lf[0],rt[0]);
	}
	cout<<"YES\n";
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) cout<<(b[i][j]^1);
		cout<<'\n';
	}
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}