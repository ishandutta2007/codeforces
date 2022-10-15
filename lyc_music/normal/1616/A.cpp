// Lynkcat.
// Problem: A. Integer Diversity
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/A
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
	int n;
	map<int,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		Mp[abs(x)]++;
	}
	int ans=0;
	for (auto u:Mp)
	{
		ans++;
		if (u.se>1&&u.fi!=0) ans++;
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