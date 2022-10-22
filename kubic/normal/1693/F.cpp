#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
int T,n,s,ans;char a[N];struct Seg {int vl,mn,mx,tg;}sg[N*4];
void mdf(int p,int l,int r,int vl)
{
	sg[p].tg=vl;sg[p].vl=vl*(r-l+1);
	sg[p].mn=min(sg[p].vl,vl);sg[p].mx=max(sg[p].vl,vl);
}
void pd(int p,int l,int r)
{
	if(sg[p].tg)
	{
		mdf(p*2,l,mid,sg[p].tg);
		mdf(p*2+1,mid+1,r,sg[p].tg);sg[p].tg=0;
	}
}
void pu(int p)
{
	sg[p].vl=sg[p*2].vl+sg[p*2+1].vl;
	sg[p].mn=min(sg[p*2].mn,sg[p*2].vl+sg[p*2+1].mn);
	sg[p].mx=max(sg[p*2].mx,sg[p*2].vl+sg[p*2+1].mx);
}
void build(int p,int l,int r)
{
	sg[p].tg=0;if(l==r) {mdf(p,l,r,a[l]=='0'?-1:1);return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(l>=qL && r<=qR) {mdf(p,l,r,vl);return;}pd(p,l,r);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int qPt(int p,int l,int r,int x)
{
	if(l==r) return sg[p].vl;pd(p,l,r);
	if(x<=mid) return qPt(p*2,l,mid,x);
	return qPt(p*2+1,mid+1,r,x);
}
int qry(int p,int l,int r,int vl)
{
	if(vl<sg[p].mn || vl>sg[p].mx) return 0;if(l==r) return l;
	pd(p,l,r);int t=qry(p*2+1,mid+1,r,vl-sg[p*2].vl);
	if(t) return t;return qry(p*2,l,mid,vl);
}
void slv()
{
	scanf("%d %s",&n,a+1);s=ans=0;
	for(int i=1;i<=n;++i) if(a[i]=='0') --s;else ++s;
	if(s>0) {s=-s;reverse(a+1,a+n+1);for(int i=1;i<=n;++i) a[i]^=1;}
	build(1,1,n);
	for(int i=0,t;i<-s;++i) if(qPt(1,1,n,i+1)>0)
	{
		t=qry(1,1,n,-i);++ans;
		upd(1,1,n,i+1,(i+t)/2,-1);upd(1,1,n,(i+t)/2+1,t,1);
	}if(sg[1].mn>(s-n)/2) ++ans;printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}