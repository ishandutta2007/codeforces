#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
	int next,to,w;
}e[2*N];
int n,m,hd[N],hd1[N],cnt,dfn[N],ind,low[N],sta[N],top,scc[N],scnt;
long long w[N],sum[N],f[N];
bool in[N],vis[N];
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	sta[top++]=u;in[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!~dfn[v])
		{
			tarjan(v);
			low[u]=low[u]<low[v]?low[u]:low[v];
		}
		else if(in[v])low[u]=low[u]<dfn[v]?low[u]:dfn[v];
	}
	if(low[u]==dfn[u])
	{
		while(sta[--top]!=u)scc[sta[top]]=scnt,in[sta[top]]=false;
		scc[u]=scnt++;in[u]=false;
	}
}
long long calc(int w)
{
	int now=0,step=1<<13,ww=w;
	while(step)
	{
		if(w>=step*(step+now*2ll-1)/2)w-=step*(step+now*2ll-1)/2,now+=step;
		step>>=1;
	}
	return now*(long long)ww-sum[now];
}
long long dfs(int u)
{
	if(vis[u])return f[u];
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)if(dfs(e[i].to)+e[i].w>f[u])
		f[u]=dfs(e[i].to)+e[i].w;
	return f[u]+=w[u];
}
int main()
{
	int start;
	F(i,1,(1<<14)+1)sum[i]=sum[i-1]+i*(i-1ll)/2;
	read(n);read(m);
	F(i,0,n)dfn[i]=hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(--u,--v,w);
	}
	F(i,0,n)if(!~dfn[i])tarjan(i);
	F(u,0,n)for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(scc[u]==scc[v])w[scc[u]]+=calc(e[i].w);
	}
	F(i,0,n)hd1[i]=hd[i];
	F(i,0,scnt)hd[i]=-1;
	F(u,0,n)for(int i=hd1[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(scc[u]!=scc[v])adline(scc[u],scc[v],e[i].w);
	}
	read(start);
	printf("%lld\n",dfs(scc[--start]));
	return 0;
}