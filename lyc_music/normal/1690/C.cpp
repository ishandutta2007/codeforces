// Lynkcat.
// Problem: C. Restoring the Duration of Tasks
// URL: https://codeforces.com/contest/1690/problem/C
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
#define N 200005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	int now=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=now)
		{
			cout<<b[i]-a[i]<<" ";
			now=b[i];
		} else
		{
			cout<<b[i]-now<<" ";
			now=b[i];
		}
	}
	cout<<endl;
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