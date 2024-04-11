// Lynkcat.
// Problem: C. Beautiful League
// Contest: Codeforces - 10.11
// URL: https://codeforces.com/gym/403247/problem/C
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
namespace G
{
	struct edge
	{
		int fm,to,val,cost,nxt;
		edge(int o=0,int a=0,int b=0,int c=0,int d=0)
		{
			fm=o,to=a,val=b,cost=c,nxt=d;
		}
	}E[N<<1];
	int cnt=1;
	int hd[N],dis[N],cur[N],lst[N];
	int n,m,S,T,ans;
	int MC,MF;
	int flw[N],ins[N];
	void add(int x,int y,int w,int cost)
	{
		E[++cnt].to=y;
		E[cnt].fm=x;
		E[cnt].val=w;
		E[cnt].nxt=hd[x];
		E[cnt].cost=cost;
		hd[x]=cnt;
		
		E[++cnt].to=x;
		E[cnt].fm=y;
		E[cnt].val=0;
		E[cnt].nxt=hd[y];
		E[cnt].cost=-cost;
		hd[y]=cnt;
	}
	bool spfa()
	{
		queue<int>q;
		for (int i=1;i<=n;i++) dis[i]=inf,ins[i]=0,flw[i]=0;
		dis[S]=0;
		q.push(S);
		ins[S]=1;
		flw[S]=inf;
		while (!q.empty())
		{
			int u=q.front();q.pop();
			ins[u]=0;
			for (int i=hd[u];i;i=E[i].nxt)
				if (E[i].val&&dis[E[i].to]>dis[u]+E[i].cost)
				{
					// cout<<i<<","<<E[i].val<<" "<<u<<" "<<E[i].to<<endl;
					dis[E[i].to]=dis[u]+E[i].cost;
					flw[E[i].to]=min(flw[u],E[i].val);
					lst[E[i].to]=i;
					if (!ins[E[i].to]) ins[E[i].to]=1,q.push(E[i].to);
				}
		}
		if (dis[T]==inf) return 0;
		MF+=flw[T];
		MC+=dis[T]*flw[T];
		// cout<<dis[T]<<","<<flw[T]<<" "<<MC<<endl;
		int nw=T;
		while (nw!=S)
		{
			E[lst[nw]].val-=flw[T];
			E[lst[nw]^1].val+=flw[T];
			// cout<<"!!"<<nw<<" "<<lst[nw]<<endl;
			nw=E[lst[nw]].fm;
		}
		return 1;
	}
}
int n,m;
int chu[55];
int f[55][55],Id[55][55];
int Ans;
void BellaKira()
{
	cin>>n>>m;
	memset(f,-1,sizeof(f));
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		chu[x]++;
		if (x>y) f[y][x]=1;
		else f[x][y]=0;
	}
	int tot=n;
	G::S=++tot;
	G::T=++tot;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (f[i][j]==-1)
			{
				++tot;
				G::add(G::S,tot,1,0);
				G::add(tot,i,1,0);
				Id[i][j]=G::cnt-1;
				G::add(tot,j,1,0);
			}
	for (int i=1;i<=n;i++)
	{
		Ans+=chu[i]*(chu[i]-1)/2;
		for (int j=chu[i]+1;j<=n-1;j++)
			G::add(i,G::T,1,j-1);
	}
	G::n=tot;
	while (G::spfa()) ;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (f[i][j]==-1)
			{
				if (!G::E[Id[i][j]].val) f[i][j]=0;
				else f[i][j]=1;
			}
	// cout<<n*(n-1)*(n-2)/6-(Ans+G::MC)<<" "<<Ans<<" "<<G::MC<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (j<i) cout<<f[j][i];
			else if (j==i) cout<<0;
			else cout<<(f[i][j]^1);
		}
		cout<<'\n';
	}
		
		
				
				
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