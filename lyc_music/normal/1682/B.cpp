// Lynkcat.
// Problem: B. AND Sorting
// URL: https://codeforces.com/contest/1682/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
int n,a[N];
void BellaKira()
{
	poly G;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=i-1)
		{
			G.push_back(a[i]);
		}
	}
	int x=(1<<20)-1;
	for (auto u:G)
	{
		// cout<<u<<endl;
		x&=u;
	}
	cout<<x<<endl;
			
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