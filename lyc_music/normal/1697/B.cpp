// Lynkcat.
// Problem: B. Promo
// URL: https://codeforces.com/contest/1697/problem/B
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
#define N 2000005
using namespace std;
int n,q,a[N],s[N];
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		y=x-y;
		cout<<s[n-y]-s[n-x]<<endl;
	}


}
signed main()
{
	IOS;
	int T=1;
	// cin>>T;
	while (T--)
	{
		BellaKira();
	}
}