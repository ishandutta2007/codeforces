#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ls[p]
#define rc rs[p]
using namespace std;
const int N=1e5+5;
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
int n,col[N],hd[N],cnt,max[N<<5],ls[N<<5],rs[N<<5],ind,rt[N];
long long sum[N<<5],ans[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int build(int l,int r,int x)
{
	int mid=(l+r)>>1,p=++ind;max[p]=1;sum[p]=x+1;
	if(r-l==1)return p;
	if(x<mid)lc=build(l,mid,x);else rc=build(mid,r,x);
	return p;
}
int merge(int p,int q)
{
	if(!p||!q)return p^q;
	if(!lc&&!rc)
	{
		max[p]+=max[q];
		return p;
	}
	lc=merge(lc,ls[q]);rc=merge(rc,rs[q]);
	if(max[lc]==max[rc])sum[p]=sum[lc]+sum[rc],max[p]=max[lc];
	else
		if(max[lc]>max[rc])max[p]=max[lc],sum[p]=sum[lc];
		else max[p]=max[rc],sum[p]=sum[rc];
	return p;
}
void dfs(int u,int fa)
{
	rt[u]=build(0,n,col[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
	ans[u]=sum[rt[u]];
}
int main()
{
	read(n);
	F(i,0,n)read(col[i]),--col[i],hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);
	F(i,0,n)printf("%lld ",ans[i]);
	puts("");
	return 0;
}