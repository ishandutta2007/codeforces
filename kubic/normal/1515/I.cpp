#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define M 19
#define ll long long
#define clz __builtin_clzll
#define mid ((l+r)/2)
const ll INF=2e18;
int n,m,rv[N];struct Node {int w1,w2,id;ll x;}a[N];
bool cmp(Node x,Node y) {return x.w2==y.w2?x.w1<y.w1:x.w2>y.w2;}
struct Seg {ll vl,vl1,vl2,tg1,tg2;};
struct SegmentTree
{
	Seg sg[N*4];
	void pu(int p)
	{
		sg[p].vl1=min(sg[p*2].vl1,sg[p*2+1].vl1);
		sg[p].vl2=min(sg[p*2].vl2,sg[p*2+1].vl2);
	}
	void mdf(int p,ll vl1,ll vl2)
	{
		sg[p].vl1+=vl1;sg[p].vl2+=vl1;sg[p].vl+=vl2;
		sg[p].tg1+=vl1;sg[p].tg2+=vl2;
	}
	void pd(int p)
	{
		mdf(p*2,sg[p].tg1,sg[p].tg2);
		mdf(p*2+1,sg[p].tg1,sg[p].tg2);sg[p].tg1=sg[p].tg2=0;
	}
	void build(int p,int l,int r,int vl)
	{
		if(l==r)
		{
			int d=63-clz(a[l].w1);sg[p]=(Seg) {0,INF,INF,0,0};
			if(d<vl) sg[p].vl1+=a[l].w1,sg[p].vl+=a[l].w2;
			if(d==vl) sg[p].vl2+=a[l].w1,sg[p].vl+=a[l].w2;return;
		}build(p*2,l,mid,vl);build(p*2+1,mid+1,r,vl);pu(p);
	}
	void upd(int p,int l,int r,int qL,int qR,ll vl1,ll vl2)
	{
		if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl1,vl2);return;}
		pd(p);if(qL<=mid) upd(p*2,l,mid,qL,qR,vl1,vl2);
		if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl1,vl2);pu(p);
	}
	void updPt(int p,int l,int r,int x,ll vl1,ll vl2)
	{
		if(l==r) {sg[p].vl1+=vl1;sg[p].vl2+=vl2;return;}pd(p);
		if(x<=mid) updPt(p*2,l,mid,x,vl1,vl2);
		else updPt(p*2+1,mid+1,r,x,vl1,vl2);pu(p);
	}
	Seg qPt(int p,int l,int r,int x)
	{
		if(!x) return (Seg) {0,0,0,0,0};if(l==r) return sg[p];pd(p);
		if(x<=mid) return qPt(p*2,l,mid,x);return qPt(p*2+1,mid+1,r,x);
	}
	int qry1(int p,int l,int r,ll vl)
	{
		if(sg[p].vl1>vl) return 0;if(l==r) return l;pd(p);
		if(sg[p*2+1].vl1>vl) return qry1(p*2,l,mid,vl);
		return qry1(p*2+1,mid+1,r,vl);
	}
	int qry2(int p,int l,int r,int x,ll vl)
	{
		if(sg[p].vl2>vl) return 0;if(l==r) return l;int t;pd(p);
		if(x<mid && sg[p*2].vl2<=vl)
		{t=qry2(p*2,l,mid,x,vl);if(t) return t;}
		return qry2(p*2+1,mid+1,r,x,vl);
	}
}SGT[M];
void upd(int x,ll vl)
{
	int d=63-clz(a[x].w1);
	for(int i=18;i>d;--i) SGT[i].upd(1,1,n,x+1,n,vl*a[x].w1,vl*a[x].w2);
	if(!a[x].x)
	{
		for(int i=18;i>d;--i) SGT[i].updPt(1,1,n,x,-INF,0);
		SGT[d].updPt(1,1,n,x,0,-INF);
	}a[x].x+=vl;
	if(!a[x].x)
	{
		for(int i=18;i>d;--i) SGT[i].updPt(1,1,n,x,INF,0);
		SGT[d].updPt(1,1,n,x,0,INF);
	}
}
ll qry(ll vl)
{
	int d,x=0,x1,x2;ll t,res=0;Seg t1,t2,t3;
	while(vl && x<n)
	{
		d=min(63-clz(vl),18);t3=SGT[d].qPt(1,1,n,x);
		if(x)
		{
			if(63-clz(a[x].w1)<d)
			{
				t3.vl1+=(a[x].x-1)*a[x].w1;
				t3.vl+=(a[x].x-1)*a[x].w2;if(!a[x].x) t3.vl1-=INF;
			}else {t3.vl1-=INF;if(63-clz(a[x].w1)==d) t3.vl-=a[x].w2;}
		}x2=SGT[d].qry2(1,1,n,x,vl+t3.vl1);
		if(x2)
		{
			x=x2;t2=SGT[d].qPt(1,1,n,x);
			vl-=t2.vl2-t3.vl1;res+=t2.vl-t3.vl;continue;
		}x1=SGT[d].qry1(1,1,n,vl+t3.vl1);
		if(x1>x)
		{
			x=x1;t1=SGT[d].qPt(1,1,n,x);vl-=t1.vl1-t3.vl1;
			t=min(vl/a[x].w1,a[x].x-1);
			vl-=t*a[x].w1;res+=t1.vl-t3.vl+t*a[x].w2;continue;
		}break;
	}return res;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		a[i].id=i,scanf("%lld %d %d",&a[i].x,&a[i].w1,&a[i].w2);
	sort(a+1,a+n+1,cmp);for(int i=1;i<=n;++i) rv[a[i].id]=i;
	for(int i=0;i<=18;++i) SGT[i].build(1,1,n,i);
	for(int i=1;i<=n;++i) {ll t=a[i].x;a[i].x=0;upd(i,t);}
	for(int i=1,op,x;i<=m;++i)
	{
		ll vl;scanf("%d %lld",&op,&vl);
		if(op==1) scanf("%d",&x),upd(rv[x],vl);
		if(op==2) scanf("%d",&x),upd(rv[x],-vl);
		if(op==3) printf("%lld\n",qry(vl));
	}return 0;
}