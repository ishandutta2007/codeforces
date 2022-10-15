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
#define N 1000005
#define M 1000005
using namespace std;
struct edge
{
	int to,val,nxt;
	edge(int a=0,int b=0,int c=0)
	{
		to=a,val=b,nxt=c;
	}
}E[M<<1];
int cnt=1;
int hd[N],dis[N],q[N],cur[N];
int n,m,S,T,all,nn,qq;
int vis[N];
int ans[N],mth[N];
void add(int x,int y,int w)
{
	E[++cnt].to=y;
	E[cnt].val=w;
	E[cnt].nxt=hd[x];
	hd[x]=cnt;
	
	E[++cnt].to=x;
	E[cnt].val=0;
	E[cnt].nxt=hd[y];
	hd[y]=cnt;
}
int bfs()
{
	int l=1,r=1;
	for (int i=1;i<=n+nn+2;i++) dis[i]=inf,cur[i]=hd[i];
	dis[S]=0;
	q[1]=S;
	while (l<=r)
	{
		int u=q[l++];
		for (int i=hd[u];i;i=E[i].nxt)
		{
			if (E[i].val&&dis[E[i].to]>dis[u]+1)
			{
				dis[E[i].to]=dis[u]+1;
				q[++r]=E[i].to;
			}
		}
	}
	// cout<<"----------"<<endl;
	// cout<<"?"<<dis[T]<<endl;
	return (dis[T]!=inf);
}
int dinic(int k,int liu)
{
	if (k==T) return liu;
	// cout<<"?"<<k<<" "<<liu<<" "<<E[36].val<<endl;
	int res=liu;
	for (int i=cur[k];i&&res;i=E[i].nxt)
	{
		cur[k]=i;
		if (!res) break;
		if (dis[E[i].to]==dis[k]+1&&E[i].val)
		{
			int c=dinic(E[i].to,min(res,E[i].val));
			if (!c) continue;
			res-=c;
			E[i].val-=c;
			E[i^1].val+=c;
			if (E[i].to!=T&&E[i].to!=S&&k!=S&&k!=T)
			{
				if (i%2==0)
				{
					mth[k]=E[i].to;
					ans[k]=i/2;
					mth[E[i].to]=k;
				} else
				{
					if (mth[E[i].to]==k) mth[E[i].to]=0,ans[E[i].to]=0;
					mth[k]=0;
				}
			}
		}
		if (!res) break;
	}
	// cout<<"out "<<endl;
	return liu-res;
}
void dfs(int k)
{
	// cout<<k<<endl;
	vis[k]=1;
		for (int i=hd[k];i;i=E[i].nxt)
			if (!vis[E[i].to]&&E[i].val)
				dfs(E[i].to);
}
void BellaKira()
{
	cin>>n>>nn>>m>>qq;
	S=n+nn+1,T=n+nn+2;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,n+y,1);
	}
	for (int i=1;i<=n;i++) add(S,i,1);
	for (int i=n+1;i<=n+nn;i++)
		add(i,T,1);
	int all=0;
	int xx=0;
	while (bfs()) xx+=dinic(S,inf);
	poly g,g1;
	dfs(S);
	// cout<<
	for (int i=1;i<=n;i++)
		if (mth[i])
		{
			g.push_back(ans[i]);
			all+=ans[i];
			if (vis[i])
				g1.push_back(mth[i]);
				else g1.push_back(i);
		}
	// cout<<xx<<endl;
	for (int i=1;i<=qq;i++)
	{
		int x;
		cin>>x;
		if (x==1)
		{
			cout<<1<<endl;
			if (g1.back()>n) cout<<-(g1.back()-n)<<endl;
			else
				cout<<g1.back()<<endl;
			all-=g.back();
			g.pop_back();g1.pop_back();
			cout<<all<<endl;
		} else
		{
			cout<<g.size()<<endl;
			for (auto u:g) cout<<u<<" ";
			cout<<endl;
		}
	}	
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}