// Lynkcat.
// Problem: A. Traveling Salesman Problem
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/A
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
#define int ll
// #define N 
using namespace std;
int n;
void BellaKira()
{
	cin>>n;
	int l=0,r=0,a=0,b=0;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		if (x==0) l=min(l,y),r=max(r,y);
		else a=min(x,a),b=max(x,b);
	}
	cout<<abs(l-r)*2+abs(a-b)*2<<endl;
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