// Lynkcat.
// Problem: CF1466E Apollo versus Pan
// URL: https://www.luogu.com.cn/problem/CF1466E
// Memory Limit: 250 MB
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
#define mod 1000000007
#define int ll
#define N 500005
using namespace std;
int n,a[N],pre[N],suf[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=0,suf[i]=0;
	}
	for (int j=0,x=1;j<=60;j++,x=x*2%mod)
	{
		int f=0;
		for (int i=1;i<=n;i++)
			if ((a[i]>>j)&1)
			{
				f=(f+1)%mod;
			}
		for (int i=1;i<=n;i++)
			if ((a[i]>>j)&1)
			{
				// cout<<"?"<<j<<","<<i<<" "<<f<<endl;
				pre[i]=(pre[i]+x*f%mod)%mod;
			}
	}
	for (int j=0,x=1;j<=60;j++,x=x*2%mod)
	{
		int f=0;
		for (int i=n;i>=1;i--)
		{
			if ((a[i]>>j)&1)
			{
				f=(f+1)%mod;
			}
		}
		for (int i=1;i<=n;i++)
		{
			if ((a[i]>>j)&1)
				suf[i]=(suf[i]+x*n%mod)%mod;
			else
				suf[i]=(suf[i]+x*f%mod)%mod;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) 
	{
		// cout<<i<<" "<<pre[i]<<" "<<suf[i]<<endl;
		ans=(ans+pre[i]*suf[i]%mod)%mod;
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