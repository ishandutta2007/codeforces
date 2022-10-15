// Lynkcat.
// Problem: A. Game with Cards
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/A
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
#define inf 1e18
#define mod 998244353
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	int mx=0,mx1=0;
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		mx=max(mx,x);
	}cin>>n;
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		mx1=max(mx1,x);
	}
	if (mx>=mx1) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
	// cout<<mx<<" "<<mx1<<endl;
	if (mx1>=mx) cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
	
	
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