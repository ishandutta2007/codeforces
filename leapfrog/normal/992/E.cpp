//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,Q,a[200005];struct node{int mx;ll sm;}T[800005];
inline void pushup(int x) {T[x].mx=max(T[x<<1].mx,T[x<<1|1].mx),T[x].sm=T[x<<1].sm+T[x<<1|1].sm;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x].mx=T[x].sm=a[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void chang(int x,int l,int r,int dw,int dc)
{
	if(l==r) return a[l]=T[x].mx=T[x].sm=dc,void();
	if(dw<=((l+r)>>1)) chang(x<<1,l,(l+r)>>1,dw,dc),pushup(x);
	else chang(x<<1|1,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline ll qrysm(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x].sm;
	return qrysm(x<<1,l,(l+r)>>1,dl,dr)+qrysm(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline int query(int x,int l,int r,int dl,ll &sm)
{
	//printf("[%d,%d]:%lld %d\n",l,r,sm,T[x].mx);
	if(dl>r) return 0;else if(sm>T[x].mx) return sm+=qrysm(x,l,r,dl,r),0;else if(l==r) return l;
	int g;if((g=query(x<<1,l,(l+r)>>1,dl,sm))) return g;
	if((g=query(x<<1|1,((l+r)>>1)+1,r,dl,sm))) return g;
	return 0;
}
inline int solve(int nw,ll nws)
{
	int wh;ll sm;if(nws>1000000000) return -1;else wh=query(1,1,n,nw,nws);
	if(!wh) return -1;else if(a[wh]==(sm=qrysm(1,1,n,1,wh-1))) return wh;else return solve(wh+1,sm+a[wh]);
}
int main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]);
	//ll qwq=8;return build(1,1,n),printf("%d\n",query(1,1,n,3,qwq)),0;
	for(build(1,1,n);Q--;) {int x,w;read(x),read(w),chang(1,1,n,x,w),printf("%d\n",solve(1,0));}
	return 0;
}