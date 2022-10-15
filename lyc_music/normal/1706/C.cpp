// Lynkcat.
// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
#define N 100005 
using namespace std;

int n,a[N],pre[N],suf[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int x=(n-1)/2;
	int ans=0;
	for (int i=2;i<n;i+=2)
	{
		ans+=max(max(a[i-1],a[i+1])-a[i]+1,0ll);
	}
	if (n%2==0)
	{
		for(int i=3;i<=n-1;i+=2)
		{
			pre[i]=pre[i-2];
			pre[i]+=max(max(a[i-2],a[i])-a[i-1]+1,0ll);
		}
		suf[n]=0;
		for (int i=n-2;i>=2;i-=2)
		{
			suf[i]=suf[i+2];
			suf[i]+=max(max(a[i],a[i+2])-a[i+1]+1,0ll);
		}
		ans=suf[2];
		for (int i=3;i<=n-1;i+=2)
		{
			ans=min(ans,pre[i]+suf[i+1]);
			// cout<<i<<","<<pre[i]+suf[i+1]<<" "<<suf[2]<<endl;
		}
		
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