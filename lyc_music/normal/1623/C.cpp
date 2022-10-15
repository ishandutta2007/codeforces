// Lynkcat.
// Problem: C. Balanced Stone Heaps
// URL: https://codeforces.com/contest/1623/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define N 2000005
using namespace std;
int a[N],b[N],n,m;
int chk(int x)
{
	int res=1;
	for (int i=1;i<=n;i++) b[i]=0;
	for (int i=n;i>=3;i--)
	{
		if (a[i]+b[i]<x) return 0;
		int now=min(a[i]/3,(a[i]+b[i]-x)/3);
		// cout<<"?"<<i<<" "<<now<<" "<<a[i]<<" "<<b[i]<<endl;
		b[i-2]+=now*2;
		b[i-1]+=now;
	}
	if (a[1]+b[1]<x) return 0;
	if (a[2]+b[2]<x) return 0;
	// cout<<"!"<<x<<endl;
	return 1;
}
	
				
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=1000000000;
	int ans=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (chk(mid))
		{
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<ans<<endl;
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}