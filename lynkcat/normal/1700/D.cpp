// Lynkcat.
// Problem: D. River Locks
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/D
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
int n,a[N],s[N],q;
void BellaKira()
{
	cin>>n;
	int mn=-inf;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		mn=max((s[i]+i-1)/i,mn);
	}
	// cout<<"?"<<mn<<endl;
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		if (x<mn) cout<<-1<<endl;
		else cout<<(s[n]+x-1)/x<<endl;
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}