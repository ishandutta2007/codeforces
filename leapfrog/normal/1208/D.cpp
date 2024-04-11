//Coded by leap_frog on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,rs[N];ll a[N];
struct segm{ll mn,tg;}T[N<<2];
inline void allc(int x,ll w) {T[x].mn+=w,T[x].tg+=w;}
inline void pushup(int x) {T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x].mn=1ll*l*(l-1)/2,void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,ll dc)
{
	if(dl>r||l>dr) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int getps(int x,int l,int r,ll dc)
{
	if(l==r) return l;else pushdw(x);
	if(T[x<<1|1].mn<=dc) return getps(x<<1|1,((l+r)>>1)+1,r,dc);
	else return getps(x<<1,l,(l+r)>>1,dc);
}
int main()
{
	read(n),build(1,1,n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i>=1;i--) rs[i]=getps(1,1,n,a[i]),modif(1,1,n,rs[i]+1,n,-rs[i]),modif(1,1,n,rs[i],rs[i],1e9);
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}