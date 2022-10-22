#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,a[N],hd[N],cnt,f[N],g[N],ans[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		if(f[v]>0)f[u]+=f[v];
	}
	f[u]+=a[u];
}
void dfs1(int u,int fa)
{
	ans[u]=f[u]+g[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		g[v]=ans[u];
		if(f[v]>0)g[v]-=f[v];
		if(g[v]<0)g[v]=0;
		dfs1(v,u);
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),a[i]=a[i]*2-1;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);dfs1(0,0);
	F(i,0,n)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}