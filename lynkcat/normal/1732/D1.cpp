// Lynkcat.
// Problem: D2. Balance (Hard version)
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforces.com/contest/1732/problem/D2
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
#define int ll
// #define N 
using namespace std;
int q;
map<int,set<int>>ers;
map<int,poly>lst,vis;
map<int,int>ins,ans;
void BellaKira()
{
	cin>>q;
	ins[0]=1;
	for (int i=1;i<=q;i++)
	{
		string st;
		cin>>st;
		int x;
		cin>>x;
		if (st=="+")
		{
			for (auto u:lst[x]) ers[u].erase(x);
			lst[x].clear();
			ins[x]=1;
		} else
		if (st=="-")
		{
			for (auto u:vis[x]) ers[u].insert(x);
			lst[x]=vis[x];
			ins[x]=0;
		} else
		{
			int &now=ans[x];
			while (ins[now]) vis[now].push_back(x),now+=x;
			int v=now;
			if (ers[x].size()) v=min(v,(*ers[x].begin()));
			cout<<v<<'\n';
		}
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}