// Lynkcat.
// Problem: D. Coprime
// Contest: Codeforces - Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
// #define N 
using namespace std;
int a[200005];
void BellaKira()
{
	int n;
	map<int,int>Mp;
	cin>>n;
	int ans=-1;
	for (int i=1;i<=n;i++)
		cin>>a[i],Mp[a[i]]=i;
	for (auto u:Mp)
		for (auto v:Mp)
			if (__gcd(u.fi,v.fi)==1)
			{
				ans=max(ans,u.se+v.se);
			}
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