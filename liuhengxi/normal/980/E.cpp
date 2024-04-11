#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,LogN=22;
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
int n,k,hd[N],cnt,top,fa[N][LogN],logn,dep[N];
bool use[N];
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
	{int v=e[i].to;if(v==f)continue;dep[v]=dep[u]+1;dfs(v,u);}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v]){for(int i=dep[u]-dep[v],j=0;i;i>>=1,++j)if(i&1)u=fa[u][j];}
	else for(int i=dep[v]-dep[u],j=0;i;i>>=1,++j)if(i&1)v=fa[v][j];
	if(u==v)return u;
	for(int i=logn;~i;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int main()
{
	read(n);read(k);k=n-k-1;
	while((1<<logn)<n)++logn;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);--u,--v;
		adline(u,v);adline(v,u);
	}
	use[n-1]=true;
	top=n-1;
	dfs(0,0);
	for(int u=n-2;~u;--u)if(!use[u])
	{
		int fsb=lca(top,u);
		if(fsb==top)
		{
			int limit=dep[u]-dep[fsb],dis=0;
			for(int delta=1<<logn,j=logn,v=u;delta;delta>>=1,--j)if(dis+delta<limit&&!use[fa[v][j]])v=fa[v][j],dis+=delta;
			++dis;
			if(dis<=k)
			{
				k-=dis;
				for(int i=0,v=u;i<dis;v=fa[v][0],++i)use[v]=true;
			}
		}
		else
		{
			int dis1=dep[u]-dep[fsb],dis2=dep[top]-dep[fsb];
			if(dis1+dis2<=k)
			{
				k-=dis1+dis2;
				for(int i=0,v=u;i<dis1;v=fa[v][0],++i)use[v]=true;
				for(int i=0,v=fa[top][0];i<dis2;v=fa[v][0],++i)use[v]=true;
				top=fsb;
			}
		}
	}
	F(i,0,n)if(!use[i])printf("%d ",i+1);
	puts("");
	return 0;
}