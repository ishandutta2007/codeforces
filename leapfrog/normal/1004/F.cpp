//
#include<bits/stdc++.h>
#define fi first
#define sc second
#define pb push_back
#define mk make_pair
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,Q,X,a[100005];
struct node{vector<pair<int,int> >la,ra;ll sm;}T[400005],zro;
inline node init(int x) {node r;r.la.pb(mk(x,1)),r.ra.pb(mk(x,1)),r.sm=x>=X;return r;}
inline node operator+(const node &a,const node &b)
{
	int nw;if(a.la.empty()) return b;else if(b.la.empty()) return a;
	node r;r.sm=a.sm+b.sm;for(auto i:a.ra) for(auto j:b.la) if((i.fi|j.fi)>=X) r.sm+=1ll*i.sc*j.sc;
	r.la=a.la,nw=a.la.back().fi;for(auto i:b.la) if((i.fi|nw)==nw) r.la.back().sc+=i.sc;else nw|=i.fi,r.la.pb(mk(nw,i.sc));
	r.ra=b.ra,nw=b.ra.back().fi;for(auto i:a.ra) if((i.fi|nw)==nw) r.ra.back().sc+=i.sc;else nw|=i.fi,r.ra.pb(mk(nw,i.sc));
	return r;
}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=init(a[l]),void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void modif(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x]=init(a[l]=dc),void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
}
inline node query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return zro;else if(dl<=l&&r<=dr) return T[x];
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n),read(Q),read(X);for(int i=1;i<=n;i++) read(a[i]);
	for(build(1,1,n);Q--;)
	{
		int op;read(op);int x,y;read(x),read(y);
		if(op&1) modif(1,1,n,x,y);else printf("%lld\n",query(1,1,n,x,y).sm);
	}
	return 0;
}