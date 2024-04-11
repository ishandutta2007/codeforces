#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
const int INF=1e9;
int T,n,ans,a[N],ps[N];bool vs[N];struct Seg {int vl,tg;};
struct SegmentTree
{
	Seg sg[N*4];
	void pu(int p) {sg[p].vl=max(sg[p*2].vl,sg[p*2+1].vl);}
	void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
	void pd(int p)
	{
		if(sg[p].tg)
		{
			mdf(p*2,sg[p].tg);
			mdf(p*2+1,sg[p].tg);sg[p].tg=0;
		}
	}
	void build(int p,int l,int r)
	{
		sg[p]=(Seg) {-INF,0};if(l==r) return;
		build(p*2,l,mid);build(p*2+1,mid+1,r);
	}
	void upd(int p,int l,int r,int qL,int qR,int vl)
	{
		if(qL>qR) return;
		if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
		if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
		if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
	}
	void upd1(int p,int l,int r,int x,int vl)
	{
		if(l==r) {sg[p].vl=vl;return;}pd(p);
		if(x<=mid) upd1(p*2,l,mid,x,vl);
		else upd1(p*2+1,mid+1,r,x,vl);pu(p);
	}
}SGT;
struct BitArray
{
	int vl[N];void clear() {for(int i=1;i<=n;++i) vl[i]=0;}
	void upd(int x,int w) {for(;x<=n;x+=x&-x) vl[x]+=w;}
	int qSm(int x)
	{int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
}BIT;
void slv()
{
	scanf("%d",&n);ans=0;SGT.build(1,1,n);BIT.clear();
	for(int i=1,x;i<=n;++i) scanf("%d",&x),vs[i]=0,ps[x]=i;
	for(int i=1,t,t1=1;i<=n;++i)
	{
		t=ps[i];BIT.upd(t,1);vs[t]=1;
		SGT.upd1(1,1,n,t,t+(t&1)+i-BIT.qSm(t)*2);
		while(t1<=n && vs[t1]) SGT.upd1(1,1,n,t1++,-INF);
		SGT.upd(1,1,n,1,t-1,1);SGT.upd(1,1,n,t+1,n,-1);
		ans=max(ans,SGT.sg[1].vl);
	}printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}