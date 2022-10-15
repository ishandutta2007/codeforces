// Lynkcat.
// Problem: C. Robot in a Hallway
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/C
// Memory Limit: 256 MB
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
#define N 200005
using namespace std;
int n,a[2][N],suf[2][N],suf1[2][N];
void BellaKira()
{
	cin>>n;
	// cout<<"??"<<endl;
	for (int i=0;i<=1;i++)
	{
		for (int j=1;j<=n;j++) cin>>a[i][j],a[i][j]++;
		suf[i][n+1]=-inf;
		for (int j=n;j>=1;j--) suf[i][j]=max(suf[i][j+1],a[i][j]-j);
		suf1[i][n+1]=-inf;
		for (int j=n;j>=1;j--) suf1[i][j]=max(suf1[i][j+1],a[i][j]+j);
	}
	a[0][1]--;
	// cout<<"??"<<endl;
	int ans=-1;
	for (int i=1;i<=n;i++)
	{
		ans=max(ans+1,a[0][i]);
	}
	for (int i=n;i>=1;i--)
	{
		ans=max(ans+1,a[1][i]);
	}
	// cout<<ans<<endl;
	int now=-1;
	for (int i=1;i<=n;i++)
	{
		if (i%2==1)
		{
			now=max(now+1,a[0][i]);
			now=max(now+1,a[1][i]);
			int nxt=now;
			// cout<<i<<","<<nxt<<endl;
			nxt=max(nxt,suf[1][i+1]+i)+(n-i);
			// cout<<i<<","<<nxt<<endl;
			nxt=max(nxt,suf1[0][i+1]-n-1)+(n-i);
			// cout<<i<<","<<nxt<<endl;
			ans=min(ans,nxt);
		} else
		{
			now=max(now+1,a[1][i]);
			now=max(now+1,a[0][i]);
			int nxt=now;
			// cout<<i<<","<<nxt<<endl;
			nxt=max(nxt,suf[0][i+1]+i)+(n-i);
			// cout<<i<<","<<nxt<<endl;
			nxt=max(nxt,suf1[1][i+1]-n-1)+(n-i);
			// cout<<i<<","<<nxt<<endl;
			ans=min(ans,nxt);
		}
	}
	ans=min(ans,now);
	cout<<ans<<endl;
		
}
signed main()
{
	// IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}