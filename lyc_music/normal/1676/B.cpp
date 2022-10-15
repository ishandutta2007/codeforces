// Lynkcat.
// Problem: B. Equal Candies
// URL: https://codeforces.com/contest/1676/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define N 20005
using namespace std;
int n,a[N];
void BellaKira()
{
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sm=0;
	for (int i=1;i<=n;i++)
		ans+=abs(a[1]-a[i]);
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