#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=20,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[2*N];
int n,logn,k,tp[N],now,hd[N],cnt,fa[N][LogN],dep[N],up[N],down[N],e2[10*N],ans;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	fa[u][0]=f;
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v]){for(int i=dep[u]-dep[v],j=0;i;i>>=1,++j)if(i&1)u=fa[u][j];}
	else for(int i=dep[v]-dep[u],j=0;i;i>>=1,++j)if(i&1)v=fa[v][j];
	if(u==v)return u;
	for(int i=logn;~i;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u][0])continue;
		dfs(v);
		up[u]+=up[v];down[u]+=down[v];
	}
}
int main()
{
	read(n);
	while((1<<logn)<n)++logn;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);read(tp[i]);--u,--v;
		adline(u,v);adline(v,u);
	}
	dfs(0,0);
	read(k);
	e2[0]=1;
	F(i,0,k)e2[i+1]=(e2[i]<<1)%MOD;
	while(k--)
	{
		int fsb,yt;read(fsb);--fsb;
		yt=lca(fsb,now);
		++up[now];--up[yt];
		++down[now=fsb];--down[yt];
	}
	dfs(0);
	F(i,0,n-1)if(tp[i])
	{
		int u=e[i<<1].to,v=e[i<<1|1].to;
		if(dep[u]>dep[v])u^=v^=u^=v,tp[i]^=1;
		(ans+=e2[(tp[i]?down:up)[v]]-1)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}