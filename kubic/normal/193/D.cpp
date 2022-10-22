#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define mid ((l+r)/2)
int n,a[N],b[N];ll ans;struct Seg {int tg,vl[2],vl1[2];}sg[N*4];
void pu(int p)
{
	sg[p].vl[0]=min(sg[p*2].vl[0],sg[p*2+1].vl[0]);
	sg[p].vl[1]=min(sg[p*2].vl[1],sg[p*2+1].vl[1]);
	if(sg[p].vl[0]!=sg[p*2].vl[0])
		sg[p].vl[1]=min(sg[p].vl[1],sg[p*2].vl[0]);
	if(sg[p].vl[0]!=sg[p*2+1].vl[0])
		sg[p].vl[1]=min(sg[p].vl[1],sg[p*2+1].vl[0]);
	sg[p].vl1[0]=sg[p].vl1[1]=0;
	if(sg[p].vl[0]==sg[p*2].vl[0]) sg[p].vl1[0]+=sg[p*2].vl1[0];
	if(sg[p].vl[0]==sg[p*2+1].vl[0]) sg[p].vl1[0]+=sg[p*2+1].vl1[0];
	if(sg[p].vl[1]==sg[p*2].vl[0]) sg[p].vl1[1]+=sg[p*2].vl1[0];
	if(sg[p].vl[1]==sg[p*2+1].vl[0]) sg[p].vl1[1]+=sg[p*2+1].vl1[0]; 
	if(sg[p].vl[1]==sg[p*2].vl[1]) sg[p].vl1[1]+=sg[p*2].vl1[1]; 
	if(sg[p].vl[1]==sg[p*2+1].vl[1]) sg[p].vl1[1]+=sg[p*2+1].vl1[1]; 
}
void mdf(int p,int vl) {sg[p].vl[0]+=vl;sg[p].vl[1]+=vl;sg[p].tg+=vl;}
void pd(int p) {if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{
	if(l==r)
	{
		sg[p].vl[0]=1e9;sg[p].vl[1]=2e9;
		sg[p].vl1[0]=sg[p].vl1[1]=1;return;
	}build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int main()
{
	scanf("%d",&n);b[0]=b[n+1]=1e9;
	for(int i=1,x;i<=n;++i) scanf("%d",&b[i]),a[b[i]]=i;build(1,1,n);
	for(int i=1,t1,t2;i<=n;++i)
	{
		t1=b[a[i]-1];t2=b[a[i]+1];if(t1>t2) swap(t1,t2);upd(1,1,n,i,i,-1e9);
		if(t1>i) upd(1,1,n,1,i,1);else if(t2>i) upd(1,1,n,t1+1,i,1);
		else upd(1,1,n,t2+1,i,1),upd(1,1,n,1,t1,-1);
		if(sg[1].vl[0]<3) ans+=sg[1].vl1[0];if(sg[1].vl[1]<3) ans+=sg[1].vl1[1];
	}printf("%lld\n",ans-n);return 0;
}