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
int n,hd[N],cnt,siz[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	int ch=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		++ch;
	}
	if(!ch)++siz[u];
}
int dfs1(int u,int fa,int dep)//maximize
{
	int ans=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		int t=dfs1(v,u,dep+1);
		if(dep&1)//minimize
		{
			ans+=t;
		}
		else//maximize
		{
			if(siz[v]-t<siz[u]-ans)ans=siz[u]-siz[v]+t;
		}
	}
	return ans;
}
int dfs2(int u,int fa,int dep)//minimize
{
	int ans=siz[u]-1,ch=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		int t=dfs2(v,u,dep+1);
		if(dep&1)//minimize
		{
			if(t<ans)ans=t;
		}
		else//maximize
		{
			ans+=t+1-siz[v];
		}
		++ch;
	}
	return ans;
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);
	printf("%d %d\n",dfs1(0,0,0)+1,dfs2(0,0,0)+1);
	return 0;
}