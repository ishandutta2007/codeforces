#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define mid ((l+r)/2) 
const int lim=1e9,INF=1e9;
int n,m,cntS,rt,a[N],ans[N],vl[N];struct Query {int id,l,r;}b[N];
struct Seg {int vl,ch[2];}sg[N*30];
bool cmp(Query x,Query y) {return x.r<y.r;}
void pu(int p) {sg[p].vl=max(sg[sg[p].ch[0]].vl,sg[sg[p].ch[1]].vl);}
void upd(int &p,int l,int r,int x,int vl)
{
	if(!p) p=++cntS;if(l==r) {sg[p].vl=vl;return;}
	if(x<=mid) upd(sg[p].ch[0],l,mid,x,vl);else upd(sg[p].ch[1],mid+1,r,x,vl);pu(p);
}
int qMx(int p,int l,int r,int qL,int qR)
{
	if(!p || qL>qR) return 0;if(l>=qL && r<=qR) return sg[p].vl;int res=0;
	if(qL<=mid) res=qMx(sg[p].ch[0],l,mid,qL,qR);
	if(qR>mid) res=max(res,qMx(sg[p].ch[1],mid+1,r,qL,qR));return res;
}
void upd1(int x,int w) {for(;x;x-=x&-x) vl[x]=min(vl[x],w);}
int qry(int x) {int res=INF;for(;x<=n;x+=x&-x) res=min(res,vl[x]);return res;}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),vl[i]=INF;scanf("%d",&m);
	for(int i=1;i<=m;++i) scanf("%d %d",&b[i].l,&b[i].r),b[i].id=i;sort(b+1,b+m+1,cmp);
	for(int i=1,t=1,t1;i<=n;++i)
	{
		t1=qMx(rt,0,lim,a[i],lim);
		while(t1) upd1(t1,a[t1]-a[i]),t1=qMx(rt,0,lim,a[i],(a[i]+a[t1]-1)/2);
		t1=qMx(rt,0,lim,0,a[i]);
		while(t1) upd1(t1,a[i]-a[t1]),t1=qMx(rt,0,lim,(a[i]+a[t1])/2+1,a[i]);
		while(t<=m && b[t].r<=i) ans[b[t].id]=qry(b[t].l),++t;upd(rt,0,lim,a[i],i);
	}for(int i=1;i<=m;++i) printf("%d\n",ans[i]);return 0;
}