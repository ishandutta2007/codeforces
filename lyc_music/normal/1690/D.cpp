// Lynkcat.
// Problem: D. Black and White Stripe
// URL: https://codeforces.com/contest/1690/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

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
#define  N 200005
using namespace std;
int n,m,s[N];
string st;
void BellaKira()
{
	cin>>n>>m;
	cin>>st;st=' '+st;
	for (int i=1;i<=n;i++)
		if (st[i]=='W') s[i]=s[i-1]+1;
		else s[i]=s[i-1];
		int ans=n;
	for (int i=1;i+m-1<=n;i++)
		ans=min(ans,s[i+m-1]-s[i-1]);
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