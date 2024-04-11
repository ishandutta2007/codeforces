#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
namespace poly
{
#define double long double
	struct comp
	{
		double x,y;
		inline comp operator+(comp b) {return(comp){x+b.x,y+b.y};}
		inline comp operator-(comp b) {return(comp){x-b.x,y-b.y};}
		inline comp operator*(comp b) {return(comp){x*b.x-y*b.y,x*b.y+y*b.x};}
		inline comp operator/(double b) {return(comp){x/b,y/b};}
		inline comp operator*(double b) {return(comp){x*b,y*b};}
	}A[2][400005],B[2][400005],R[3][400005];const int P=1e9+7;
	int rev[400005];comp zr=(comp){0,0};const double Pi=acos(-1);
	inline void init(int n) {for(int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);}
	inline void FFT(int n,comp *a,int fg)
	{
		for(int i=0;i<n;i++) if(rev[i]<i) swap(a[i],a[rev[i]]);
		for(int d=1;d<n;d<<=1)
		{
			comp wn=(comp){cos(Pi/d),fg*sin(Pi/d)},w;
			for(int i=0,k;i<n;i+=(d<<1))
				for(k=0,w=(comp){1,0};k<d;k++,w=wn*w)
					{comp x=a[i+k],y=a[i+k+d]*w;a[i+k]=x+y,a[i+k+d]=x-y;}
		}
		if(!~fg) for(int i=0;i<n;i++) a[i]=a[i]/n;
	}
	inline void FST(int T,int n,int *a,int *b,int *r)
	{
		for(int i=0;i<T;i++) A[0][i]=A[1][i]=B[0][i]=B[1][i]=R[0][i]=R[1][i]=R[2][i]=zr;
		for(int i=n;i<T;i++) a[i]=b[i]=0;
		for(int i=0;i<T;i++) A[0][i].x=a[i]>>15,A[1][i].x=a[i]&0x7fff,B[0][i].x=b[i]>>15,B[1][i].x=b[i]&0x7fff;
		FFT(T,A[0],1),FFT(T,A[1],1),FFT(T,B[0],1),FFT(T,B[1],1);
		for(int i=0;i<T;i++) R[0][i]=A[0][i]*B[0][i],R[1][i]=A[0][i]*B[1][i]+A[1][i]*B[0][i],R[2][i]=A[1][i]*B[1][i];
		FFT(T,R[0],-1),FFT(T,R[1],-1),FFT(T,R[2],-1);
		for(int i=0;i<n;i++)
		{
			ll g1=((((ll)(R[0][i].x+0.5)%P)<<30)%P+P)%P;
			ll g2=((((ll)(R[1][i].x+0.5)%P)<<15)%P+P)%P;
			ll g3=((ll)(R[2][i].x+0.5)%P+P)%P;
			r[i]=(((g1+g2)%P+g3)%P+P)%P;
		}
	}
#undef double
}using poly::P;
ll n;int k,fc[120005],fi[120005],f[120005],g[120005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void work(int k,int n,int T)
{
	if(k==1) {f[0]=0;for(int i=1;i<n;i++) f[i]=fi[i];return;}else work(k>>1,n,T);
	g[0]=0;for(int i=1;i<n;i++) g[i]=1ll*f[i]*ksm(2,1ll*(k>>1)*i%(P-1))%P;
	poly::FST(T,n,f,g,f);if(!(k&1)) return;
	g[0]=0;for(int i=1;i<n;i++) f[i]=1ll*f[i]*ksm(2,i)%P,g[i]=fi[i];
	poly::FST(T,n,f,g,f);
}
signed main()
{
	read(n),read(k);if(n>k) return puts("0"),0;else fc[0]=fi[0]=1;
	int T=1;while(T<=((k+1)<<1)) T<<=1;poly::init(T);
	for(int i=1;i<T;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[T-1]=ksm(fc[T-1]);for(int i=T-1;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	work(n,k+1,T);int res=0;for(int i=1;i<=k;i++) res=(res+1ll*f[i]*fc[k]%P*fi[k-i]%P)%P;
	return printf("%d\n",res),0;
}