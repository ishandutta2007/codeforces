// Lynkcat.
// Problem: B. All Distinct
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/B
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
	map<int,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		Mp[x]++;
	}
	int ans=0;
	int x=0,y=0;
	for (auto u:Mp)
		if (u.se%2==0) x++;
		else y++;
	cout<<x-x%2+y<<endl;
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