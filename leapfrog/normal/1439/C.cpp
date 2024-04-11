//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct zkak{int len,lz,mx,mn;long long sm;}t[1600005];int n,q,a[400005];
inline void pushup(int x) {t[x].mx=max(t[x<<1].mx,t[x<<1|1].mx),t[x].mn=min(t[x<<1].mn,t[x<<1|1].mn),t[x].sm=t[x<<1].sm+t[x<<1|1].sm;}
inline void allc(int x,int c) {t[x].mx=t[x].lz=t[x].mn=c,t[x].sm=1ll*t[x].len*c;}
inline void down(int x) {if(~t[x].lz) allc(x<<1,t[x].lz),allc(x<<1|1,t[x].lz),t[x].lz=-1;}
inline void build(int x,int l,int r)
{
	t[x].len=r-l+1,t[x].lz=-1;if(l==r) return(void)(t[x].mx=t[x].sm=t[x].mn=a[l]);
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void motif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return allc(x,dc);else down(x);
	motif(x<<1,l,(l+r)>>1,dl,dr,dc),motif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline void Motif(int x,int l,int r,int dr,int dc)
{
	if(l>dr||t[x].mn>dc) return;else if(r<=dr&&t[x].mx<=dc) return allc(x,dc);else down(x);
	if(t[x<<1|1].mx>dc) return Motif(x<<1|1,((l+r)>>1)+1,r,dr,dc),pushup(x);
	motif(x<<1|1,((l+r)>>1)+1,r,((l+r)>>1)+1,dr,dc),Motif(x<<1,l,(l+r)>>1,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int dl,int& dc)
{
	if(dl>r||dc<t[x].mn) return 0;else if(dl<=l&&t[x].sm<=dc) return dc-=t[x].sm,r-l+1;else down(x);
	return query(x<<1,l,(l+r)>>1,dl,dc)+query(x<<1|1,((l+r)>>1)+1,r,dl,dc);
}
signed main()
{
	read(n),read(q);for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);for(int fg,x,y;q--;)
	{
		read(fg),read(x),read(y);
		if(fg==1) Motif(1,1,n,x,y);else printf("%d\n",query(1,1,n,x,y));
	}
	return 0;
}