// Lynkcat.
// Problem: A. Subrectangle Guess
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/0
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
#define N  1005
using namespace std;
int n,m,a[N][N];
void BellaKira()
{
	cin>>n>>m;
	int mx=-inf;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			mx=max(mx,a[i][j]);
		}
	}
	int ans=inf;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if (a[i][j]==mx)
			ans=min(ans,max(i,n-i+1)*max(j,m-j+1));
	cout<<ans<<endl;
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