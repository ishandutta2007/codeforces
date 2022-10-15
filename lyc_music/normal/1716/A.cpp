// Lynkcat.
// Problem: A. 2-3 Moves
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/0
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
	cin>>n;
	if (n==1)
	{
		cout<<2<<endl;
	} else
	{
			cout<<(n+2)/3<<endl;
	}
		
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