#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
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
}e[N];
int n,q,hd[N],cnt,dfn[N],ind,siz[N],a[N],aa[N],sum[N<<2];
bool tag[N<<2];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	dfn[u]=ind++;
	siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		siz[u]+=siz[v];
	}
}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	sum[p]=aa[l];
	if(r-l==1)return;
	build(lc,l,mid);build(rc,mid,r);
	sum[p]=sum[lc]+sum[rc];
}
void pushdown(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(tag[p])
	{
		sum[lc]=mid-l-sum[lc];
		sum[rc]=r-mid-sum[rc];
		tag[lc]=!tag[lc];
		tag[rc]=!tag[rc];
		tag[p]=false;
	}
}
void update(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return sum[p]=r-l-sum[p],tag[p]=!tag[p],void();
	pushdown(p,l,r);
	update(lc,l,mid,x,y);update(rc,mid,r,x,y);
	sum[p]=sum[lc]+sum[rc];
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return sum[p];
	pushdown(p,l,r);
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		int f;read(f);
		adline(--f,i);
	}
	F(i,0,n)read(a[i]);
	dfs(0);
	F(i,0,n)aa[dfn[i]]=a[i];
	build(0,0,n);
	read(q);
	while(q--)
	{
		char op[4];
		int x;
		scanf("%s%d",op,&x);--x;
		if(op[0]=='p')
		{
			update(0,0,n,dfn[x],dfn[x]+siz[x]);
		}
		else
		{
			printf("%d\n",query(0,0,n,dfn[x],dfn[x]+siz[x]));
		}
	}
	return 0;
}