// Lynkcat.
// Problem: E. Sending a Sequence Over the Network
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/E
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
#define inf 1e9
#define mod 998244353
#define int ll
#define N  200005
using namespace std;
int n,dp[N],a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) dp[i]=0,cin>>a[i];
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (dp[i-1])
		{
			if (i+a[i]<=n) dp[i+a[i]]=1;
		}
		if (i-a[i]-1>=0)
			dp[i]|=dp[i-a[i]-1];
		// cout<<i<<" "<<dp[i]<<endl;
	}
	if (dp[n]) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}