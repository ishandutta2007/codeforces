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
const int P=1e9,N=200005;int n,Q,f[N],sf[N];
struct segm{int ln,s1,s2,fg;}T[N<<2];int a[N];
inline int F(int x) {return x<0?0:f[x];}
inline int Cl(int x,int k) {return (1ll*T[x].s1*F(k-2)+1ll*T[x].s2*F(k-1))%P;}
inline void pushup(int x)
{
	T[x].s1=(T[x<<1].s1+Cl(x<<1|1,T[x<<1].ln))%P;
	T[x].s2=(T[x<<1].s2+Cl(x<<1|1,T[x<<1].ln+1))%P;
}
inline void allc(int x,int c)
{
	T[x].fg=(T[x].fg+c)%P;
	T[x].s1=(T[x].s1+1ll*sf[T[x].ln-1]*c)%P;
	T[x].s2=(T[x].s2+1ll*(sf[T[x].ln]-1)*c)%P;
}
inline void pushdw(int x) {if(T[x].fg) allc(x<<1,T[x].fg),allc(x<<1|1,T[x].fg),T[x].fg=0;}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1;if(l==r) return T[x].s1=T[x].s2=a[l],void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void chang(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x].s1=T[x].s2=dc,void();else pushdw(x);
	if(dw<=((l+r)>>1)) chang(x<<1,l,(l+r)>>1,dw,dc),pushup(x);
	else chang(x<<1|1,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return l^dl?Cl(x,l-dl):T[x].s1;else pushdw(x);
	return (query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr))%P;
}
int main()
{
	read(n),read(Q),sf[0]=f[0]=f[1]=1,sf[1]=2;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) sf[i]=(sf[i-1]+(f[i]=(f[i-1]+f[i-2])%P))%P;
	build(1,1,n);for(int op,l,r,v;Q--;)
	{
		read(op),read(l),read(r);
		if(op==2) printf("%d\n",query(1,1,n,l,r));
		else if(op==1) chang(1,1,n,l,r);
		else read(v),modif(1,1,n,l,r,v);
	}
	return 0;
}