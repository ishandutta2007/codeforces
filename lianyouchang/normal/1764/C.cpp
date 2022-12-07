// Problem: C. Doremy's City Construction
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/C
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
#define inf 1e18
#define mod 998244353
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	map<int,int>Mp;
	int n;
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		Mp[x]++;
	}
	if (Mp.size()==1)
	{
		return cout<<n/2<<'\n',void();
	}
	int s=n;
	int x=0;
	for (auto u:Mp)
	{
		x+=u.se;
		s-=u.se;
		ans=max(ans,x*s);
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