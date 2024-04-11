// Lynkcat.
// Problem: B. Optimal Reduction
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/B
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
int n,f[N],g[N],a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)  f[i]=g[i]=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) 
	{
		if (a[i]>=a[i-1]) f[i]=1;
		else break;
	}
	a[n+1]=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]>=a[i+1]) g[i]=1;
		else break;
	}
	bool ans=0;
	for (int i=1;i<=n;i++)
		if (f[i]&&g[i]) ans=1;
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
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