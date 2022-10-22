#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct st
{
	const static int N=2e5+5,LogN=19;
	int n,a[LogN][N],log[N];
	void build(int *b,int n)
	{
		F(i,2,n+1)log[i]=log[i-1]+((i&-i)==i);
		F(i,0,n)a[0][i]=b[i];
		F(i,0,log[n])
		{
			int k=1<<i;
			F(j,0,n-(k<<1)+1)a[i+1][j]=min(a[i][j],a[i][j+k]);
		}
	}
	int query(int l,int r)
	{
		int k=log[r-l];
		return min(a[k][l],a[k][r-(1<<k)]);
	}
}st;
int n,m,dis[N],centroid,rt,fa[N],dfn[N],ind,seq[2*N],dep[N];bool vis[N];
struct line
{
	int next,to;
}e[2*N];
int hd[N],cnt;
void init(int n){F(i,cnt=0,n)hd[i]=-1;}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int getcentroid(int u,int fa,int n,int dep)
{
	int maxsize=0,size=0;
	if(vis[u])return 0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to,tmp;if(v==fa)continue;
		size+=tmp=getcentroid(v,u,n,dep+1);
		if(tmp>maxsize)maxsize=tmp;
	}
	++size;
	if(maxsize*2<=n&&size*2>=n)centroid=u;
	return size;
}
int getsize(int u,int fa)
{
	int size=0;if(vis[u])return 0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		size+=getsize(v,u);
	}
	return ++size;
}
void getcentroid(int u)
{
	int n=getsize(u,u);
	getcentroid(u,u,n,1);
}
int divide(int u)
{
	getcentroid(u);
	vis[u=centroid]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v])fa[divide(v)]=u;
	}
	return u;
}
void dfs(int u,int fa)
{
	seq[ind]=dep[u];
	dfn[u]=ind++;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		seq[ind++]=dep[u];
	}
}
int getdis(int u,int v)
{
	int x=dfn[u],y=dfn[v];
	if(x>y)swap(x,y);
	return dep[u]+dep[v]-(st.query(x,y+1)<<1);
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)dis[i]=INF;
	rt=divide(0);fa[rt]=rt;
	dfs(0,0);
	st.build(seq,2*n-1);
	for(int u=0,d=0;u!=rt;)
	{
		dis[u]=min(dis[u],d);
		d=getdis(u=fa[u],0);
	}
	dis[rt]=getdis(0,rt);
	while(m--)
	{
		int op;read(op);
		if(op==1)
		{
			int u,d=0;read(u);--u;
			for(int v=u;v!=rt;v=fa[v],d=getdis(u,v))dis[v]=min(dis[v],d);
			dis[rt]=min(dis[rt],getdis(u,rt));
		}
		if(op==2)
		{
			int u,d=0,ans=INF;read(u);--u;
			for(int v=u;v!=rt;v=fa[v],d=getdis(u,v))ans=min(ans,d+dis[v]);
			ans=min(ans,getdis(u,rt)+dis[rt]);
			printf("%d\n",ans);
		}
	}
	return 0;
}