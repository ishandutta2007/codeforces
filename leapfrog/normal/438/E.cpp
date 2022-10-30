//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
namespace poly
{
	namespace num_sqrt
	{
		const int P=998244353;int I2;struct comp{int x,y;comp(int a=0,int b=0):x(a%P),y(b%P) {}};
		inline bool operator==(comp a,comp b) {return a.x==b.x&&a.y==b.y;}
		inline comp operator*(comp a,comp b) {return comp((1ll*a.x*b.x%P+1ll*a.y*b.y%P*I2%P)%P,(1ll*a.x*b.y%P+1ll*a.y*b.x%P)%P);}
		inline comp operator^(comp x,int q) {comp r=comp(1,0);for(;q;q>>=1,x=x*x) if(q&1) r=r*x;return r;}
		inline char chk(int x) {return (comp(x,0)^((P-1)>>1)).x==1;}
		inline int solve(int n)
		{
			int a=rand()%P;while(!a||chk((1ll*a*a%P+P-n)%P)) a=rand()%P;
			return I2=(1ll*a*a%P+P-n)%P,(comp(a,1)^((P+1)>>1)).x;
		}
	}
	const int P=998244353,N=4000005,G=3,L=119,Z=23;
	inline int ksm(int x,ll q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
	const int Ip=num_sqrt::solve(P-1),I2=(P+1)>>1;
	int rev[N],g[Z+5][2],A[N],B[N],C[N],D[N];
	inline void init(int T)
	{
		rev[0]=0;for(int i=1;i<T;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(T>>1):0);
		if(g[Z][0]) return;else g[Z][0]=ksm(G,L),g[Z][1]=ksm(ksm(G),L);
		for(int i=Z;i;i--) g[i-1][0]=1ll*g[i][0]*g[i][0]%P,g[i-1][1]=1ll*g[i][1]*g[i][1]%P;
	}
	#define fst(x) ((x)>=P?(x)-P:(x))
	inline void NTT(int T,int *a,int flg)
	{
		for(int i=0;i<T;i++) if(rev[i]>i) swap(a[i],a[rev[i]]);
		for(int d=1,rp=1;d<T;d<<=1,rp++)
			for(int i=0,wn=g[rp][flg];i<T;i+=(d<<1))
				for(int k=0,w=1;k<d;k++,w=1ll*w*wn%P)
					{int x=a[i+k],y=1ll*a[i+k+d]*w%P;a[i+k]=fst(x+y),a[i+k+d]=fst(x-y+P);}
		if(flg) {int iv=ksm(T);for(int i=0;i<T;i++) a[i]=1ll*a[i]*iv%P;}
	}
	inline void getconv(int n,int *a,int *b,int *r)//use A and B
	{
		int T=1;while(T<n) T<<=1;init(T);
		for(int i=0;i<T;i++) A[i]=(i<n)?a[i]:0,B[i]=(i<n)?b[i]:0;
		NTT(T,A,0),NTT(T,B,0);for(int i=0;i<T;i++) A[i]=1ll*A[i]*B[i]%P;
		NTT(T,A,1);for(int i=0;i<n;i++) r[i]=A[i];
	}
	inline void getsqr(int n,int *a,int *r)//use A
	{
		int T=1;while(T<n+n-1) T<<=1;init(T);
		for(int i=0;i<T;i++) A[i]=(i<n)?a[i]:0;
		NTT(T,A,0);for(int i=0;i<T;i++) A[i]=1ll*A[i]*A[i]%P;
		NTT(T,A,1);for(int i=0;i<n;i++) r[i]=A[i];
	}
	inline void getinv(int n,int *a,int *r)//use A
	{
		if(n==1) return(void)(r[0]=ksm(a[0]));else getinv((n+1)>>1,a,r);
		int T=1;while(T<n+n-1) T<<=1;init(T);
		for(int i=0;i<T;i++) A[i]=i<n?a[i]:0,r[i]=i<((n+1)>>1)?r[i]:0;
		NTT(T,A,0),NTT(T,r,0);for(int i=0;i<T;i++) r[i]=1ll*(2-1ll*r[i]*A[i]%P+P)%P*r[i]%P;
		NTT(T,r,1);for(int i=n;i<T;i++) r[i]=0;
	}
	inline void getln(int n,int *a,int *r)//use A
	{
		getinv(n,a,r);int T=1;while(T<n+n-1) T<<=1;init(T);
		for(int i=0;i<T;i++) A[i]=i<n-1?1ll*a[i+1]*(i+1)%P:0;
		NTT(T,A,0),NTT(T,r,0);for(int i=0;i<T;i++) r[i]=1ll*r[i]*A[i]%P;
		NTT(T,r,1);for(int i=T-1;~i;i--) if(i>=n) r[i]=0;else if(i) r[i]=1ll*r[i-1]*ksm(i)%P;else r[i]=0;
	}
	inline void getexp(int n,int *a,int *r)//use A and B
	{
		if(n==1) return(void)(r[0]=1);else getexp((n+1)>>1,a,r),getln(n,r,B);
		int T=1;while(T<n+n-1) T<<=1;init(T);
		for(int i=0;i<T;i++) B[i]=i<n?(a[i]-B[i]+P)%P:0,r[i]=i<((n+1)>>1)?r[i]:0;
		++B[0],NTT(T,B,0),NTT(T,r,0);for(int i=0;i<T;i++) r[i]=1ll*r[i]*B[i]%P;
		NTT(T,r,1);for(int i=n;i<T;i++) r[i]=0;
	}
	inline void getpow(int n,int k1,int k2,int *a,int *r)//use A and B and C
	{
		int div=ksm(a[0]);for(int i=0;i<n;i++) B[i]=1ll*a[i]*div%P;
		getln(n,B,C);for(int i=0;i<n;i++) C[i]=1ll*C[i]*k1%P;getexp(n,C,r);
		div=ksm(ksm(div),k2);for(int i=0;i<n;i++) r[i]=1ll*r[i]*div%P;
	}
	inline void getsqrt(int n,int *a,int *r)//use A and B
	{
		if(n==1) return(void)(r[0]=a[0]);else getsqrt((n+1)>>1,a,r),getinv(n,r,B);
		int T=1;while(T<n+n-1) T<<=1;init(T);
		const int iv2=ksm(2);for(int i=0;i<T;i++) A[i]=i<n?a[i]:0;
		NTT(T,A,0),NTT(T,B,0),NTT(T,r,0);for(int i=0;i<T;i++) r[i]=(r[i]+1ll*A[i]*B[i]%P)%P*iv2%P;
		NTT(T,r,1);for(int i=n;i<T;i++) r[i]=0;
	}
	inline void getsin(int n,int *a,int *r)//use A and B and C and D
	{
		for(int i=0;i<n;i++) D[i]=1ll*a[i]*Ip%P;
		getexp(n,D,C),getinv(n,C,B);const int fm=ksm((Ip<<1)%P);
		for(int i=0;i<n;i++) r[i]=1ll*(C[i]-B[i]+P)%P*fm%P;
	}
	inline void getcos(int n,int *a,int *r)//use A and B and C and D
	{
		for(int i=0;i<n;i++) D[i]=1ll*a[i]*Ip%P;
		getexp(n,D,C),getinv(n,C,B);
		for(int i=0;i<n;i++) r[i]=1ll*(C[i]+B[i])%P*I2%P;
	}
	inline void getasin(int n,int *a,int *r)//use A and B and C
	{
		getsqr(n,a,r);for(int i=0;i<n;i++) r[i]=(P-r[i]),r[i]>=P?r[i]-=P:0;
		r[0]++,getsqrt(n,r,C);for(int i=0;i<n;i++) C[i]=(C[i]+1ll*Ip*a[i])%P;
		getln(n,C,r);for(int i=0;i<n;i++) r[i]=P-1ll*r[i]*Ip%P,r[i]==P?r[i]=0:0;
	}
	inline void getatan(int n,int *a,int *r)//use A and B and C
	{
		for(int i=0;i<n;i++) C[i]=1ll*a[i]*Ip%P,r[i]=1ll*a[i]*Ip%P;
		C[0]--,r[0]++,getsqrt(n,C,D),getln(n,D,C),getsqrt(n,r,D),getln(n,D,r);
		for(int i=0;i<n;i++) r[i]=1ll*Ip*(C[i]-r[i]+P)%P;
	}
	inline void getdiv(int n,int *a,int m,int *g,int *r)//use A and B and C
	{
		for(int i=0;i<n;i++) i<m?B[i]=g[m-i-1]:B[i]=0,C[n-i-1]=a[i];
		getinv(n-m+1,B,r);int T=1;while(T<((n-m+1)<<1)) T<<=1;init(T);
		for(int i=0;i<T;i++) C[i]=i<n-m+1?C[i]:0,r[i]=i>((n-m)<<1)?0:r[i];
		NTT(T,r,0),NTT(T,C,0);for(int i=0;i<T;i++) r[i]=1ll*r[i]*C[i]%P;
		NTT(T,r,1);for(int i=n-m+1;i<T;i++) r[i]=0;reverse(r,r+n-m+1);
	}
	inline void getmod(int n,int *a,int m,int *g,int *r)//use A and B and C and D
	{
		getdiv(n,a,m,g,D);int T=1;while(T<n+n-1) T<<=1;init(T);
		for(int i=0;i<T;i++) D[i]=i<n-m+1?D[i]:0,B[i]=i<m?g[i]:0;
		NTT(T,D,0),NTT(T,B,0);for(int i=0;i<T;i++) D[i]=1ll*D[i]*B[i]%P;
		NTT(T,D,1);for(int i=0;i<m;i++) r[i]=(a[i]-D[i]+P)%P;
	}
}
const int P=998244353;int n,m,g[4000005],f[4000005];
int main()
{
	read(m),read(n);
	for(int i=1,x;i<=m;i++) read(x),g[x]+=4;
	for(int i=0;i<=n;i++) g[i]=(P-g[i])%P;
	(g[0]+=1)%=P;poly::getsqrt(n+1,g,f),(f[0]+=1)%=P,memset(g,0,sizeof(g)),poly::getinv(n+1,f,g);
	for(int i=1;i<=n;i++) printf("%lld\n",g[i]*2ll%P);
	return 0;
}