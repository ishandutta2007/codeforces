// Lynkcat.
// Problem: A. Compare T-Shirt Sizes
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/A
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
#define inf 1e9
#define mod 998244353
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	string x,y;
	cin>>x>>y;
	if (x==y) return cout<<"=\n",void();
	if (x=="M")
	{
		if (y.back()=='S') return cout<<">\n",void();
		cout<<"<\n";
		return;
	}
	if (x.back()==y.back())
	{
		if ((x.size()>y.size())^(x.back()=='S')) cout<<">\n";
		else cout<<"<\n";
		return;
	}
	if (x.back()=='S') cout<<"<\n";
	else cout<<">\n";
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}