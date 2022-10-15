// Lynkcat.
// Problem: F. Eating Candies
// URL: https://codeforces.com/contest/1669/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
//#define N
using namespace std;
int a[200005];
void BellaKira()
{
	int ans=0;
	int n;
	cin>>n;
	int l=0,r=n+1;
	int sm=0,sm1=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	while (l<r)
	{
		while (r-1>l&&sm1+a[r-1]<=sm)
		{
			sm1+=a[r-1];
			r--;
		}
		if (sm==sm1) ans=max(ans,l+n-r+1);
		// cout<<l<<","<<r<<" "<<ans<<" "<<sm<<" "<<sm1<<endl;
		l++;
		sm+=a[l];
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}