// Problem: A. Access Levels
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
#define N 1005
#define M 3000005
using namespace std;
int n,m,x,y,vis[N],ans,f[N][N];
int a[N][N];
int col[N],num[N],Num[N][N];
poly all;
struct Graph_Dinic
{
	int q[N<<2],l,r,dis[N],cur[N],head[N],S,T,mch[N],cnt=1,ans,now;
	struct
	{
		int to,nx,val;
	}e[M];
	inline void ad(int x,int y,int val)
	{
		// cout<<x<<" -> "<<y<<" "<<val<<endl;
		e[++cnt].to=y,e[cnt].nx=head[x],e[cnt].val=val;head[x]=cnt;
		e[++cnt].to=x,e[cnt].nx=head[y],e[cnt].val=0;head[y]=cnt;
	}
	inline bool bfs()
	{
		l=0,r=1;
		q[++l]=S;
		memset(dis,-1,sizeof(dis));
		dis[S]=0;
		memcpy(cur,head,sizeof(head));
		while (l<=r)
		{
			now=q[l];
			l++;
			for (int i=head[now];i;i=e[i].nx)
			{
				if (dis[e[i].to]==-1&&e[i].val!=0)
				{
					dis[e[i].to]=dis[now]+1;
					q[++r]=e[i].to;
				}
			}
		}
		return (dis[T]!=-1);
	}
	inline int dfs(int now,int liu)
	{
		if (now==T)
		{
			return liu;
		}
		int res=liu;
		for (int i=cur[now];i&&res;i=e[i].nx)
		{
			cur[now]=i;
			if (dis[e[i].to]==dis[now]+1&&e[i].val!=0)
			{
				int c=dfs(e[i].to,min(res,e[i].val));
				res-=c;
				e[i].val-=c;
				e[i^1].val+=c;
				if (c!=0&&e[i].to!=T&&now!=S)
				{
					f[(e[i].to-1)%m+1][(now-1)%m+1]^=1;
					f[(now-1)%m+1][(e[i].to-1)%m+1]^=1;
				}
			}
		}
		return liu-res;
	}
	inline void dinic()
	{
		while (bfs())
			ans+=dfs(S,inf);
	}
}G;
inline void dfs(int k,int fa)
{
	vis[k]=1;
	all.push_back(k-1);
	for (int i=1;i<=m;i++)
		if (f[k][i]&&i!=fa&&!vis[i])
			dfs(i,k);
}
void BellaKira()
{
	cin>>n>>m;
	G.T=2*m+1;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			char ch;
			cin>>ch;
			a[j][i]=ch-'0';
		}
	
	for (int i=0;i<m;i++)
		G.ad(G.S,i+1,1),G.ad(i+m+1,G.T,1);
	for (int i=0;i<m;i++)
		for (int j=i+1;j<m;j++)
		{
			int x=0,y=0;
			for (int k=0;k<n;k++) 
				if ((a[i][k]^a[j][k]))
				{
					if (a[i][k]) y=1;
					else x=1;
				}
			if (x&&y) continue;
			if (x==0)
			{
				// cout<<i<<"->"<<j<<" "<<x<<" "<<y<<" "<<a[1][0]<<" "<<a[1][1]<<endl;
				G.ad(i+1,j+m+1,1);
			}
			else 
			{
				// cout<<j<<"->"<<i<<" "<<x<<" "<<y<<" "<<a[1][0]<<" "<<a[1][1]<<endl;
				G.ad(j+1,i+m+1,1);
			}
		}
	G.dinic();
	// cout<<"??"<<G.ans<<endl;
	int ans=0;
	for (int i=1;i<=m;i++)
		if (!vis[i])
		{
			all.clear();
			dfs(i,0);
			++ans;
			for (auto u:all) col[u]=ans;
			for (auto u:all) 
			{
				for (int j=0;j<n;j++)
					num[u]+=a[u][j];
				num[u]=n-num[u]+1;
				for (int j=0;j<n;j++)
					if (a[u][j]) 
					{
						// if (!Num[j][ans]) Num[j][ans]=num[u];
						Num[j][ans]=max(Num[j][ans],num[u]);
						// cout<<"?"<<u<<" "<<j<<" "<<Num[j][ans]<<'\n';
					}
			}
		}
	cout<<ans<<'\n';
	for (int i=0;i<m;i++) cout<<col[i]<<" ";
	cout<<'\n';
	for (int i=0;i<m;i++) cout<<num[i]+1<<" ";
	cout<<'\n';
	for (int i=0;i<n;i++)
	{
		for (int j=1;j<=ans;j++)
			cout<<Num[i][j]+1<<" ";
		cout<<'\n';
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