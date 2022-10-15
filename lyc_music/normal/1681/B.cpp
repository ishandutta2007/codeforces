// Lynkcat.
// Problem: B. Card Trick
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/B
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
#define N 200005
using namespace std;
int n,a[N],m;
void BellaKira()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	int x=0;
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		int y;
		cin>>y;
		x=(x+y)%n;
	}
	cout<<a[x]<<endl;
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