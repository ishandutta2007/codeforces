#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define EPS 1e-10
#define ll long long
#define db double
const db PI=acos(-1);
int n,tp,tpD,vl[N],s[N];ll m;db L=0,R=2e4,ds[N];
struct Point {db x,y,r,angle;}a[N];
struct Node {db l,r;}b[N];struct Node1 {int l,r;}b1[N];
bool cmp(Node1 x,Node1 y) {return x.r<y.r;}
void upd(int x) {for(;x;x-=x&-x) ++vl[x];}
int qSm(int x) {int res=0;for(;x<=tpD;x+=x&-x) res+=vl[x];return res;}
bool chk(db w)
{
	ll res=0;tp=tpD=0;
	for(int i=1;i<=n;++i) if(w<a[i].r)
	{
		db t=acos(w/a[i].r),l=a[i].angle-t,r=a[i].angle+t;
		if(l<-PI) l+=PI*2;if(r>PI) r-=PI*2;if(l>r) swap(l,r);
		ds[++tpD]=l;ds[++tpD]=r;b[++tp]=(Node) {l,r};
	}sort(ds+1,ds+tpD+1);tpD=unique(ds+1,ds+tpD+1)-ds-1;
	for(int i=1;i<=tpD;++i) s[i]=vl[i]=0;
	for(int i=1;i<=tp;++i)
	{
		b1[i].l=lower_bound(ds+1,ds+tpD+1,b[i].l)-ds;
		b1[i].r=lower_bound(ds+1,ds+tpD+1,b[i].r)-ds;
	}sort(b1+1,b1+tp+1,cmp);
	for(int i=1;i<=tp;++i) ++s[b1[i].r],res+=qSm(b1[i].l),upd(b1[i].l);
	for(int i=1;i<=tpD;++i) s[i]+=s[i-1];
	for(int i=1;i<=tp;++i) res+=s[b1[i].l];res=1ll*tp*(tp-1)/2-res;
	return res<m;
}
int main()
{
	scanf("%d %lld",&n,&m);m=1ll*n*(n-1)/2-m+1;
	for(int i=1;i<=n;++i)
	{
		scanf("%lf %lf",&a[i].x,&a[i].y);
		a[i].r=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
		a[i].angle=atan2(a[i].y,a[i].x);
	}while(R-L>EPS) {db mid=(L+R)/2;if(chk(mid)) R=mid;else L=mid;}
	printf("%.9lf\n",R);return 0;
}