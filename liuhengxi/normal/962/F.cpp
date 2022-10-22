#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=20;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to;
}e[N<<1];
int n,m,x[N],y[N],lcaxy[N],f[N],hd[N],cnt,fa[N][LogN],logn,dep[N],a[N],b[N],up[N],anstot;
bool no[N],vis[N],rt[N],ok[N],ans[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
inline int lca(int u,int v)
{
	for(int &c=dep[u]>dep[v]?u:v,k=dep[c]-dep[c^u^v],j=0;k;k>>=1,++j)if(k&1)c=fa[c][j];
	for(int j=logn;~--j;)if(fa[u][j]!=fa[v][j])u=fa[u][j],v=fa[v][j];
	return u==v?u:fa[u][0];
}
void dfs1(int u,int f)
{
	vis[u]=true;
	fa[u][0]=f;
	F(i,0,logn-1)fa[u][i+1]=fa[fa[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
	}
}
void dfs2(int u,int f)
{
	b[u]=a[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dfs2(v,u);
		b[u]+=b[v];
	}
}
void dfs3(int u,int f)
{
	up[u]=b[u]<2&&u!=f?up[f]+1:0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dfs3(v,u);
	}
}
int main()
{
	F(i,0,read(n))hd[f[i]=i]=-1;
	while((1<<logn)<n)++logn;
	F(i,0,read(m))
	{
		--read(x[i]),--read(y[i]);
		if(find(x[i])==find(y[i]))no[i]=true;
		else
		{
			f[f[x[i]]]=f[y[i]];
			adline(x[i],y[i]),adline(y[i],x[i]);
		}
	}
	F(i,0,n)if(!vis[i])dfs1(i,i),rt[i]=true;
	F(i,0,m)if(no[i])++a[x[i]],++a[y[i]],a[lcaxy[i]=lca(x[i],y[i])]-=2;
	F(i,0,n)if(rt[i])dfs2(i,i);
	F(i,0,n)if(rt[i])dfs3(i,i);
	F(i,0,m)if(no[i])if(!(ans[i]=ok[i]=dep[x[i]]-up[x[i]]<=dep[lcaxy[i]]&&dep[y[i]]-up[y[i]]<=dep[lcaxy[i]]))
		++a[x[i]],++a[y[i]],a[lcaxy[i]]-=2;
	F(i,0,n)if(rt[i])dfs2(i,i);
	F(i,0,m)if(!no[i])ans[i]=b[dep[x[i]]>dep[y[i]]?x[i]:y[i]]==1;
	F(i,0,m)if(ans[i])++anstot;
	printf("%d\n",anstot);
	F(i,0,m)if(ans[i])printf("%d ",i+1);
	puts("");
	return 0;
}