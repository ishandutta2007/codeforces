// Problem: B. Maximum Substring
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/B
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
int n;
char a[N];
void BellaKira()
{
	cin>>n;
	int x=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],x+=a[i]-'0';
	int ans=x*(n-x);
	x=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i]!=a[i-1])
		{
			ans=max(ans,x*x);
			x=1;
		} else x++;
	}
	ans=max(ans,x*x);
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