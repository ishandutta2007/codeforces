#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
#define ll long long
int n,m,a[N],s[N],ps[N];ll s1,s2;
int f(int x,int y) {return x<y?y-x:n*2-x+y+1;}
int f1(int x) {return x<=n*2?x:0;}
struct Seg {int vl,tg;}sg[N*4];
void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
void pu(int p) {sg[p].vl=min(sg[p*2].vl,sg[p*2+1].vl);}
void pd(int p) {mdf(p*2,sg[p].tg);mdf(p*2+1,sg[p].tg);sg[p].tg=0;}
void build(int p,int l,int r)
{
	if(l==r) {sg[p].vl=s[l];return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int qPt(int p,int l,int r,int x)
{
	if(l==r) return sg[p].vl;pd(p);
	if(x<=mid) return qPt(p*2,l,mid,x);return qPt(p*2+1,mid+1,r,x);
}
int qry(int p,int l,int r)
{
	if(l==r) return l;pd(p);
	if(sg[p].vl==sg[p*2].vl) return qry(p*2,l,mid);
	return qry(p*2+1,mid+1,r);
}
void init()
{
	for(int i=1;i<=n*2+1;++i)
	{s[i]=s[i-1];if(a[i]<=n) --s[i];if(a[i]>n+1) ++s[i];}
	build(1,0,n*2+1);for(int i=1;i<=n*2+1;++i) ps[a[i]]=i;
	s1=f(ps[n+1],ps[1]);s2=f(ps[n*2+1],ps[n+1]);
	for(int i=1;i<=n;++i) s1+=f(ps[i],ps[i+1]);
	for(int i=n+1;i<=n*2;++i) s2+=f(ps[i],ps[i+1]);
}
void upd1(int x,int y)
{
	if(x<=n)
	{
		upd(1,0,n*2+1,ps[x],n*2+1,1);
		s1-=f(ps[x>1?x-1:n+1],ps[x])+f(ps[x],ps[x+1]);ps[x]=y;
		upd(1,0,n*2+1,ps[x],n*2+1,-1);
		s1+=f(ps[x>1?x-1:n+1],ps[x])+f(ps[x],ps[x+1]);return;
	}
	if(x>n+1)
	{
		upd(1,0,n*2+1,ps[x],n*2+1,-1);
		s2-=f(ps[x-1],ps[x])+f(ps[x],ps[x<=n*2?x+1:n+1]);ps[x]=y;
		upd(1,0,n*2+1,ps[x],n*2+1,1);
		s2+=f(ps[x-1],ps[x])+f(ps[x],ps[x<=n*2?x+1:n+1]);return;
	}s1-=f(ps[n],ps[x])+f(ps[x],ps[1]);
	s2-=f(ps[n*2+1],ps[x])+f(ps[x],ps[n+2]);ps[x]=y;
	s1+=f(ps[n],ps[x])+f(ps[x],ps[1]);
	s2+=f(ps[n*2+1],ps[x])+f(ps[x],ps[n+2]);
}
void slv()
{
	if(qPt(1,0,n*2+1,ps[n+1])!=sg[1].vl)
	{printf("%d\n",qry(1,0,n*2+1));return;}
	if(s1>n*2+1) {printf("%d\n",f1(ps[n+1]));return;}
	if(s2>n*2+1) {printf("%d\n",ps[n+1]-1);return;}printf("-1\n");
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*2+1;++i) scanf("%d",&a[i]);init();
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d %d",&x,&y);upd1(a[x],y);upd1(a[y],x);
		swap(a[x],a[y]);slv();
	}return 0;
}