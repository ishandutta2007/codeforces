// Lynkcat.
// Problem: B. Triple
// URL: https://codeforces.com/contest/1669/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

//~~
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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	int ans=-1;
	map<int,int>Mp;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		Mp[x]++;
		if (Mp[x]>=3) ans=x;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}