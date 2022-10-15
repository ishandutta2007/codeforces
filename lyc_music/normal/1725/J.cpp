// Lynkcat.
// Problem: J. Journey
// Contest: Codeforces - COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1725/problem/J
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
#define N 200005
using namespace std;
int dp[N],dis[N];
int sum[N];
vector<pa>G[N];
int Ex[N],Ey[N],Ew[N];
int fk[N];
int n;
int ans;

void dfs(int k,int fa)
{
	int x=0,y=0;
	int z=0;
	int sm=0;
	vector<pa>nxt;
	int mx=0;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		dfs(u,k);
		nxt.push_back({u,w});
		mx=max(mx,w);
		dp[k]=max(dp[k],dp[u]+w);
		dp[k]=max(dp[k],w*2+sum[u]+x);
		dp[k]=max(dp[k],sm+dis[u]+w);
		if (dis[u]+w>x)
		{
			z=y;
			y=x;
			x=dis[u]+w;
		} else 
		if (dis[u]+w>y)
		{
			z=y;
			y=dis[u]+w;
		} else z=max(z,dis[u]+w);
		sm=max(sm,sum[u]+w*2);
	}
	nxt.swap(G[k]);
	dp[k]=max(dp[k],x+y+z);
	dis[k]=x;
	sum[k]=x+y;
	fk[k]=sm;
}
void dfs1(int k,int fa,int fdp,int fdis,int fsm,int lstw)
{
	if (fa)
	{
		dp[k]=max(dp[k],fdp+lstw);
		dp[k]=max(dp[k],fsm+dis[k]+lstw*2);
		dp[k]=max(dp[k],fk[k]+fdis+lstw);
		dp[k]=max(dp[k],sum[k]+fdis+lstw);
	}
	// cout<<"?"<<k<<" "<<dp[k]<<endl;
	ans=max(ans,dp[k]);
	multiset<int>a;
	multiset<pa>b,c;
	if (fa)
	{
		a.insert(fdp+lstw);
		b.insert(mp(fdis+lstw,fa));
		c.insert(mp(fsm+lstw*2,fa));
	}
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		a.insert(dp[u]+w);
		b.insert(mp(dis[u]+w,u));
		c.insert(mp(sum[u]+w*2,u));
	}
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		int lst=dp[u];
		a.erase(a.find(dp[u]+w));
		b.erase(mp(dis[u]+w,u));
		c.erase(mp(sum[u]+w*2,u));
		int ndp=0;
		if (a.size()) ndp=(*a.rbegin());
		int ndis=0;
		if (b.size()) ndis=(*b.rbegin()).fi;
		int nsm=0+ndis;
		if (b.size()>1) nsm+=(*(--(--b.end()))).fi;
		if (b.size()&&c.size())
		{
			if ((*b.rbegin()).se==(*c.rbegin()).se)
			{
				if (b.size()>1)
				{
					ndp=max(ndp,(*(--(--b.end()))).fi+(*c.rbegin()).fi);
				}
				if (c.size()>1)
				{
					ndp=max(ndp,(*(--(--c.end()))).fi+(*b.rbegin()).fi);
				}
			}
			else
			{
				ndp=max(ndp,(*(--b.end())).fi+(*c.rbegin()).fi);
			}
		}
		if (b.size()>2)
		{
			ndp=max(ndp,(*(--(--b.end()))).fi+(*(--b.end())).fi+(*(--(--(--b.end())))).fi);
		}
		dfs1(u,k,ndp,ndis,nsm,w);
		a.insert(lst+w);
		b.insert(mp(dis[u]+w,u));
		c.insert(mp(sum[u]+w*2,u));
	}
		
}
namespace ss
{
	int dp[N];
	int dis[N];
	void dfs(int k,int fa)
	{
		vector<pa>nxt;
		int x=0,y=0;
		for (auto U:G[k])
		{
			int u=U.fi,w=U.se;
			if (u==fa) continue;
			dfs(u,k);
			nxt.push_back({u,w});
			if (dis[u]+w>x)
			{
				y=x;
				x=dis[u]+w;
			} else y=max(y,dis[u]+w);
			dp[k]=max(dp[k],dp[u]);
		}
		nxt.swap(G[k]);
		dp[k]=max(dp[k],x+y);
		// cout<<k<<","<<dp[k]<<" "<<x<<" "<<y<<endl;
		dis[k]=x;
	}
	void dfs1(int k,int fa,int lstdp,int lstdis,int lstw)
	{
		if (k>n)
		{
			if (G[k].size()==2)
			{
				ans=max(ans,dp[G[k][0].fi]+dp[G[k][1].fi]+2*(G[k][0].se+G[k][1].se));
			}
			else
			{
				ans=max(ans,lstdp+dp[G[k][0].fi]+2*(G[k][0].se+lstw));
			}
			// cout<<k<<" "<<ans<<" "<<lstdp<<" "<<lstdp+dp[G[k][0].fi]+2*(G[k][0].se+lstw)<<endl;
		}
		multiset<int>S,S1;
		for (auto U:G[k])
		{
			int u=U.fi,w=U.se;
			if (u==fa) continue;
			S.insert(dis[u]+w);
			S1.insert(dp[u]);
		}
		if (fa)
		{
			S.insert(lstdis);
			S1.insert(lstdp);
		}
		for (auto U:G[k])
		{
			int u=U.fi,w=U.se;
			if (u==fa) continue;
			S.erase(S.find(dis[u]+w));
			S1.erase(S1.find(dp[u]));
			int ndp=0,ndis=0;
			if (S.size()) ndis=max(ndis,(*S.rbegin())),ndp=max(ndp,(*S1.rbegin()));
			int o=ndis;
			if (S.size()>1) o+=(*(--(--S.end())));
			ndp=max(ndp,o);
			dfs1(u,k,ndp,ndis+w,w);
			S.insert(dis[u]+w);
			S1.insert(dp[u]);
		}
	}
}
void BellaKira()
{
	cin>>n;
	int sum=0;
	for (int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		Ex[i]=x,Ey[i]=y,Ew[i]=w;
		G[x].push_back(mp(y,w));
		G[y].push_back(mp(x,w));
		sum+=w*2;
	}
	dfs(1,0);
	dfs1(1,0,0,0,0,0);
	// cout<<sum-ans<<'\n';
	for (int i=1;i<=n;i++) vector<pa>().swap(G[i]);
	for (int i=1;i<n;i++)
	{
		int x=Ex[i],y=Ey[i],w=Ew[i];
		G[x].push_back(mp(n+i,0));
		G[n+i].push_back(mp(x,0));
		swap(x,y);
		G[x].push_back(mp(n+i,w));
		G[n+i].push_back(mp(x,w));
	}
	ss::dfs(1,0);
	ss::dfs1(1,0,0,0,0);
	cout<<sum-ans<<'\n';
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