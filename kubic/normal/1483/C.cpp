#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define mid ((l+r)/2)
#define set(a,vl) memset(a,vl,sizeof(a))
const ll INF=0x3f3f3f3f3f3f3f3f;int n,a[N],b[N];
struct Seg {ll vl[2];bool tg;}sg[N*4];
void mdf(int p) {sg[p].vl[0]=sg[p].vl[1]=-INF;sg[p].tg=1;}
void pd(int p) {if(sg[p].tg) mdf(p*2),mdf(p*2+1),sg[p].tg=0;}
void pu(int p)
{
	sg[p].vl[0]=max(sg[p*2].vl[0],sg[p*2+1].vl[0]);
	sg[p].vl[1]=max(sg[p*2].vl[1],sg[p*2+1].vl[1]);
}
void upd1(int p,int l,int r,int x,ll w)
{
	if(l==r) {sg[p].vl[0]=w;sg[p].vl[1]=w+b[l];return;}pd(p);
	if(x<=mid) upd1(p*2,l,mid,x,w);else upd1(p*2+1,mid+1,r,x,w);pu(p);
}
void upd2(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) {mdf(p);return;}pd(p);
	if(qL<=mid) upd2(p*2,l,mid,qL,qR);
	if(qR>mid) upd2(p*2+1,mid+1,r,qL,qR);pu(p); 
}
ll qSm(int p,int l,int r,int qL,int qR,bool fl)
{
	if(l>=qL && r<=qR) return sg[p].vl[fl];pd(p);ll res=-INF;
	if(qL<=mid) res=qSm(p*2,l,mid,qL,qR,fl);
	if(qR>mid) res=max(res,qSm(p*2+1,mid+1,r,qL,qR,fl));return res;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[a[i]]);mdf(1);upd1(1,1,n,a[1],0);
	for(int i=2;i<=n;++i)
	{
		ll t=max(qSm(1,1,n,a[i],n,0),sg[1].vl[1]);
		upd2(1,1,n,a[i],n);upd1(1,1,n,a[i],t);
	}printf("%lld\n",sg[1].vl[1]);return 0;
}