// Lynkcat.
// Problem: A. Everyone Loves to Sleep
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/0
// Memory Limit: 256 MB
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
// #define N 
using namespace std;
int n,x,y;
void BellaKira()
{
	cin>>n>>x>>y;
	int ans=inf;
	for (int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if (a<x||a==x&&b<y)
		{
			int ax=(a+24-x)*60+(b-y);
			if (ax<ans) ans=ax;
		} else
		{
			int ax=(a-x)*60+b-y;
			// cout<<ax<<endl;
			if (ax<ans) ans=ax;
		}
	}
	cout<<ans/60<<" "<<ans%60<<endl;
		
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