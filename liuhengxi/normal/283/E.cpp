// LUOGU_RID: 90544782
#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1e5+5;
namespace seg
{
	struct data{int c[2],tg;}s[(1<<18)+5];
#define lc (p<<1)
#define rc (p<<1|1)
#define c(p) s[p].c
#define tg(p) s[p].tg
	inline void flip(int p){swap(c(p)[0],c(p)[1]);tg(p)^=1;}
	inline void pushdown(int p)
	{
		if(!tg(p))return;
		flip(lc);flip(rc);
		tg(p)=0;
	}
	inline void pushup(int p)
	{
		c(p)[0]=c(lc)[0]+c(rc)[0];
		c(p)[1]=c(lc)[1]+c(rc)[1];
	}
	void build(int p,int l,int r)
	{
		c(p)[0]=r-l;
		if(r-l==1)return;
		int mid=(l+r)>>1;
		build(lc,l,mid);build(rc,mid,r);
	}
	void flip(int p,int l,int r,int x,int y)
	{
		if(x==l&&r==y)return flip(p);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)flip(lc,l,mid,x,y);
		else if(mid<=x)flip(rc,mid,r,x,y);
		else flip(lc,l,mid,x,mid),flip(rc,mid,r,mid,y);
		pushup(p);
	}
	int query(int p,int l,int r,int x)
	{
		if(r-l==1)return c(p)[1];
		int mid=(l+r)>>1;
		pushdown(p);
		if(x<mid)return query(lc,l,mid,x);
		else return query(rc,mid,r,x);
	}
#undef lc
#undef rc
#undef c
#undef tg
}
using seg::build;
using seg::flip;
using seg::query;
struct change
{
	int t,l,r;
}c[2*N];
int n,k,s[N],v[N];
long long ans;
int main()
{
	read(n,k);
	F(i,0,n)v[i]=read(s[i]);
	sort(v,v+n);
	F(i,0,n)s[i]=(int)(lower_bound(v,v+n,s[i])-v);
	F(i,0,k)
	{
		int ll,rr;
		read(ll,rr);++rr;
		ll=(int)(lower_bound(v,v+n,ll)-v);
		rr=(int)(lower_bound(v,v+n,rr)-v);
		c[i<<1].t=ll,c[i<<1].l=ll,c[i<<1].r=rr;
		c[i<<1|1].t=rr,c[i<<1|1].l=ll,c[i<<1|1].r=rr;
	}
	k<<=1;
	sort(c,c+k,[](change uu,change vv){return uu.t<vv.t;});
	ans=n*(n-1ull)*(n-2ull)/6ull;
	build(1,0,n);
	for(int i=0,j=0;i<n;++i)
	{
		for(;j<k&&c[j].t<=i;++j)if(c[j].l<c[j].r)seg::flip(1,0,n,c[j].l,c[j].r);
		seg::flip(1,0,n,i,i+1);
		int t=seg::s[1].c[1]-seg::query(1,0,n,i);
		ans-=t*(t-1ll)>>1;
	}
	printf("%lld\n",ans);
	return 0;
}