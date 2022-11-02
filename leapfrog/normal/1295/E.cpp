//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
struct node{ll vl,fg;}T[800005];int n,p[200005],a[200005];
inline void pushup(int x) {T[x].vl=min(T[x<<1].vl,T[x<<1|1].vl);}
inline void allc(int x,ll c) {T[x].vl+=c,T[x].fg+=c;}
inline void pushdw(int x) {allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void modif(int x,int l,int r,int dl,int dr,ll dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline void debug(int x,int l,int r)
{
	if(l==r) return printf("%lld%c",T[x].vl,l==n?'\n':' '),void();
	pushdw(x),debug(x<<1,l,(l+r)>>1),debug(x<<1|1,((l+r)>>1)+1,r);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(p[i]);
	for(int i=1;i<=n;i++) read(a[i]),modif(1,0,n,p[i],n,a[i]);
	ll rs=0x3f3f3f3f3f3f3f3f;for(int i=1;i<n;i++)
		modif(1,0,n,p[i],n,-a[i]),modif(1,0,n,0,p[i]-1,a[i]),rs=min(rs,T[1].vl);
	return printf("%lld\n",rs),0;
}