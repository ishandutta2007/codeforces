// Lynkcat.
// Problem: A. Minimums and Maximums
// URL: https://codeforces.com/contest/1680/problem/A
// Memory Limit: 512 MB
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
	int l,r,L,R;
	cin>>l>>r>>L>>R;
	if (min(r,R)>=max(l,L)) cout<<max(l,L)<<endl;
	else
	{
		cout<<l+L<<endl;
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