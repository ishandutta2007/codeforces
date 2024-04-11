// Lynkcat.
// Problem: A. NIT orz!
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/A
// Memory Limit: 512 MB
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
int n,m;
void BellaKira()
{
	cin>>n>>m;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans=max(ans,x|m);
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