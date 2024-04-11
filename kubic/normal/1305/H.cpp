#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,c,ps,l,r,w1,ans,vl[N],st[N],z[N];
ll h,t,nw,s[N],lim[N],L[N],R[N],w[N];struct Node {int x,w;}a[N];
bool cmp(Node x,Node y) {return x.x<y.x;}
struct Point
{
	int x;ll y;Point(int _x=0,ll _y=0) {x=_x;y=_y;}
	Point operator - (Point t) const {return Point(x-t.x,y-t.y);}
}b[N];
ll crsMul(Point x,Point y) {return x.x*y.y-x.y*y.x;}
bool chk1(int x,int x1,int x2) {return crsMul(b[x1]-b[x],b[x2]-b[x])<=0;}
bool chk2()
{nw=0;for(int i=1;i<=m;++i) {nw+=z[i];if(nw<lim[i]) return 0;}return 1;}
bool chk(int x,bool fl=1)
{
	ps=c;for(int i=c;i;--i) if(m-x<a[i].x) ps=i-1;
	if(ps<c && a[ps+1].w<a[c].w) return 0;nw=h;
	for(int i=1;i<=c;++i) for(int j=a[i].x;j<a[i+1].x;++j) z[j]=a[i].w;
	for(int i=1;i<=ps;++i) w[i]=min(nw,R[i]-L[i]),nw-=w[i];if(nw) return 0;
	if(fl) w1=ps<c?a[ps+1].w-a[ps].w:(w[c]-1)/(m-a[c].x)+1;
	nw=max(1ll*w1*(a[ps+1].x-m+x-1)-w[ps],0ll);w[ps]+=nw;
	for(int i=ps-1;i;--i) t=min(nw,w[i]),nw-=t,w[i]-=t;if(nw) return 0;
	for(int i=1;i<ps;++i)
	{
		t=a[i+1].x-a[i].x-1;for(int j=a[i].x+1;j<a[i+1].x;++j) z[j]+=w[i]/t;
		if(t) for(int j=0;j<w[i]%t;++j) ++z[a[i+1].x-j-1];
	}for(int i=a[ps+1].x-1;i>m-x;--i) z[i]+=w1,w[ps]-=w1;
	t=m-x-a[ps].x;for(int i=m-x;i>a[ps].x;--i) z[i]+=w[ps]/t;
	if(t) for(int i=0;i<w[ps]%t;++i) ++z[m-x-i];return chk2();
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld %lld",&L[i],&R[i]),nw+=L[i],++vl[L[i]],--vl[R[i]];
	scanf("%d",&c);
	for(int i=1,x,w;i<=c;++i) scanf("%d %d",&x,&w),a[i]=(Node) {m-x+1,w};
	a[++c]=(Node) {0,0};sort(a+1,a+c+1,cmp);scanf("%lld",&h);
	for(int i=0;i<=m;++i) {if(i) vl[i]+=vl[i-1];if(nw<=h) ps=i;nw+=vl[i];}
	if(ps==-1 || (ps==m && nw<h)) {printf("-1 -1\n");return 0;}nw=0;
	for(int i=1;i<=n;++i) nw+=L[i];for(int i=0;i<ps;++i) nw+=vl[i];
	for(int i=1;i<=n;++i) if(ps<L[i]) s[i]=L[i];else if(ps>=R[i]) s[i]=R[i];
		else if(nw<h) ++nw,s[i]=ps+1;else s[i]=ps;sort(s+1,s+n+1);
	for(int i=1;i<=n;++i) s[i]+=s[i-1];reverse(s,s+n+1);
	for(int i=0;i<=n;++i)
	{
		b[i]=Point(i,s[i]);
		while(st[0]>1 && chk1(st[st[0]-1],st[st[0]],i)) --st[0];st[++st[0]]=i;
	}
	for(int i=m,t=1;i>=0;--i)
	{
		while(t<st[0] && crsMul(Point(1,-i),b[st[t+1]]-b[st[t]])<=0)
			++t;lim[i]=h-1ll*b[st[t]].x*i-b[st[t]].y;
	}reverse(lim,lim+m+1);a[c+1]=(Node) {m+1,n};
	for(int i=1;i<=c;++i)
	{
		L[i]=1ll*(a[i+1].x-a[i].x-1)*a[i].w;
		R[i]=1ll*(a[i+1].x-a[i].x-1)*a[i+1].w;h-=L[i]+a[i].w;
	}if(h<0) {printf("-1 -1\n");return 0;}
	l=1;r=m;while(l<=r) {int mid=(l+r)/2;if(chk(mid)) l=mid+1;else r=mid-1;}
	if(!r) {printf("-1 -1\n");return 0;}ans=r;printf("%d ",r);chk(r);
	if(ps<c) {printf("%d\n",z[m]);return 0;}l=w1;r=n-a[c].w;
	while(l<=r) {int mid=(l+r)/2;w1=mid;if(chk(ans,0)) l=mid+1;else r=mid-1;}
	printf("%d\n",a[c].w+r);return 0;
}