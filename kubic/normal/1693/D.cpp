#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
#define ll long long
const int INF=1e9;
int n,a[N];ll ans=1;struct Seg {int vl,tg;bool tg1;};
struct SegmentTree
{
	Seg sg[N*4];
	void mdf(int p,int vl)
	{
		sg[p].vl=max(sg[p].vl,vl);
		sg[p].tg=max(sg[p].tg,vl);
	}
	void mdf1(int p) {sg[p].vl=sg[p].tg=0;sg[p].tg1=1;}
	void pd(int p)
	{
		if(sg[p].tg1) mdf1(p*2),mdf1(p*2+1),sg[p].tg1=0;
		if(sg[p].tg)
		{
			mdf(p*2,sg[p].tg);
			mdf(p*2+1,sg[p].tg);sg[p].tg=0;
		}
	}
	void pu(int p) {sg[p].vl=max(sg[p].vl,sg[p*2+1].vl);}
	void upd(int p,int l,int r,int qL,int qR,int vl)
	{
		if(qL>qR) return;
		if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
		if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
		if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
	}
	void upd1(int p,int l,int r,int qL,int qR)
	{
		if(qL>qR) return;
		if(l>=qL && r<=qR) {mdf1(p);return;}pd(p);
		if(qL<=mid) upd1(p*2,l,mid,qL,qR);
		if(qR>mid) upd1(p*2+1,mid+1,r,qL,qR);pu(p);
	}
	int qry(int p,int l,int r,int vl)
	{
		if(vl>sg[p].vl) return n+1;if(l==r) return l;pd(p);
		if(vl<=sg[p*2].vl) return qry(p*2,l,mid,vl);
		return qry(p*2+1,mid+1,r,vl);
	}
}SGT1,SGT2;
int main()
{
	scanf("%d",&n);SGT1.mdf(1,INF);SGT2.mdf(1,INF);
	for(int i=1,t1,t2;i<=n;++i)
	{
		scanf("%d",&a[i]);if(i==1) continue;
		t1=SGT1.qry(1,1,n,a[i]);
		t2=SGT2.qry(1,1,n,n-a[i]+1);
		if(a[i]<a[i-1]) SGT1.upd1(1,1,n,1,i-1);
		else SGT2.upd1(1,1,n,1,i-1);
		SGT1.upd(1,1,n,t2,n,a[i-1]);
		SGT2.upd(1,1,n,t1,n,n-a[i-1]+1);
		ans+=i-min(SGT1.qry(1,1,n,1),SGT2.qry(1,1,n,1))+1;
	}printf("%lld\n",ans);return 0;
}