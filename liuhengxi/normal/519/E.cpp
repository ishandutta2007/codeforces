#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=18;
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
int n,hd[N],cnt,f[N][LogN],logn,dep[N],siz[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	f[u][0]=fa;
	F(i,0,logn)f[u][i+1]=f[f[u][i]][i];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	++siz[u];
}
int jump(int u,int x)
{
	int i=0;
	while(x)
	{
		if(x&1)u=f[u][i];
		x>>=1;++i;
	}
	return u;
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])u=jump(u,dep[u]-dep[v]);
	else v=jump(v,dep[v]-dep[u]);
	for(int i=logn-1;~i;--i)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	if(u==v)return u;
	return f[u][0];
}
int main()
{
	int m;
	read(n);
	while((1<<logn)<n)++logn;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);
	read(m);
	while(m--)
	{
		int u,v,a,ans;read(u);read(v);--u,--v;
		if((dep[u]^dep[v])&1)ans=0;
		else
		{
			if(u==v)ans=n;
			else
			{
				a=lca(u,v);
				if(dep[u]==dep[v])
				{
					int k=dep[u]-dep[a]-1;
					ans=n-siz[jump(u,k)]-siz[jump(v,k)];
				}
				else
				{
					int k=(dep[u]+dep[v]-(dep[a]<<1))>>1;
					if(dep[u]<dep[v])u^=v^=u^=v;
					ans=siz[jump(u,k)]-siz[jump(u,k-1)];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}