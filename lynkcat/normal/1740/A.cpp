// Lynkcat.
// Problem: A. Factorise N+M
// Contest: Codeforces - Codeforces Round #831 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1740/problem/A
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
	int n;
	cin>>n;
	if (n%2==1) cout<<3<<'\n';
	else cout<<2<<'\n';
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