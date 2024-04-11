// Lynkcat.
// Problem: A. Tokitsukaze and Strange Inequality
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/0
// Memory Limit: 256 MB
// Time Limit: 1500 ms

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
#define N 5005
using namespace std;
int n,a[N],s[N][N];
int ans;
int qry(int x,int l,int r,int tp)
{
	if (l>r) return 0;
	if (tp==1)
	{
		return s[r][x-1]-s[l-1][x-1];
	}
	if (tp==0)
	{
		return (s[r][n]-s[r][x])-(s[l-1][n]-s[l-1][x]);
	}
}
void BellaKira()
{
	ans=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			s[i][j]=s[i-1][j]+(a[i]<=j);
	}
	for (int i=1;i<=n;i++)
	{
		int sm=0;
		// sm+=qry(i+1,i+3,n,1);
		for (int j=i+2;j<=n;j++)
		{
			sm+=qry(a[j-1],j,n,1);
			sm-=qry(a[j],i+1,j-1,0);
			if (a[j]>a[i])
			ans+=sm;
			// cout<<i<<" "<<j<<" "<<ans<<" "<<sm<<" "<<qry(j-1,j,n,1)<<" "<<qry(j,i+1,j-1,0)<<endl;
		}
	}
	cout<<ans<<endl;
			
			
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}