// Lynkcat.
// Problem: E. Three Days Grace
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
#define N 5000005
using namespace std;
int n,m,mx[N],vs[N],cnt[N],a[N];
void BellaKira()
{
	cin>>n>>m;
	poly mx(m+1,m);
	int mn=inf;
	for (int i=1;i<=n;i++)
		cin>>a[i],vs[a[i]]=1,mn=min(mn,a[i]);
	
	for (int i=1;i<=m;i++)
		if (vs[i])
		{
			cnt[m]++;
		}
	int mxr=m;
	int ans=m;
	for (int i=m;i>=1;i--)
	{
		if (vs[i]) cnt[mx[i]]--;
		mx[i]=i;
		if (vs[i]) cnt[mx[i]]++;
		for (int j=1;j*i<=m;j++)
		{
			if (vs[i*j])
			{
				cnt[mx[i*j]]--;
			}
			mx[i*j]=min(mx[i*j],max(mx[j],i));
			if (vs[i*j])
			{
				cnt[mx[i*j]]++;
			}
		}
		while (!cnt[mxr])
		{
			mxr--;
		}
		if (i<=mn)
		ans=min(ans,mxr-i);
		// cout<<i<<" "<<mxr<<" "<<mx[i]<<" "<<mx[12]<<endl;
	}
	cout<<ans<<endl;
	for (int i=1;i<=m;i++) vs[i]=0,cnt[i]=0;
		
			
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