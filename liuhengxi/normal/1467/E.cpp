#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,LogN=20;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
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
int n,logn,a[N],hd[N],cnt,aa[N],last[N],tag[N],f[N][LogN],dep[N],tot;
bool ok[N],bad,app[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	f[u][0]=fa;
	F(i,0,logn)f[u][i+1]=f[f[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		tag[v]+=tag[u];
		dfs2(v,u);
	}
	ok[u]=!tag[u];
}
bool dfs3(int u,int fa)
{
	if(app[a[u]])return true;
	app[a[u]]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		if(dfs3(v,u))return true;
	}
	app[a[u]]=false;
	return false;
}
int jump(int u,int x){for(int j=0;x;x>>=1,++j)if(x&1)u=f[u][j];return u;}
int lca(int u,int v)
{
	for(int &c=dep[u]>dep[v]?u:v,k=dep[c]-dep[c^u^v],j=0;k;k>>=1,++j)if(k&1)c=f[c][j];
	for(int i=logn;~--i;)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return u!=v?f[u][0]:u;
}
int main()
{
	F(i,0,read(n))aa[i]=read(a[i]);
	while((1<<logn)<n)++logn;
	sort(aa,aa+n);
	F(i,0,n)a[i]=(int)(lower_bound(aa,aa+n,a[i])-aa);
	F(i,0,n)last[i]=hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;--read(u),--read(v);
		adline(u,v);adline(v,u);
	}
	dfs1(0,0);
	F(u,0,n)
	{
		int &v=last[a[u]];
		if(~v)
		{
			int w=lca(u,v);
			++tag[u],++tag[v];
			if(w==u)--tag[u],--tag[jump(v,dep[v]-dep[u]-1)],++tag[0];
			if(w==v)--tag[v],--tag[jump(u,dep[u]-dep[v]-1)],++tag[0];
		}
		v=u;
	}
	dfs2(0,0);
	F(i,0,n)if(ok[i])bad=dfs3(i,i),i=n-1;
	if(bad)F(i,0,n)ok[i]=false;
	F(i,0,n)tot+=ok[i];
	printf("%d\n",tot);
	return 0;
}