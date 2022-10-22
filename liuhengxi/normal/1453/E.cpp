#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
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
int tt,n,hd[N],cnt,f[N],ans,deg[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	if(deg[u]>1||u==0)f[u]=INF;else f[u]=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		if(f[v]+1>ans&&u!=0)ans=f[v]+1;
		if(f[v]<f[u])f[u]=f[v];
	}
	if(u==0)
	{
		int maxf=0;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(f[v]>maxf)maxf=f[v];
		}
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(f[v]==maxf)++maxf;
			else if(f[v]+1>ans)ans=f[v]+1;
		}
	}
	++f[u];
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,cnt=0,n)hd[i]=-1,deg[i]=0;
		F(i,0,n-1)
		{
			int u,v;read(u);read(v);
			adline(--u,--v);adline(v,u);
			++deg[u];++deg[v];
		}
		ans=1;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}