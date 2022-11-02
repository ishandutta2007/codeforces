//
#include<bits/stdc++.h>
using namespace std;const int P=1000000007;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct mat
{
	int a[3][3];
	inline void operator!() {memset(a,0,sizeof(a));}
	inline void operator~() {!(*this),a[1][1]=a[2][2]=1;}
	inline mat operator*(const mat &b) const
	{
		mat r;!r;
		for(int i=1;i<=2;i++) for(int k=1;k<=2;k++) for(int j=1;j<=2;j++) (r.a[i][j]+=1ll*a[i][k]*b.a[k][j]%P)%=P;
		return r;
	}
	inline mat operator+(const mat &b) const
	{
		mat r;!r;
		for(int i=1;i<=2;i++) for(int j=1;j<=2;j++) r.a[i][j]=(a[i][j]+b.a[i][j])%P;
		return r;
	}
	inline mat operator^(long long q) {mat x=*this,r;~r;for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
}dw,vl,epx,zro;int n,Q,a[100005];
struct segment{mat vl,lz;}t[400005];
inline void allc(int x,mat v) {t[x].vl=t[x].vl*v,t[x].lz=t[x].lz*v;}
inline void down(int x) {allc(x<<1,t[x].lz),allc(x<<1|1,t[x].lz),~t[x].lz;}
inline void build(int x,int l,int r)
{
	if(l==r) return(void)(t[x].vl=dw^a[l],~t[x].lz);else ~t[x].lz;
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x].vl=t[x<<1].vl+t[x<<1|1].vl;
}
inline void chang(int x,int l,int r,int dl,int dr,const mat &dc)
{
	if(dl>r||l>dr) return;else if(dl<=l&&r<=dr) return allc(x,dc);else down(x);
	chang(x<<1,l,(l+r)>>1,dl,dr,dc),chang(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),t[x].vl=t[x<<1].vl+t[x<<1|1].vl;
}
inline mat query(int x,int l,int r,int dl,int dr)
{
	if(dl>r||l>dr) return zro;else if(dl<=l&&r<=dr) return t[x].vl;else down(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
signed main()
{
	dw.a[1][1]=dw.a[1][2]=dw.a[2][1]=1,dw.a[2][2]=0,~epx,!zro;
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);for(int fg,l,r,c;Q--;)
	{
		read(fg),read(l),read(r);
		if(fg==1) read(c),chang(1,1,n,l,r,dw^c);
		else printf("%d\n",query(1,1,n,l,r).a[2][1]);
	}
	return 0;
}