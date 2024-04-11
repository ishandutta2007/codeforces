#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1000000000
#define mod 1000000007
#define int ll
#define N 1000005
using namespace std;
int n,m;
vector<pa>G[N];
int vis[N],ans[N];
pa nw[N];
poly Q[N];
int dis[N];
int id[N];
void BellaKira()
{
	cin>>n>>m;
	int cnt=n;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int X=x,Y=y;
		string st=to_string(i);
		for (int j=0;j+1<st.size();j++)
			G[x].push_back(mp(++cnt,st[j]-'0')),x=cnt;
		G[x].push_back(mp(y,st.back()-'0'));
		x=Y,y=X;
		for (int j=0;j+1<st.size();j++)
			G[x].push_back(mp(++cnt,st[j]-'0')),x=cnt;
		G[x].push_back(mp(y,st.back()-'0'));
	}
	vis[1]=1;
	for (int i=1;i<=cnt;i++) nw[i]=mp(inf,inf);
	Q[dis[1]].push_back(1);
		
	for (int i=0;i<=cnt;i++)
	{
		sort(Q[i].begin(),Q[i].end(),[&](int x,int y)
		{
			return nw[x]<nw[y];
		});
		int tot=0;
		for (int j=0;j<Q[i].size();j++)
			if (j==0||ans[Q[i][j]]!=ans[Q[i][j-1]])
			{
				id[Q[i][j]]=++tot;
			} else id[Q[i][j]]=tot;
		for (auto u:Q[i])
		{
			for (auto [v,w]:G[u])
				if (!vis[v]||dis[v]==dis[u]+1)
				{
					if (!vis[v]) Q[dis[u]+1].push_back(v);
					vis[v]=1;
					dis[v]=dis[u]+1;
					pa now=mp(id[u],w);
					if (now<nw[v])
					{
						nw[v]=now;
						ans[v]=(ans[u]*10%mod+w)%mod;
					}
				}
		}
	}
	for (int i=2;i<=n;i++) cout<<ans[i]<<"\n";
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