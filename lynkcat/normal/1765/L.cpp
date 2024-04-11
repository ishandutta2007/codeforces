// Problem: L. Project Manager
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/L
// Memory Limit: 512 MB
// Time Limit: 4000 ms

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
#define N 200005
using namespace std;
int n,m,q,f[N][7];
map<int,set<int>>P[7];
queue<int>G[N];
int ans[N];
unordered_map<int,int>Mp;
void BellaKira()
{
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while (x--)
		{
			string st;
			cin>>st;
			if (st=="Monday") f[i][1]=1;
			else
			if (st=="Tuesday") f[i][2]=1;
			else if (st=="Wednesday") f[i][3]=1;
			else if (st=="Thursday") f[i][4]=1;
			else if (st=="Friday") f[i][5]=1;
			else if (st=="Saturday") f[i][6]=1;
			else if (st=="Sunday") f[i][0]=1;
		}
	}
	for (int i=1;i<=m;i++) 
	{
		int x;
		cin>>x;
		Mp[x]=1;
	}
	for (int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		for (int j=1;j<=x;j++)
		{
			int y;
			cin>>y;
			G[i].push(y);
		}
		if (G[i].size())
		{
			int x=G[i].front();
			for (int j=0;j<7;j++)
				if (f[x][j])
					P[j][x].insert(i);
		}
	}
	// return;
	int tim=1;
	int tt=0;
	while (1)
	{
		if (Mp.count(tim))
		{
			tim++;
			tt=0;
			continue;
		}
		if (!P[tim%7].size())
		{
			tim++;
			tt++;
			if (tt==7) break;
			continue;
		}
		tt=0;
		poly g;
		poly nxt;
		for (auto &typ:P[tim%7])
		{
			int u=typ.fi;
			if (typ.se.size()==0) 
			{
				g.push_back(u);
				continue;
			}
			int o=(*typ.se.begin());
			for (int i=0;i<7;i++)
				if (f[u][i])
					P[i][u].erase(P[i][u].find(o));
			nxt.push_back(o);
		}
		for (auto u:g)
			P[tim%7].erase(u);
		for (auto i:nxt)
		{
			G[i].pop();
			if (G[i].size())
			{
				int x=G[i].front();
				for (int j=0;j<7;j++)
					if (f[x][j])
						P[j][x].insert(i);
			} else ans[i]=tim;
		}
		tim++;
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<' ';
	cout<<'\n';
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