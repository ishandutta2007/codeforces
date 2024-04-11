// Lynkcat.
// Problem: B. Make It Increasing
// URL: https://codeforces.com/contest/1675/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
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
#define N 35
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	a[0]=-1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int tot=0;
	for (int i=n-1;i>=1;i--)
	{
		while (a[i]&&a[i]>=a[i+1])
		{
			a[i]=a[i]/2;
			tot++;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		// cout<<a[i]<<" ";
		if (a[i]>a[i-1]) ans++;
	}
	// cout<<endl;
	if (ans!=n) cout<<"-1"<<endl;
	else cout<<tot<<endl;
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}