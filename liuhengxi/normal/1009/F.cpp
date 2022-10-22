#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ls[p]
#define rc rs[p]
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
	int next,to;
}e[2*N];
int n,hd[N],cnt,ans[N],dep[N],maxind[N*25],maxocc[N*25],ls[N*25],rs[N*25],rt[N],ind;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int build(int l,int r,int x)
{
	int mid=(l+r)>>1,p=++ind;
	maxind[p]=x;maxocc[p]=1;
	if(r-l==1)return p;
	if(x<mid)lc=build(l,mid,x);else rc=build(mid,r,x);
	return p;
}
int merge(int p,int q)
{
	if(!p||!q)return p^q;
	if(!lc&&!rc)return maxocc[p]+=maxocc[q],p;
	lc=merge(lc,ls[q]);
	rc=merge(rc,rs[q]);
	if(maxocc[rc]>maxocc[lc])maxocc[p]=maxocc[rc],maxind[p]=maxind[rc];
	else maxocc[p]=maxocc[lc],maxind[p]=maxind[lc];
	return p;
}
void dfs(int u,int fa)
{
	rt[u]=build(0,n,dep[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+1;dfs(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
	ans[u]=maxind[rt[u]]-dep[u];
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
	F(i,0,n)printf("%d\n",ans[i]);
	return 0;
}