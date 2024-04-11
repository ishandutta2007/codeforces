// Lynkcat.
// Problem: C. Fishingprince Plays With Array
// Contest: Codeforces - Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
int n,m,a[N],b[N],nn;
vector<pa> work(poly g)
{
	vector<pa>res;
	for (auto u:g)
	{
		int x=1,y=u;
		while (y%m==0)
		{
			x*=m;
			y/=m;
		}
		if (!res.size()||res.back().se!=y) 
			res.push_back(mp(x,y));
		else res.back().fi+=x;
	}
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	poly g,g1;
	for  (int i=1;i<=n;i++)
	 cin>>a[i],g.push_back(a[i]);
	cin>>nn;
	for (int i=1;i<=nn;i++)
		cin>>b[i],g1.push_back(b[i]);
	if (work(g)==work(g1)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
}
signed main()
{
	IOS;
	int T=1;cin>>T;
	while (T--)
	{
		BellaKira();
	}
}