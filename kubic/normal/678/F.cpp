#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define pb push_back
#define po pop_back
#define ll long long
#define mid ((l+r)/2)
const ll INF=2e18;
int n,tp1,tp2;ll ans[N];bool vs[N];
struct Point
{
	int x,y;
	Point(int _x=0,int _y=0) {x=_x;y=_y;}
	bool operator < (Point t) const {return x==t.x?y<t.y:x<t.x;}
	Point operator - (Point t) const {return Point(x-t.x,y-t.y);}
};
struct Query {int F[3];}a[N];
struct Node1
{
	int l,r;Point vl;
	bool operator < (Node1 t) const {return vl<t.vl;}
}b1[N];
struct Node2
{
	int id,x,w;
	bool operator < (Node2 t) const {return w<t.w;}
}b2[N];
struct Seg {int nw;vector<Point> st;}sg[N*4];
ll crsMul(Point x,Point y) {return 1ll*x.x*y.y-1ll*x.y*y.x;}
void upd1(int p,Point vl)
{
	while(sg[p].st.size()>1)
	{
		int t=sg[p].st.size();
		Point t1=sg[p].st[t-1],t2=sg[p].st[t-2];
		if(crsMul(vl-t2,t1-t2)>0) break;sg[p].st.po();
	}sg[p].st.pb(vl);
}
ll qry1(int p,int w)
{
	if(!sg[p].st.size()) return -INF;
	while(sg[p].nw<sg[p].st.size()-1)
	{
		int t=sg[p].nw;
		if(crsMul(sg[p].st[t+1]-sg[p].st[t],Point(1,-w))>0)
			break;++sg[p].nw;
	}return 1ll*sg[p].st[sg[p].nw].x*w+sg[p].st[sg[p].nw].y;
}
void upd(int p,int l,int r,int qL,int qR,Point vl)
{
	if(l>=qL && r<=qR) {upd1(p,vl);return;}
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);
}
ll qry(int p,int l,int r,int x,int w)
{
	ll res=qry1(p,w);if(l==r) return res;
	if(x<=mid) return max(res,qry(p*2,l,mid,x,w));
	return max(res,qry(p*2+1,mid+1,r,x,w));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a[i].F[0],&a[i].F[1]);
		if(a[i].F[0]==1) scanf("%d",&a[i].F[2]);
	}
	for(int i=1,t;i<=n;++i) if(a[i].F[0]==2)
	{
		t=a[i].F[1];vs[t]=1;
		b1[++tp1]=(Node1) {t,i-1,Point(a[t].F[1],a[t].F[2])};
	}
	for(int i=1;i<=n;++i) if(a[i].F[0]==1 && !vs[i])
		b1[++tp1]=(Node1) {i,n,Point(a[i].F[1],a[i].F[2])};
	sort(b1+1,b1+tp1+1);
	for(int i=1;i<=tp1;++i) upd(1,1,n,b1[i].l,b1[i].r,b1[i].vl);
	for(int i=1;i<=n;++i) if(a[i].F[0]==3)
		++tp2,b2[tp2]=(Node2) {tp2,i,a[i].F[1]};sort(b2+1,b2+tp2+1);
	for(int i=1;i<=tp2;++i) ans[b2[i].id]=qry(1,1,n,b2[i].x,b2[i].w);
	for(int i=1;i<=tp2;++i) if(ans[i]>-INF)
		printf("%lld\n",ans[i]);else puts("EMPTY SET");return 0;
}