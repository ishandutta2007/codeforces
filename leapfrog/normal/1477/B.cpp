#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct segm{int sm,ln,lz;}t[800005];int T,n,Q,a[200005],b[200005],l[200005],r[200005];
inline void allfg(int x,int c) {t[x].lz=c,t[x].sm=t[x].ln*c;}
inline void pushdw(int x) {if(~t[x].lz) allfg(x<<1,t[x].lz),allfg(x<<1|1,t[x].lz),t[x].lz=-1;}
inline void build(int x,int l,int r)
{
	t[x].lz=-1,t[x].ln=r-l+1;if(l==r) return t[x].sm=b[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x].sm=t[x<<1].sm+t[x<<1|1].sm;
}
inline void updat(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return allfg(x,dc);else pushdw(x);
	updat(x<<1,l,(l+r)>>1,dl,dr,dc),updat(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),t[x].sm=t[x<<1].sm+t[x<<1|1].sm;
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r||dl>dr) return 0;else if(dl<=l&&r<=dr) return t[x].sm;else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline char check(int x,int l,int r)
{
	if(l==r) return t[x].sm==a[l];else pushdw(x);
	return check(x<<1,l,(l+r)>>1)&&check(x<<1|1,((l+r)>>1)+1,r);
}
inline void solve()
{
	read(n),read(Q);for(int i=1;i<=n;i++) scanf("%1d",a+i);
	for(int i=1;i<=n;i++) scanf("%1d",b+i);
	build(1,1,n);for(int i=1;i<=Q;i++) read(l[i]),read(r[i]);
	for(int i=Q;i;i--)
	{
		int len=r[i]-l[i]+1,sm=query(1,1,n,l[i],r[i]);
		if((sm<<1)==len) return puts("NO"),void();
		else updat(1,1,n,l[i],r[i],(sm<<1)>len);
	}
	puts(check(1,1,n)?"YES":"NO");
}
int main() {for(read(T);T--;) solve();return 0;}