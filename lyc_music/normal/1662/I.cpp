// Problem: I. Ice Cream Shop
// URL: https://codeforces.com/contest/1662/problem/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// //
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
#define N 200005
using namespace std;
int n,m,p[N],s[N],a[N];
int x[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		cin>>p[i];
		s[i]=s[i-1]+p[i];
		x[i]=(i-1)*100;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	// a[0]=-inf;
	// a[m+1]=inf;
	int ans=0;
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++)
		if((i*100)-100<a[1]) ans=max(ans,s[i]);
	for(int i=1;i<=n;i++)
		if ((i*100)-100>a[m]) ans=max(ans,s[n]-s[i-1]);
	for(int i=1;i<m;i++)
	{
		int l=a[i],r=a[i+1];
		int xl=upper_bound(x+1,x+n+1,l)-x,xr=lower_bound(x+1,x+n+1,r)-x-1,mx=0;
		if	(xl>xr)
			continue;
		for(int j=xl;j<=xr;j++)
			ans=max(ans,s[j]-s[upper_bound(x+1,x+n+1,max(x[j]-(r-l+1)/2,l))-x-1]);
	}
	cout<<ans<<endl;
	
}
signed main()
{
	int T=1;
	IOS;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/