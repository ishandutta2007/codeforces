// Lynkcat.
// Problem: H. Maximal AND
// URL: https://codeforces.com/contest/1669/problem/H
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
#define N 200005
using namespace std;
int n,m,a[N],b[N];
void BellaKira()
{
	cin>>n>>m;
	int ans=0;
		for (int j=0;j<=30;j++) b[j]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		for (int j=0;j<=30;j++)
			if ((a[i]>>j)%2==0) b[j]++;
	}
	for (int i=30;i>=0;i--)
		if (m>=b[i])
		{
			m-=b[i];
			ans+=(1ll<<i);
		}
	// cout<<m<<endl;
	cout<<ans<<endl;
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