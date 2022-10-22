#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 1000005
#define mid ((l+r)/2)
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int INF=1e9;char *P1,*P2,buf[LIM];
int n,ans,a[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
struct BitArray
{
	int vl[N];
	void upd(int x,int w) {for(;x<=n;x+=x&-x) vl[x]+=w;}
	int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
}BIT1,BIT2;
struct Seg {int vl,vl1,vl2,ps,tg;};
struct SegmentTree
{
	Seg sg[N*4];
	void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
	void pu(int p)
	{
		sg[p].vl=min(sg[p*2].vl,sg[p*2+1].vl);
		sg[p].vl1=max(sg[p*2].vl1,sg[p*2+1].vl1);
		sg[p].vl2=min(sg[p*2].vl2,sg[p*2+1].vl2);
		sg[p].ps=sg[p*2+(sg[p].vl!=sg[p*2].vl)].ps;
	}
	void pd(int p)
	{if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
	void build(int p,int l,int r)
	{
		if(l==r) {sg[p]=(Seg) {INF,-INF,INF,l,0};return;}
		build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
	}
	void upd(int p,int l,int r,int qL,int qR,int vl)
	{
		if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
		if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
		if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
	}
	void upd1(int p,int l,int r,int x,int vl,int vl1,int vl2)
	{
		if(l==r) {sg[p]=(Seg) {vl,vl1,vl2,l,0};return;}pd(p);
		if(x<=mid) upd1(p*2,l,mid,x,vl,vl1,vl2);
		else upd1(p*2+1,mid+1,r,x,vl,vl1,vl2);pu(p);
	}
	int upd2(int p,int l,int r,int qL,int qR,int vl,bool fl)
	{
		if(qL>qR || vl<=sg[p].vl2) return vl;
		if(l==r)
		{
			int t=fl?n-l+1:l;vl=sg[p].vl2;sg[p]=(Seg) {0,vl,INF,l,0};
			sg[p].vl=abs(a[t]-BIT2.qSm(a[t])-t+BIT1.qSm(t));return vl;
		}pd(p);
		if(qR>mid) vl=upd2(p*2+1,mid+1,r,qL,qR,vl,fl);
		if(qL<=mid) vl=upd2(p*2,l,mid,qL,qR,vl,fl);pu(p);return vl;
	}
	int qry(int p,int l,int r,int vl)
	{
		if(vl>sg[p].vl1) return n+1;if(l==r) return l;
		if(vl<sg[p*2].vl1) return qry(p*2,l,mid,vl);
		return qry(p*2+1,mid+1,r,vl);
	}
	int qry11(int p,int l,int r,int x)
	{
		if(sg[p].vl1==-INF) return n+1;if(l==r) return l;int t;
		if(x<=mid) {t=qry11(p*2,l,mid,x);if(t<=n) return t;}
		return qry11(p*2+1,mid+1,r,x);
	}
	int qry12(int p,int l,int r,int x)
	{
		if(sg[p].vl1==-INF) return 0;if(l==r) return l;int t;
		if(x>mid) {t=qry12(p*2+1,mid+1,r,x);if(t) return t;}
		return qry12(p*2,l,mid,x);
	}
}ST1,ST2;
int main()
{
	n=rd();for(int i=1;i<=n;++i) a[i]=rd();a[n+1]=INF;
	ST1.build(1,1,n);ST2.build(1,1,n);
	for(int i=1;i<=n;++i) if(i<a[i]) ST1.upd1(1,1,n,i,INF,-INF,a[i]);
		else ST2.upd1(1,1,n,n-i+1,INF,-INF,n-a[i]+1);
	ST1.upd2(1,1,n,1,n,INF,0);ST2.upd2(1,1,n,1,n,INF,1);
	for(int i=1,t,l,r;i<=n;++i) if(ST1.sg[1].vl<ST2.sg[1].vl)
	{
		ans=max(ans,ST1.sg[1].vl);t=ST1.sg[1].ps;
		ST1.upd1(1,1,n,t,INF,-INF,INF);
		BIT1.upd(t,1);BIT2.upd(a[t],1);
		l=ST1.qry(1,1,n,a[t]);ST1.upd(1,1,n,l,t,-1);
		l=ST2.qry(1,1,n,n-a[t]+1);ST2.upd(1,1,n,l,n-t+1,-1);
		l=ST1.qry12(1,1,n,t);r=ST1.qry11(1,1,n,t);
		ST1.upd2(1,1,n,l+1,r-1,a[r],0);
	}
	else
	{
		ans=max(ans,ST2.sg[1].vl);t=ST2.sg[1].ps;
		ST2.upd1(1,1,n,t,INF,-INF,INF);
		BIT1.upd(n-t+1,1);BIT2.upd(a[n-t+1],1);
		l=ST1.qry(1,1,n,a[n-t+1]);ST1.upd(1,1,n,l,n-t+1,-1);
		l=ST2.qry(1,1,n,n-a[n-t+1]+1);ST2.upd(1,1,n,l,t,-1);
		l=ST2.qry12(1,1,n,t);r=ST2.qry11(1,1,n,t);
		ST2.upd2(1,1,n,l+1,r-1,n-a[n-r+1]+1,1);
	}printf("%d\n",ans);return 0;
}