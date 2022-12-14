// Lynkcat.
// Problem: C. Bricks and Bags
// Contest: Codeforces - Codeforces Round #831 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1740/problem/C
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
#define N 200005 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=a[3]-a[2]+a[3]-a[1];
	for (int i=3;i<=n;i++)
		ans=max(ans,a[i]-a[i-1]+a[i]-a[1]);
	for (int i=1;i+2<=n;i++)
		ans=max(ans,a[i+1]-a[i]+a[n]-a[i]);
	cout<<ans<<'\n';
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