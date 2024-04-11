#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define mid ((l+r)>>1)
#define ls ((p<<1)+1)
#define rs ((p<<1)+2)
using namespace std;
const int N=2e5+5,M=3e5+5,Q=5e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct edge
{
	int u,v,del;
	bool operator<(edge b)const{return del>b.del;}
}e[M];
int n,m,q,pp[N],op[Q],x[Q],cnt,ii,ind,num[N],dfn[N],maxp[N<<2];
int f[2*N],rt[2*N],lc[2*N],rc[2*N],l[2*N],r[2*N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v)return;
	f[u]=f[v]=cnt;
	rt[u]=rt[v]=false;
	lc[cnt]=u;rc[cnt]=v;
	f[cnt]=cnt;
	rt[cnt++]=true;
}
void dfs(int u)
{
	l[u]=ind;
	if(u<n)num[dfn[u]=ind++]=u;
	else dfs(lc[u]),dfs(rc[u]);
	r[u]=ind;
}
void build(int p,int l,int r)
{
	if(r-l==1)maxp[p]=num[l];
	else
	{
		build(ls,l,mid),build(rs,mid,r);
		maxp[p]=pp[maxp[ls]]>pp[maxp[rs]]?maxp[ls]:maxp[rs];
	}
}
int query(int p,int l,int r,int x,int y)
{
	int a,b;
	if(y<=l||r<=x)return num[x];
	if(x<=l&&r<=y)return maxp[p];
	a=query(ls,l,mid,x,y);
	b=query(rs,mid,r,x,y);
	return pp[a]>pp[b]?a:b;
}
void update(int p,int l,int r,int x,int v)
{
	if(r-l==1)return void(pp[maxp[p]]=v);
	if(x<mid)update(ls,l,mid,x,v);
	else update(rs,mid,r,x,v);
	maxp[p]=pp[maxp[ls]]>pp[maxp[rs]]?maxp[ls]:maxp[rs];
}
int main()
{
	read(n);read(m);read(q);cnt=n;
	F(i,0,n)read(pp[i]);
	F(i,0,m)
	{
		read(e[i].u);read(e[i].v);--e[i].u;--e[i].v;
		e[i].del=INF;
	}
	F(i,0,q)
	{
		read(op[i]),read(x[i]),--x[i];
		if(op[i]==2)e[x[i]].del=i;
	}
	sort(e,e+m);
	F(i,0,n)f[i]=i,rc[i]=lc[i]=-1,rt[i]=true;
	ii=q-1;
	F(i,0,m)
	{
		while(e[i].del<ii)
		{
			if(op[ii]==1)x[ii]=find(x[ii]);
			--ii;
		}
		merge(e[i].u,e[i].v);
	}
	while(~ii)
	{
		if(op[ii]==1)x[ii]=find(x[ii]);
		--ii;
	}
	F(i,0,cnt)if(rt[i])dfs(i);
	build(0,0,n);
	F(i,0,q)
	{
		if(op[i]==1)
		{
			int a=query(0,0,n,l[x[i]],r[x[i]]);
//			F(k,l[x[i]],r[x[i]])printf("%d ",num[k]+1);
//			printf("\n");
			printf("%d\n",pp[a]);
			update(0,0,n,dfn[a],0);
		}
	}
	return 0;
}