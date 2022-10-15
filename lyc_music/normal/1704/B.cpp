// Lynkcat.
// Problem: B. Luke is a foodie
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/B
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
#define N 200005
using namespace std;
int n,m,a[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	int mn=a[1],mx=a[1];
	int ans=0;
	for (int i=2;i<=n;i++)
	{
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		if (mx-mn>2*m) 
		{
			ans++;
			mx=mn=a[i];
		}
	}
	cout<<ans<<'\n';
		
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