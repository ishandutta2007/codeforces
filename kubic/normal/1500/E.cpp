#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define ll unsigned long long
#define mid ((l+r)/2)
int n,m,n1,op[N];ll a[N],b[N],ds[N];struct Seg {ll vl[4];}sg[N*4];
int qId(ll x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
Seg merge(Seg tL,Seg tR)
{
	Seg res;res.vl[0]=tL.vl[0]+tR.vl[0];res.vl[1]=tL.vl[1]+tR.vl[1];
	res.vl[2]=tL.vl[2]+tR.vl[2]+tL.vl[1]*tR.vl[0];
	res.vl[3]=tL.vl[3]+tR.vl[3]+tL.vl[0]*tR.vl[1];return res;
}
void pu(int p) {sg[p]=merge(sg[p*2],sg[p*2+1]);}
void upd1(int p,int l,int r,int x,int w)
{
	if(l==r)
	{
		sg[p].vl[0]+=w;sg[p].vl[1]+=ds[l]*w;
		sg[p].vl[2]=sg[p].vl[3]=ds[l]*sg[p].vl[0]*(sg[p].vl[0]+1)/2;return;
	}if(x<=mid) upd1(p*2,l,mid,x,w);else upd1(p*2+1,mid+1,r,x,w);pu(p);
}
Seg qSg1(int p,int l,int r,int x)
{
	if(l==r) return (Seg) {{1ull*x,ds[l]*x,ds[l]*x*(x+1)/2,ds[l]*x*(x+1)/2}};
	if(x<=sg[p*2].vl[0]) return qSg1(p*2,l,mid,x);
	return merge(sg[p*2],qSg1(p*2+1,mid+1,r,x-sg[p*2].vl[0]));
}
Seg qSg2(int p,int l,int r,int x)
{
	if(l==r) return (Seg) {{1ull*x,ds[l]*x,ds[l]*x*(x+1)/2,ds[l]*x*(x+1)/2}};
	if(x<=sg[p*2+1].vl[0]) return qSg2(p*2+1,mid+1,r,x);
	return merge(qSg2(p*2,l,mid,x-sg[p*2+1].vl[0]),sg[p*2+1]);
}
Seg qry1(int x) {return qSg1(1,1,ds[0],x);}
Seg qry2(int x) {return qSg2(1,1,ds[0],x);}
void upd(ll vl,int w) {n1+=w;upd1(1,1,ds[0],qId(vl),w);}
void slv()
{
	int l=1,r=(n1+1)/2;ll res=0;
	while(l<=r)
	{
		ll tL=qry1(mid).vl[1],tR=qry2(mid-1).vl[1];
		if(tL>tR) l=mid+1;else r=mid-1;
	}if(r==(n1+1)/2) {printf("%llu\n",sg[1].vl[3]-sg[1].vl[2]);return;}
	res=qry2(r-1).vl[3]+qry2(n1).vl[3]-qry2(n1-r-1).vl[3];
	res-=qry1(r).vl[2]+qry1(n1).vl[2]-qry1(n1-r).vl[2];printf("%llu\n",res);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%llu",&a[i]),ds[++ds[0]]=a[i];
	for(int i=1;i<=m;++i) scanf("%d %llu",&op[i],&b[i]),ds[++ds[0]]=b[i];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i) upd(a[i],1);slv();
	for(int i=1;i<=m;++i) {if(op[i]==1) upd(b[i],1);else upd(b[i],-1);slv();}
	return 0;
}