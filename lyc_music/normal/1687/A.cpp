// Lynkcat.
// Problem: A. The Enchanted Forest
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/0
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
#define N  200005
using namespace std;
int n,m;
int a[N];
int s[N];
void BellaKira()
{
	cin>>n>>m;
	int sm=0;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		sm+=a[i]+i-1;
	}
	for (int i=min(m,n);i<=n;i++)
		ans=max(ans,s[i]-s[i-min(n,m)]);
	cout<<ans+(m-1+m-min(n,m))*min(n,m)/2<<endl;
		
		
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