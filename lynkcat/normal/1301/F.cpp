// Lynkcat.
// Problem: B. Super Jaber
// Contest: Codeforces - 10.10
// URL: https://codeforces.com/gym/403227/problem/B
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
// #define int ll
// #define N 
using namespace std;
int n,m,K;
int qq;
int a[1005][1005];
int sx[100005],sy[100005],tx[100005],ty[100005];
int ans[100005];
int dis[1000045];
vector<pa>G[1000045];
poly Col[45];
int vis[1000045];
int Id[45];
int id[1005][1005];
void ad(int x,int y,int w)
{
	G[x].push_back(mp(y,w));
}
void BellaKira()
{
	cin>>n>>m>>K;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	cin>>qq;
	for (int i=1;i<=qq;i++)
		cin>>sx[i]>>sy[i]>>tx[i]>>ty[i],ans[i]=abs(sx[i]-tx[i])+abs(sy[i]-ty[i]);
	int tt=0;
	for(int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			id[i][j]=++tt;
	for (int i=1;i<=K;i++) Id[i]=++tt;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			Col[a[i][j]].push_back(id[i][j]);
	// for (int i=1;i<=n;i++)
		// for (int j=1;j<=m;j++)
			// ad(Id[a[i][j]],id[i][j],0),ad(id[i][j],Id[a[i][j]],1);
	// for (int i=1;i<n;i++)
		// for (int j=1;j<=m;j++)
			// ad(id[i][j],id[i+1][j],1),ad(id[i+1][j],id[i][j],1);
	// for (int i=1;i<=n;i++)
		// for (int j=1;j<=m;j++)
			// ad(id[i][j],id[i][j+1],1),ad(id[i][j+1],id[i][j],1);
	for (int i=1;i<=K;i++)
	{
		int st=Id[i];
		deque<int>q;
		for (int j=1;j<=tt;j++)
			dis[j]=inf,vis[j]=0;
		dis[st]=0;
		q.push_back(st);
		while (!q.empty())
		{
			int u=q.front();q.pop_front();
			if (vis[u]) continue;
			if (u>n*m)
			{
				for (auto v:Col[u-n*m])
				{
					if (dis[u]<dis[v])
					{
						dis[v]=dis[u];
						q.push_front(v);
					}
				}
			} else
			{
				{
					int X=(u-1)/m+1;
					int Y=u-(X-1)*m;
					int v=Id[a[X][Y]];
					if (dis[u]+1<dis[v])
					{
						dis[v]=dis[u]+1;
						q.push_back(v);
					}
				}
				{
					int X=(u-1)/m+1;
					int Y=u-(X-1)*m;
					if (X+1<=n)
					{
						int v=id[X+1][Y];
						if (dis[u]+1<dis[v])
						{
							dis[v]=dis[u]+1;
							q.push_back(v);
						}
					}
					if (X-1>=1)
					{
						int v=id[X-1][Y];
						if (dis[u]+1<dis[v])
						{
							dis[v]=dis[u]+1;
							q.push_back(v);
						}
					}
					if (Y+1<=m)
					{
						int v=id[X][Y+1];
						if (dis[u]+1<dis[v])
						{
							dis[v]=dis[u]+1;
							q.push_back(v);
						}
					}
					if (Y-1>=1)
					{
						int v=id[X][Y-1];
						if (dis[u]+1<dis[v])
						{
							dis[v]=dis[u]+1;
							q.push_back(v);
						}
					}
				}
			}
		}
		for (int j=1;j<=qq;j++)
		{
			ans[j]=min(dis[id[sx[j]][sy[j]]]+1+dis[id[tx[j]][ty[j]]],ans[j]);
			// cout<<"?"<<j<<" "<<i<<" "<<dis[id[sx[j]][sy[j]]]<<" "<<
			// dis[id[tx[j]][ty[j]]]<<" "<<dis[id[3][3]]<<endl;
		}
	}
	for (int i=1;i<=qq;i++) cout<<ans[i]<<'\n';
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