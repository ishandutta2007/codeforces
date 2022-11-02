#include<bits/stdc++.h>
using namespace std;const int P=1e9+9;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int sm,f1,f2,ln;}t[1200005];
int n,m,a[300005],f[300005];
inline void allc(int x,int a,int b)
{
	(t[x].f1+=a)%=P,(t[x].f2+=b)%=P;
	(t[x].sm+=(1ll*a*f[t[x].ln]%P+1ll*b*f[t[x].ln+1]%P-b+P)%P)%=P;
}
inline void down(int x)
{
	if(!t[x].f2) return;else allc(x<<1,t[x].f1,t[x].f2);
	int ff1=(1ll*t[x].f1*f[t[x<<1].ln-1]%P+1ll*t[x].f2*f[t[x<<1].ln]%P)%P;
	int ff2=(1ll*t[x].f1*f[t[x<<1].ln]%P+1ll*t[x].f2*f[t[x<<1].ln+1]%P)%P;
	allc(x<<1|1,ff1,ff2),t[x].f1=t[x].f2=0;
}
inline void build(int x,int l,int r)
{
	if(l==r) return(void)(t[x]=(node){a[l],0,0,1});else t[x].ln=r-l+1;
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x].sm=(t[x<<1].sm+t[x<<1|1].sm)%P;
}
inline void chang(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,f[l-dl+1],f[l-dl+2]);else down(x);
	chang(x<<1,l,(l+r)>>1,dl,dr),chang(x<<1|1,((l+r)>>1)+1,r,dl,dr),t[x].sm=(t[x<<1].sm+t[x<<1|1].sm)%P;
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return t[x].sm%P;else down(x);
	return (query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr))%P;
}
int main()
{
	f[1]=f[2]=1;for(int i=3;i<=300004;i++) f[i]=(f[i-1]+f[i-2])%P;
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);build(1,1,n);
	for(int f,l,r;m--;) {read(f),read(l),read(r);if(f==1) chang(1,1,n,l,r);else printf("%d\n",query(1,1,n,l,r));}
	return 0;
}