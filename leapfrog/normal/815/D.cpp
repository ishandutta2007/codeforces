//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=500005;int n,p,q,r,a[N],b[N],c[N],vl[N];
struct segm{ll sm;int mx,fg,ln;}T[N<<2];vector<int>vc[N];
inline void pushup(int x) {T[x].sm=T[x<<1].sm+T[x<<1|1].sm,T[x].mx=max(T[x<<1].mx,T[x<<1|1].mx);}
inline void allc(int x,int c) {T[x].sm=1ll*T[x].ln*c,T[x].mx=T[x].fg=c;}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void build(int x,int l,int r)
{
	T[x].fg=0,T[x].ln=r-l+1;if(l==r) return T[x].sm=T[x].mx=vl[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline void chang(int x,int l,int r,int dc)
{
	if(l==r) return T[x].sm=T[x].mx=max(T[x].mx,dc),void();else pushdw(x);
	if(T[x<<1|1].mx>dc) chang(x<<1|1,((l+r)>>1)+1,r,dc),pushup(x);
	else allc(x<<1|1,dc),chang(x<<1,l,(l+r)>>1,dc),pushup(x);
}
inline void debug(int x,int l,int r)
{
	if(l==r) return printf("%d%c",T[x].mx,l==q?'\n':' '),void();
	pushdw(x),debug(x<<1,l,(l+r)>>1),debug(x<<1|1,((l+r)>>1)+1,r);
}
int main()
{
	read(n),read(p),read(q),read(r),vl[q+1]=1;
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]),read(c[i]),vc[a[i]].push_back(i);
	for(int i=1;i<=n;i++) vl[b[i]]=max(c[i]+1,vl[b[i]]);//a=p+1
	ll rs=0;for(int i=q;i>=1;i--) vl[i]=max(vl[i],vl[i+1]);
	//for(int i=1;i<=q;i++) printf("%d%c",vl[i],i==q?'\n':' ');
	build(1,1,q);for(int i=p;i>=1;i--,rs+=1ll*(r+1)*q-T[1].sm)
		for(auto j:vc[i]) chang(1,1,q,c[j]+1),modif(1,1,q,1,b[j],r+1);
	return printf("%lld\n",rs),0;
}