// Lynkcat.
// Problem: B. Polycarp Writes a String from Memory
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/B
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
void BellaKira()
{
	map<int,int>Mp;
	string st;
	cin>>st;
	int ans=0;
	for (auto u:st)
	{
		Mp[u]++;
		if (Mp.size()==4)
		{
			ans++;
			Mp.clear();
			Mp[u]++;
		}
	}
	if (Mp.size()) ans++;
	cout<<ans<<endl;
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