#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,M=3e4+5,MAX=0x7fffffff;
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
	int next,to,dis;
}e[M<<1];
int n,m,s,t,hd[N],cnt,f[N],x[M],y[M],z[M],ans=MAX,tag[N],dep[N],fa[N],to[N],c,r1,r2;
bool nec[M],un[M],vis[N],is[M<<1];
inline void adline(int u,int v,int w){e[cnt].to=v;e[cnt].dis=w;e[cnt].next=hd[u];hd[u]=cnt++;}
int find(int xx){return f[xx]==xx?xx:f[xx]=find(f[xx]);}
void dfs1(int u)
{
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(un[i>>1])continue;
		if(!vis[v])
		{
			is[i]=true;
			dep[v]=dep[u]+1;
			to[v]=i>>1;
			fa[v]=u;
			dfs1(v);
		}
	}
}
void dfs2(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(un[i>>1]||!vis[v])continue;
		if(!is[i]&&dep[v]>dep[u])++tag[v],--tag[u];
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(un[i>>1]||!vis[v])continue;
		if(is[i])
		{
			dfs2(v);
			tag[u]+=tag[v];
		}
	}
}
int main()
{
	read(n,m);
	--read(s),--read(t);
	F(i,0,n)hd[f[i]=i]=-1;
	F(i,0,m)
	{
		--read(x[i]),--read(y[i]),read(z[i]);
		adline(x[i],y[i],z[i]);adline(y[i],x[i],z[i]);
		if(find(x[i])!=find(y[i]))nec[i]=true,f[find(x[i])]=find(y[i]);
	}
	if(find(s)!=find(t))return puts("0\n0\n"),0;
	F(i,0,m)if(nec[i])
	{
		un[i]=true;
		F(j,0,n)vis[j]=false,tag[j]=0;
		F(j,0,m<<1)is[j]=false;
		dfs1(s);
		if(vis[t])
		{
			dfs2(s);
			for(int u=t;u!=s;u=fa[u])if(!tag[u])if(z[i]+z[to[u]]<ans)ans=z[i]+z[to[u]],c=2,r1=i,r2=to[u];
		}
		else if(z[i]<ans)ans=z[i],c=1,r1=i;
		un[i]=false;
	}
	if(ans==MAX)return puts("-1"),0;
	printf("%d\n%d\n",ans,c);
	printf("%d ",r1+1);
	if(c==2)printf("%d ",r2+1);
	puts("");
	return 0;
}