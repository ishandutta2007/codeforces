// Lynkcat.
// Problem: A. Plus One on the Subset
// URL: https://codeforces.com/contest/1624/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define int ll
//#define N
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	vector<int>a(n+5,0);
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int mn=inf,mx=-inf;
	for (int i=1;i<=n;i++)
		mx=max(mx,a[i]),mn=min(mn,a[i]);
	cout<<mx-mn<<endl;
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