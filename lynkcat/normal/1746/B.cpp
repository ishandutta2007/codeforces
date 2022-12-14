// Problem: B. Rebellion
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.ml/contest/1746/problem/B
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
#define N 100005 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int x=0;
	for (int i=1;i<=n;i++) x+=a[i];
	int y=0;
	int ans=n-x;
	for (int i=1;i<=n;i++)
	{
		y+=a[i];
		ans=min(max(y,(n-x)-(i-y)),ans);
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}