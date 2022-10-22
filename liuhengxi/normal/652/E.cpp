#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,M=3e5+5;
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
	int next,to,dis;
}e[2*N];
int n,m,hd[N],cnt,fa[N],tag[N],dep[N],bcc[N],val[N],to[N];
bool vis[N];
inline void adline(int u,int v,int w){e[cnt].to=v;e[cnt].dis=w;e[cnt].next=hd[u];hd[u]=cnt++;}
int find(int x){return bcc[x]==x?x:bcc[x]=find(bcc[x]);}
void dfs1(int u)
{
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u])continue;
		if(vis[v])(dep[u]>dep[v]&&(++tag[u],--tag[v]));
		else
		{
			fa[v]=u,dep[v]=dep[u]+1,dfs1(v);
			tag[u]+=tag[v];
			bcc[v]=tag[v]?u:v;
		}
	}
}
void dfs2(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u])continue;
		dep[v]=dep[fa[v]=u]+1,to[v]=e[i].dis;dfs2(v);
	}
}
int main()
{
	int s,t,ans=0;
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(--u,--v,w);adline(v,u,w);
	}
	dfs1(0);
	F(i,0,n)find(i);
	F(i,cnt=0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u=bcc[e[i<<1].to],v=bcc[e[i<<1|1].to],w=e[i<<1].dis;
		if(u==v)val[u]|=w;
		else adline(u,v,w),adline(v,u,w);
	}
	dfs2(0);
	read(s);read(t);s=bcc[s-1],t=bcc[t-1];
	while(s!=t)
	{
		if(dep[s]>dep[t])ans|=val[s]|to[s],s=fa[s];
		else ans|=val[t]|to[t],t=fa[t];
	}
	ans|=val[s];
	puts(ans?"YES":"NO");
	return 0;
}