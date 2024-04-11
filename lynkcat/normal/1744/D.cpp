// Lynkcat.
// Problem: D. Divisibility by 2^n
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/D
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
#define inf 1e9
#define mod 998244353
#define int ll
#define N 200005 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	int sm=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		while (a[i]%2==0) a[i]/=2,sm++;
	}
	int ans=0;
	poly g;
	for (int i=n;i>=1;i--)
	{
		int o=i;
		int x=0;
		while (o%2==0) o/=2,x++;
		g.push_back(x);
		// cout<<i<<" "<<sm<<" "<<ans<<endl;
	}
	sort(g.begin(),g.end(),greater<int>());
	for (auto u:g)
	{
		if (sm>=n) break;
		sm+=u;
		ans++;
	}
	if (sm<n) cout<<"-1\n";
	else cout<<ans<<'\n';
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