// Lynkcat.
// Problem: D. Magical Array
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/D
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
int n,m;
pa a[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int x=0;
		int sm=0;
		for (int j=1;j<=m;j++)
		{
			int y;cin>>y;
			x+=y;
			sm+=x;
		}
		a[i]=mp(sm,i);
		// cout<<i<<","<<sm<<endl;
	}
	sort(a+1,a+n+1);
	cout<<a[1].se<<" "<<a[n].fi-a[1].fi<<endl;
	
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