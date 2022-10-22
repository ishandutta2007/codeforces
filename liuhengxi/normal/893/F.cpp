#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=5e6+5,INF=0x3fffffff;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
struct line
{
	int next,to;
}e[2*N];
int n,r,a[N],hd[N],cnt,q,dep[N],t[N],ls[M],rs[M],val[M],ind;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int build(int l,int r,int x,int v)
{
	int mid=(l+r)>>1,p=++ind;
	val[p]=v;
	if(r-l==1)return p;
	if(x<mid)ls[p]=build(l,mid,x,v);
	else rs[p]=build(mid,r,x,v);
	return p;
}
int merge(int p,int q)
{
	int r;
	if(!p||!q)return p^q;
	r=++ind;
	val[r]=min(val[p],val[q]);
	ls[r]=merge(ls[p],ls[q]);
	rs[r]=merge(rs[p],rs[q]);
	return r;
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x||!p)return INF;
	if(x<=l&&r<=y)return val[p];
	return min(query(ls[p],l,mid,x,y),query(rs[p],mid,r,x,y));
}
void dfs(int u,int fa)
{
	t[u]=build(0,n,dep[u],a[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		t[u]=merge(t[u],t[v]);
	}
}
int main()
{
	read(n);--read(r);
	F(i,0,n)read(a[i]);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		int u,v;--read(u),--read(v);
		adline(u,v);adline(v,u);
	}
	dfs(r,r);
	read(q);
	for(int ans=0;q--;)
	{
		int x,k;(read(x)+=ans)%=n;(read(k)+=ans)%=n;
		printf("%d\n",ans=query(t[x],0,n,dep[x],min(dep[x]+k+1,n)));
	}
	return 0;
}