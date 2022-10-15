// Lynkcat.
// Problem: B. Array Decrements
// URL: https://codeforces.com/contest/1690/problem/B
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
#define N 200005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	int ans=1;
	for (int i=1;i<=n;i++)
		if (b[i]>a[i]) ans=0;
	if (!ans) return cout<<"NO"<<endl,void();
	int mx=-inf;
	int now=-1;
	for (int i=1;i<=n;i++)
		if (b[i]==0) mx=max(mx,a[i]);
		else
		{
			if (now==-1) now=a[i]-b[i];
			else
			{
				if (a[i]-b[i]!=now) return cout<<"NO"<<endl,void();
			}
		}
	// cout<<"?"<<mx<<" "<<now<<endl;
	if (now==-1) return cout<<"YES"<<endl,void();
	if (mx>now) return cout<<"NO"<<endl,void();
	cout<<"YES"<<endl;
				
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