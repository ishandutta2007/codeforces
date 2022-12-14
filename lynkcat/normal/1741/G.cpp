// Lynkcat.
// Problem: G. Kirill and Company
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/G
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
#define N  10005
using namespace std;
int n,m;
poly G[N];
int dis[N];
int Dis[7][N];
int K,a[7];
int tt;
int dp[(1<<6)],dp1[(1<<6)];
int vis[(1<<6)];
int pos[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cin>>tt;
	for (int i=1;i<=tt;i++) cin>>pos[i];
	cin>>K;
	for (int i=1;i<=K;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++) dis[i]=m+1;
	queue<int>q;
	dis[1]=0;
	q.push(1);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:G[u])
		{
			if (dis[u]+1<dis[v])
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	sort(a+1,a+K+1,[&](int x,int y)
	{
		return dis[pos[x]]<dis[pos[y]];
	});
	for (int i=1;i<=K;i++)
	{
		for (int j=1;j<=n;j++) Dis[i][j]=m+1;
		queue<int>q;
		Dis[i][pos[a[i]]]=0;
		q.push(pos[a[i]]);
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for (auto v:G[u])
			{
				if (Dis[i][u]+1<Dis[i][v])
				{
					Dis[i][v]=Dis[i][u]+1;
					q.push(v);
				}
			}
		}
	}
	dp[0]=1;
	for (int i=1;i<(1<<K);i++) dp[i]=0;
	for (int i=1;i<=tt;i++)
	{
		bool p=0;
		for (int j=1;j<=K;j++)
			if (a[j]==i)
				p=1;
		if (p) continue;
		for (int j=1;j<(1<<K);j++)
		{
			int x=0;
			bool bl=1;
			for (int k=1;k<=K;k++)
				if ((j>>(k-1))&1)
				{
					if (!x) x=k;
					else
					{
						bl&=(dis[pos[a[x]]]+Dis[x][pos[a[k]]]==dis[pos[a[k]]]);
						x=k;
					}
					if (!bl) break;
				}
			bl&=dis[pos[a[x]]]+Dis[x][pos[i]]==dis[pos[i]];
			if (bl)
			{
				// cout<<"???"<<j<<endl;
				for (int p=j;p<(1<<K);p++)
					if ((p&j)==j)
					{
						dp1[p]|=dp[p^j];
					}
			}
		}
		for (int j=1;j<(1<<K);j++) dp[j]|=dp1[j],dp1[j]=0;
	}
	int ans=0;
	for (int i=1;i<(1<<K);i++)
	{
		vis[i]=0;
		if (dp[i])
			ans=max(ans,(int)__builtin_popcountll(i));
			// cout<<"?"<<bitset<5>(i)<<'\n';
	}
	cout<<K-ans<<'\n';
	for (int i=1;i<=n;i++) poly().swap(G[i]);
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