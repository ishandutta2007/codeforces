// Lynkcat.
// Problem: D. Fixed Point Guessing
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/D
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
// #define int ll
// #define N 
using namespace std;
int n;
poly query(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	poly g;
	for (int i=1;i<=r-l+1;i++)
	{
		int x;
		cin>>x;
		g.push_back(x);
	}
	return g;
}
void BellaKira()
{
	cin>>n;
	int l=1,r=n;
	while (l<r)
	{
		int mid=l+(r-l)/2;
		poly g=query(l,mid);
		int tt=0;
		for (int i=0;i<g.size();i++)
			if ((g[i]>=l&&g[i]<=mid)) tt++;
		if (tt%2==0)
		{
			l=mid+1;
		}  else r=mid;
	}
	cout<<"! "<<l<<endl;
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