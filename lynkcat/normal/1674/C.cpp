// Lynkcat.
// Problem: C. Infinite Replacement
// URL: https://codeforces.com/contest/1674/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
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
//#define N
using namespace std;
void BellaKira()
{
	string st,st1;
	cin>>st>>st1;
	if (st1=="a")
	{
		cout<<1<<endl;
		return;
	}
	int bl=0;
	for (auto u:st1) bl|=(u=='a');
	if (bl) cout<<"-1"<<endl;
	else
	{
		int now=1;
		for (auto u:st)
			if (u=='a') now=now*2;
		cout<<now<<endl;
	}
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}