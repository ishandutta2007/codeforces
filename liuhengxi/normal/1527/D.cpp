#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,LogN=20;
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
int tt,n,logn,hd[N],cnt,fa[N][LogN],dep[N],siz[N];
long long ans[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	fa[u][0]=f;
	F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
	siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
inline int jump(int u,int i){for(int j=0;i;i>>=1,++j)if(i&1)u=fa[u][j];return u;}
inline int lca(int u,int v)
{
	if(dep[u]>dep[v])u=jump(u,dep[u]-dep[v]);
	else v=jump(v,dep[v]-dep[u]);
	for(int j=logn;~j;--j)if(fa[u][j]!=fa[v][j])u=fa[u][j],v=fa[v][j];
	return u==v?u:fa[u][0];
}
inline int dis(int u,int v){return dep[u]+dep[v]-(dep[lca(u,v)]<<1);}
int main()
{
	read(tt);
	while(tt--)
	{
		int x,y,xy;
		read(n);
		F(i,cnt=0,n)hd[i]=-1;
		for(logn=0;(1<<logn)<n;++logn);
		F(i,0,n-1)
		{
			int u,v;read(u);read(v);
			adline(u,v);adline(v,u);
		}
		dfs(0,0);
		ans[0]=n*(n-1ll)/2;
		F(i,1,n+2)ans[i]=0;
		F(i,0,n)
		{
			if(i)
			{
				int dxy=dep[x]+dep[y]-(dep[xy]<<1),dxi=dis(x,i),dyi=dis(y,i);
				if(dxi+dyi!=dxy){if(dxy+dyi==dxi)y=i;else if(dxy+dxi==dyi)x=i;else break;xy=lca(x,y);}
				ans[i+1]=(x==xy?siz[0]-siz[jump(y,dep[y]-dep[x]-1)]:siz[x])*
				(long long)(y==xy?siz[0]-siz[jump(x,dep[x]-dep[y]-1)]:siz[y]);
			}
			else
			{
				ans[i+1]=ans[0];
				for(int ak=hd[i];~ak;ak=e[ak].next)
				{
					int v=e[ak].to;
					ans[i+1]-=siz[v]*(siz[v]-1ll)/2;
				}
				xy=x=y=i;
			}
		}
		F(i,0,n+1)printf("%lld ",ans[i]-ans[i+1]);
		puts("");
	}
	return 0;
}