// Lynkcat.
// Problem: D. Knowledge Cards
// Contest: Codeforces - Codeforces Round #831 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1740/problem/D
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
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n,m,K;
	cin>>n>>m>>K;
	int ans=0;
	int l=K;
	priority_queue<int>g;
	for (int i=1;i<=K;i++)
	{
		int x;
		cin>>x;
		if (ans) continue;
		g.push(x);
		if (g.size()==n*m-2)
		{
			ans=1;
			continue;
		}
		while (!g.empty()&&g.top()==l) g.pop(),l--;
	}
	if (ans) cout<<"TIDAK\n";
	else
		cout<<"YA\n";
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