// Problem: A. Extremely Round
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/0
// Memory Limit: 512 MB
// Time Limit: 3000 ms

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
// #define N 
using namespace std;
void BellaKira()
{
	int ans=1;
	int n;
	cin>>n;
	for (int i=1;i<=n;i=i*10)
	{
		if (n>=i*10) ans+=10-1;
		else
		{
			ans+=n/i-1;
		}
		// cout<<i<<" "<<ans<<'\n';
	}
	cout<<ans<<'\n';
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