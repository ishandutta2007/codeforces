// Problem: C. Wish I Knew How to Sort
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/C
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
// #define N 
using namespace std;
int n,a[200005];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	int x=0,y=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],x+=(a[i]==0);
	for (int i=1;i<=x;i++)
		y+=(a[i]==1);
	int ans=0;
	for (int i=1;i<=y;i++)
	{
		int V=n*(n-1)/2;
		V%=mod;V=V*quickPower(i*i%mod,mod-2)%mod;
		// cout<<i<<" "<<V<<'\n';
		ans=(ans+V)%mod;
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