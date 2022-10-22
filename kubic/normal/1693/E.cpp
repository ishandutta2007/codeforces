#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define mid ((l+r)/2)
int n,a[N],b[N],cnt[N][2];ll ans;
struct Seg {int vl[3],vl1[3];}z[4],sg[N*4];
Seg merge(Seg tL,Seg tR)
{
	Seg res;
	res.vl[0]=tL.vl[tR.vl1[0]]+tR.vl[0];
	res.vl1[0]=tL.vl1[tR.vl1[0]];
	res.vl[1]=tL.vl[tR.vl1[1]]+tR.vl[1];
	res.vl1[1]=tL.vl1[tR.vl1[1]];
	res.vl[2]=tL.vl[tR.vl1[2]]+tR.vl[2];
	res.vl1[2]=tL.vl1[tR.vl1[2]];
	return res;
}
void pu(int p) {sg[p]=merge(sg[p*2],sg[p*2+1]);}
void build(int p,int l,int r)
{
	if(l==r) {sg[p]=z[0];return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int x,int vl)
{
	if(l==r) {b[l]+=vl;sg[p]=z[b[l]];return;}
	if(x<=mid) upd(p*2,l,mid,x,vl);
	else upd(p*2+1,mid+1,r,x,vl);pu(p);
}
Seg qSg(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p];Seg tL,tR;
	if(qL<=mid) tL=qSg(p*2,l,mid,qL,qR);
	if(qR>mid) tR=qSg(p*2+1,mid+1,r,qL,qR);
	if(qL<=mid && qR>mid) return merge(tL,tR);
	if(qL<=mid) return tL;return tR;
}
int main()
{
	scanf("%d",&n);
	z[0]=(Seg) {{0,0,0},{0,1,2}};z[1]=(Seg) {{0,0,1},{1,1,0}};
	z[2]=(Seg) {{0,1,0},{2,0,2}};z[3]=(Seg) {{1,1,1},{0,0,0}};
	cnt[0][0]=cnt[0][1]=1;build(1,0,n);upd(1,0,n,0,3);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),++cnt[a[i]][1];
	for(int i=1;i<=n;++i) if(cnt[i][1]) upd(1,0,n,i,2);
	for(int i=1;i<=n;++i)
	{
		--cnt[a[i]][1];if(!cnt[a[i]][1]) upd(1,0,n,a[i],-2);
		if(a[i]) ans+=qSg(1,0,n,0,a[i]-1).vl[0];
		if(!cnt[a[i]][0]) upd(1,0,n,a[i],1);++cnt[a[i]][0];
	}printf("%lld\n",ans);return 0;
}