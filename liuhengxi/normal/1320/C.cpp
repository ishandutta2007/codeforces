#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(long long i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const long long N=2e5+5,M=1e6+5,INF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
long long n,m,p,v,a[N],ca[N],b[N],cb[N],x[N],y[N],z[N],ac[M],bc[M],id[N],t[N];
long long val[M<<2],tag[M<<2],ans;
void pushdown(long long p)
{
	val[lc]+=tag[p];tag[lc]+=tag[p];
	val[rc]+=tag[p];tag[rc]+=tag[p];
	tag[p]=0;
}
void build(long long p,long long l,long long r)
{
	long long mid=(l+r)>>1;
	if(r-l==1)return val[p]=-bc[l],void();
	build(lc,l,mid);build(rc,mid,r);
	val[p]=val[lc]>val[rc]?val[lc]:val[rc];
}
void update(long long p,long long l,long long r,long long x,long long y,long long v)
{
	long long mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return tag[p]+=v,val[p]+=v,void();
	pushdown(p);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	val[p]=val[lc]>val[rc]?val[lc]:val[rc];
}
bool cmp(long long u,long long v){return x[u]<x[v];}
int main()
{
	read(n);read(m);read(p);
	F(i,0,n)read(a[i]),read(ca[i]);
	F(i,0,m)read(b[i]),read(cb[i]);
	F(i,0,p)read(x[id[i]=i]),read(y[i]),read(z[i]);
	sort(id,id+p,cmp);
	F(i,0,p)t[i]=x[i];F(i,0,p)x[i]=++t[id[i]];
	F(i,0,p)t[i]=y[i];F(i,0,p)y[i]=++t[id[i]];
	F(i,0,p)t[i]=z[i];F(i,0,p)z[i]=t[id[i]];
	F(i,0,n)v=v>a[i]?v:a[i],--a[i];
	F(i,0,m)v=v>b[i]?v:b[i],--b[i];
	F(i,0,p)v=v>x[i]?v:x[i],--x[i];
	F(i,0,p)v=v>y[i]?v:y[i],--y[i];
	F(i,0,v)ac[i]=bc[i]=INF;
	F(i,0,n)if(ca[i]<ac[a[i]])ac[a[i]]=ca[i];
	F(i,0,m)if(cb[i]<bc[b[i]])bc[b[i]]=cb[i];
	for(long long i=v-2;~i;--i)ac[i]=ac[i]<ac[i+1]?ac[i]:ac[i+1];
	for(long long i=v-2;~i;--i)bc[i]=bc[i]<bc[i+1]?bc[i]:bc[i+1];
	build(0,0,v);
	ans=-ac[0]-bc[0];
	F(i,0,p)
	{
		update(0,0,v,y[i],v,z[i]);
		ans=ans>val[0]-ac[x[i]]?ans:val[0]-ac[x[i]];
	}
	printf("%lld\n",ans);
	return 0;
}