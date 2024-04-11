// Lynkcat.
// Problem: A. Beat The Odds
// URL: https://codeforces.com/contest/1691/problem/A
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
//#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	int x=0;
	for (int i=1;i<=n;i++)
	{
		int y;
		cin>>y;
		x+=y&1;
	}
	cout<<min(x,n-x)<<endl;
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