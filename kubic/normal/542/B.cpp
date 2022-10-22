#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define mid ((l+r)/2)
int n,m,tp,ds[N],z[N];struct Node {int l,r;}a1[N],a2[N];
struct Seg {int vl,tg;}sg[N*4];
bool cmp1(Node x,Node y) {return x.l<y.l;}
bool cmp2(Node x,Node y) {return x.r<y.r;}
void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
void pd(int p) {if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void pu(int p) {sg[p].vl=max(sg[p*2].vl,sg[p*2+1].vl);}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}
	pd(p);if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
void upd1(int p,int l,int r,int x,int vl)
{
	if(l==r) {sg[p].vl=vl;return;}pd(p);
	if(x<=mid) upd1(p*2,l,mid,x,vl);else upd1(p*2+1,mid+1,r,x,vl);pu(p);
}
int qMx(int p,int l,int r,int qL,int qR)
{
	if(qL>qR) return 0;if(l>=qL && r<=qR) return sg[p].vl;
	pd(p);int res=0;if(qL<=mid) res=qMx(p*2,l,mid,qL,qR);
	if(qR>mid) res=max(res,qMx(p*2+1,mid+1,r,qL,qR));return res;
}
int qry(int p,int l,int r,int vl)
{
	if(l==r) return l;pd(p);if(vl<=sg[p*2].vl) return qry(p*2,l,mid,vl);
	return qry(p*2+1,mid+1,r,vl);
}
int main()
{
	scanf("%d %d",&n,&m);z[0]=-m;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a1[i].l,&a1[i].r);
		a1[i].l=max(a1[i].l,0);a1[i].r=max(a1[i].r,-1);
		a2[i]=a1[i];ds[++ds[0]]=a1[i].l;ds[++ds[0]]=a1[i].r+1;
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	sort(a1+1,a1+n+1,cmp1);sort(a2+1,a2+n+1,cmp2);
	for(int i=1,l,r,t,t1=1,t2=1;i<ds[0];++i)
	{
		l=ds[i];r=ds[i+1]-1;
		while(t1<=n && a1[t1].l<=l)
			upd(1,0,n,0,lower_bound(z,z+tp+1,a1[t1++].l)-z-1,1);
		while(t2<=n && a2[t2].r<l)
			upd(1,0,n,0,lower_bound(z,z+tp+1,a2[t2++].l)-z-1,-1);
		t=qMx(1,0,n,0,upper_bound(z+1,z+tp+1,r-m)-z-1);
		while(tp<t) ++tp,z[tp]=max(z[qry(1,0,n,tp)]+m,l),upd1(1,0,n,tp,tp);
	}printf("%d\n",tp);return 0;
}