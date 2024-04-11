#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define INF 0x3f3f3f3f
#define ll long long
#define mid ((l+r)>>1) 
int n,m,tp1,tp2,a[N],st1[N],st2[N];ll ans;struct Seg {int tg,vl[2];}sg[N<<2];
void mdf(int p,int vl) {sg[p].vl[0]+=vl;sg[p].tg+=vl;}
void pu(int p)
{
	sg[p].vl[0]=min(sg[p<<1].vl[0],sg[p<<1|1].vl[0]);sg[p].vl[1]=0;
	if(sg[p<<1].vl[0]==sg[p].vl[0]) sg[p].vl[1]=sg[p<<1].vl[1];
	if(sg[p<<1|1].vl[0]==sg[p].vl[0]) sg[p].vl[1]+=sg[p<<1|1].vl[1];
}
void pd(int p) 
{if(sg[p].tg) mdf(p<<1,sg[p].tg),mdf(p<<1|1,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{
	if(l==r) {sg[p]=(Seg) {0,{INF,1}};return;}
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p); 
	if(qL<=mid) upd(p<<1,l,mid,qL,qR,vl);
	if(qR>mid) upd(p<<1|1,mid+1,r,qL,qR,vl);pu(p);
}
int qry(int p,int l,int r,int x)
{
	if(l==r) return sg[p].vl[0];pd(p);
	if(x<=mid) return qry(p<<1,l,mid,x);return qry(p<<1|1,mid+1,r,x);
}
int main()
{
	scanf("%d",&n);build(1,1,n);
	for(int i=1,x,y;i<=n;++i) scanf("%d %d",&x,&y),a[x]=y;
	for(int i=1;i<=n;++i)
	{
		while(tp1 && a[i]<a[st1[tp1]])
			upd(1,1,n,st1[tp1-1]+1,st1[tp1],a[st1[tp1]]-a[i]),--tp1;
		while(tp2 && a[i]>a[st2[tp2]])
			upd(1,1,n,st2[tp2-1]+1,st2[tp2],a[i]-a[st2[tp2]]),--tp2;
		upd(1,1,n,i,i,i-INF);st1[++tp1]=i;st2[++tp2]=i;
		if(sg[1].vl[0]==i) ans+=sg[1].vl[1];
	}printf("%lld\n",ans);return 0;
}