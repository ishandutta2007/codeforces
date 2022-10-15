// Lynkcat.
// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/F
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
int n,a[N],s[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]<i) s[i]=1;
		else s[i]=0;
		s[i]=s[i-1]+s[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=i) continue;
		int x=n;
		if (a[i]-1<x) x=a[i]-1;
		if (x<=0) continue;
		ans+=s[x];
		// cout<<i<<" "<<s[i]<<endl;
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