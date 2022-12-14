// Lynkcat.
// Problem: B. Increasing
// Contest: Codeforces - Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/B
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
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int ans=0;
	int n;
	map<int,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if (Mp[x])
			ans=1;
		Mp[x]=1;
	}
	if (ans) cout<<"NO\n";
	else cout<<"YES\n";
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