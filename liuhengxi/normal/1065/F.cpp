#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
int n,k,to[N],hd[N],cnt,sta[N],top,dfn[N],low[N],ind,scc[N],scccnt,m,u[2*N],v[2*N],f[N];
bool ins[N],vis[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	if(!~hd[u])return to[u]=sta[top>k?top-k:0],void();
	sta[top++]=u;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
	}
	--top;
}
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	sta[top++]=u;ins[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!~dfn[v])(tarjan(v),low[v]<low[u])&&(low[u]=low[v]);
		else if(ins[u]&&dfn[v]<low[u])low[u]=dfn[v];
	}
	if(dfn[u]==low[u])
	{
		while(sta[--top]!=u)ins[sta[top]]=false,scc[sta[top]]=scccnt;
		ins[u]=false,scc[u]=scccnt++;
	}
}
int dp(int u)
{
	int g=0;
	if(vis[u])return f[u];
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(dp(v)>g)g=dp(v);
	}
	return f[u]+=g;
}
int main()
{
	read(n,k);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		int p;
		adline(--read(p),i);
	}
	F(i,0,n)to[i]=-1;
	dfs(0);
	F(i,0,n)if(~to[i])adline(i,to[i]);
	F(i,0,n)dfn[i]=-1;
	tarjan(0);
	F(x,0,n)for(int i=hd[x];~i;i=e[i].next)u[m]=x,v[m++]=e[i].to;
	F(i,cnt=0,scccnt)hd[i]=-1;
	F(i,0,m)if(scc[u[i]]!=scc[v[i]])adline(scc[u[i]],scc[v[i]]);
	F(i,0,n)if(~to[i])++f[scc[i]];
	printf("%d\n",dp(scc[0]));
	return 0;
}