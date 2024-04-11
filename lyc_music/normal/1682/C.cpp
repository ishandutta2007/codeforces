// Lynkcat.
// Problem: C. LIS or Reverse LIS?
// URL: https://codeforces.com/contest/1682/problem/C
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
int n,a[N];
void BellaKira()
{
	map<int,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],Mp[a[i]]++;
	if (Mp.size()==2&&n>2)
	{
		cout<<2<<endl;
		return;
	}
	sort(a+1,a+n+1);
	poly g,g1;
	int bl=0;
	for (int i=1;i<=n;i++)
	{
		int x=0,y=0;
		if (!g.size()||g.back()<a[i]) x=1;
		if (!g1.size()||g1.back()<a[i]) y=1;
		if (x&&y&&!bl&&Mp[a[i]]==1)
		{
			// cout<<x<<" "<<y<<" "<<" "<<a[i]<<endl;
			bl=1;
			if (x) g.push_back(a[i]);
			if (y) g1.push_back(a[i]);
			continue;
		}
		if (x&&y)
		{
			if (g.size()<=g1.size())
			{
				g.push_back(a[i]);
			}
			else g1.push_back(a[i]);
		} else
		{
				if (x&&(!y)) g.push_back(a[i]);
				if (y&&(!x)) g1.push_back(a[i]);
				
		}
	}
	cout<<min(g.size(),g1.size())<<endl;
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