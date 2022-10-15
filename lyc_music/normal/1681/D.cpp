// Lynkcat.
// Problem: D. Required Length
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/D
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
// #define N 
using namespace std;
int n,x;
unordered_map<int,int>vis;
int dfs(int x)
{
	string st=to_string(x);
	if (vis.count(x)) return vis[x];
	if (st.size()==n) 
	{
		return 0;
	}
	if (st.size()>n) return -1;
	int &res=vis[x];
	res=10000;
	for (auto u:st)
	{
		if (u<='1') continue;
		int v=dfs(x*(u-'0'));
		if (v!=-1) res=min(res,v+1);
	}
	if (res==10000) res=-1;
	return res;
}	
void BellaKira()
{
	cin>>n>>x;
	cout<<dfs(x)<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}