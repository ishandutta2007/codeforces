// Problem: H. Hospital Queue
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/H
// Memory Limit: 512 MB
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
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2005 
using namespace std;
int n,m,d[N],du[N],a[N];
poly G[N],P[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[y].push_back(x);
		du[x]++;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) d[j]=du[j],P[j].clear();
		for (int j=1;j<=n;j++)
			if (d[j]==0&&j!=i)
				P[a[j]].push_back(j);
		poly q;
		for (int ans=n;ans>=1;ans--)
		{
			for (auto u:P[ans])
				q.push_back(u);
			if (!q.size())
			{
				cout<<ans<<' ';
				break;
			} else
			{
				int u=q.back();
				q.pop_back();
				for (auto v:G[u])
				{
					d[v]--;
					if (!d[v]&&v!=i)
					{
						if (a[v]>=ans) q.push_back(v);
						else P[a[v]].push_back(v);
					}
				}
			}
		}
	}
	
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}