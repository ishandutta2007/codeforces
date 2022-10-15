// Lynkcat.
// Problem: E. Price Maximization
// URL: https://codeforces.com/contest/1690/problem/E
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
int n,m,a[N];
void BellaKira()
{
	cin>>n>>m;
	poly b;
	int sm=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sm+=a[i]/m;
		b.push_back(a[i]%m);
	}
	sort(b.begin(),b.end());
	int l=(int)b.size()-1;
	for (int i=0;i<l;i++)
	{
		if (i<l&&b[i]+b[l]>=m)
		{
			l--;
			sm++;
			continue;
		}
	}
	cout<<sm<<endl;
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