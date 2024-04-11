// Lynkcat.
// Problem: F. Equate Multisets
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/f
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int l=n;
	multiset<int>g;
	multiset<int>S;
	for (int i=1;i<=n;i++) g.insert(b[i]);
	for (int i=1;i<=n;i++) S.insert(a[i]);
	while (S.size())
	{
		int ai=(*S.rbegin());
		S.erase(--S.end());
		if (g.empty())
		{
			return cout<<"NO"<<endl,void();
		}
		while (__lg(*g.rbegin())>__lg(ai))
		{
			poly nw;
			for (auto u:g)nw.push_back(u);
			g.clear();
			for (auto u:nw)
			{
				while (__lg(u)>__lg(ai)) u/=2;
				g.insert(u);
			}
		}
		if (g.find(ai)!=g.end())
		{
			g.erase(g.find(ai));
			continue;
		}
		if (ai%2==1) 
		{
			return cout<<"NO"<<endl,void();
		}
		S.insert(ai/2);
	}
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