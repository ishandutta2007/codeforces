//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct sum{ll sm;int mx;}t[400005];int n,m,a[100005];
inline void pushup(int x) {t[x].sm=t[x<<1].sm+t[x<<1|1].sm,t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx);}
inline void mdfmod(int x,int l,int r,int dl,int dr,int p)
{
	if(l>dr||dl>r||p>t[x].mx) return;else if(l==r) return t[x].mx%=p,t[x].sm%=p,void();
	mdfmod(x<<1,l,(l+r)>>1,dl,dr,p),mdfmod(x<<1|1,((l+r)>>1)+1,r,dl,dr,p),pushup(x);
}
inline void ddchg(int x,int l,int r,int dw,int dc)
{
	if(l==r) return t[x].mx=t[x].sm=dc,void();
	if(dw<=((l+r)>>1)) ddchg(x<<1,l,(l+r)>>1,dw,dc),pushup(x);
	else ddchg(x<<1|1,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline void build(int x,int l,int r)
{
	if(l==r) return t[x].mx=t[x].sm=a[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline ll qrysm(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r||dl>dr) return 0;else if(dl<=l&&r<=dr) return t[x].sm;
	return qrysm(x<<1,l,(l+r)>>1,dl,dr)+qrysm(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	for(build(1,1,n);m--;)
	{
		int fg,l,r,x;read(fg),read(l),read(r);
		if(fg==1) printf("%lld\n",qrysm(1,1,n,l,r));
		else if(fg==3) ddchg(1,1,n,l,r);
		else read(x),mdfmod(1,1,n,l,r,x);
	}
	return 0;
}