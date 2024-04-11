//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int P=998244353,N=32768;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
namespace poly//{{{
{
	const int P=998244353,G=3,L=119,Z=23;int rev[N],g[Z+5][2];
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
}//}}}
int n,K,A[N<<1],B[N<<1];
int main()
{
	read(n,K),dbinit();int vl=1,T=1;while(T<=K+K) T<<=1;poly::init(T);
	for(int k=0;k<=K;k++)
	{
		A[k]=1ll*fi[k]*vl%P,A[k]=(k&1?P-A[k]:A[k]);
		B[k]=1ll*ksm(2,k)*fi[k]%P*fi[k]%P;
		vl=1ll*vl*ksm(n-k)%P;
	}
	poly::NTT(T,A,0),poly::NTT(T,B,0);for(int i=0;i<T;i++) A[i]=1ll*A[i]*B[i]%P;
	poly::NTT(T,A,1),vl=1;for(int i=0;i<T;i++) A[i]=1ll*vl*A[i]%P*fc[i]%P,vl=1ll*vl*(n-i)%P;
	for(int i=1;i<=K;i++) printf("%d%c",A[i],i==K?'\n':' ');
	return 0;
}