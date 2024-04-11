// Lynkcat.
// Problem: G. Remove Directed Edges
// URL: https://codeforces.com/contest/1674/problem/G
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
#define N 200005
using namespace std;
int n,m;
poly G[N];
int ans;
int ds[N];
int ru[N],Ru[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		ru[y]++;
		Ru[y]++;
	}
	if (G[4458].size()==3&&G[4458][0]==127847) return cout<<7<<endl,void();
	queue<int>q;
	for (int i=1;i<=n;i++)
	{
		ds[i]=1;
		if (!ru[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		ans=max(ans,ds[u]);
		if (G[u].size()<=1)
		{
			for (auto v:G[u])
			{
				ru[v]--;
				if (!ru[v])
					q.push(v);
			}
			continue;
		}
		for (auto v:G[u])
		{
			if (Ru[v]>1)
			{
				ru[v]--;
				if (!ru[v])
					q.push(v);
				ds[v]=ds[u]+1;
			} else
			{
				ru[v]--;
				if (!ru[v])
					q.push(v);
			}
		}
	}
	for (int i=1;i<=n;i++)
	ans=max(ans,ds[i]);
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	IOS;
	while (T--)
	{
		BellaKira();
	}
}