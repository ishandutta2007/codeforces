//
#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,Q,a[300005];
struct node{ll lv,rv;int len,lm,rm,mx;}T[1200005];
inline int sign(ll x) {return x<0?-1:(x>0?1:0);}
inline node operator+(node a,node b)
{
	node r;r.len=a.len+b.len,r.lv=a.lv,r.rv=b.rv;
	r.mx=max(max(a.mx,b.mx),max(a.lm,b.rm));
	if(!a.rv||!b.lv||sign(a.rv)<sign(b.lv)) return r.lm=a.lm,r.rm=b.rm,r;
	if(a.lm==a.len) r.lm=a.len+b.lm;else r.lm=a.lm;
	if(b.rm==b.len) r.rm=b.len+a.rm;else r.rm=b.rm;
	return r.mx=max(r.mx,a.rm+b.lm),r;
}
inline void build(int x,int l,int r)
{
	if(l==r) T[x].lv=T[x].rv=a[l],T[x].len=1,T[x].lm=T[x].rm=T[x].mx=!!a[l];
	else build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void modif(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x].lv=(T[x].rv+=dc),T[x].lm=T[x].rm=T[x].mx=!!T[x].lv,void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=T[x<<1]+T[x<<1|1];
}
signed main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	n--;for(int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
	if(!n) {for(read(Q);Q--;) puts("1");return 0;}
	for(build(1,1,n),read(Q);Q--;)
	{
		int l,r,w;read(l),read(r),read(w);
		(l>1?modif(1,1,n,l-1,w):void()),(r<=n?modif(1,1,n,r,-w):void());
		printf("%lld\n",T[1].mx+1);
	}
	return 0;
}