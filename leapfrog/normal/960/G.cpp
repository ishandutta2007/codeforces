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
const int N=262145<<2,P=998244353;int n,a[N],r[N],rev[N],g[26][2],A[N],B[N],C[N],iv[N>>1],fi[N>>1],fc[N>>1];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void pinit(int T)
{
	rev[0]=0;for(int i=1;i<T;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(T>>1):0);
	if(g[23][0]) return;else g[23][0]=ksm(3,119),g[23][1]=ksm(ksm(3),119);
	for(int i=23;i;i--) g[i-1][0]=1ll*g[i][0]*g[i][0]%P,g[i-1][1]=1ll*g[i][1]*g[i][1]%P;
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
inline void getpn(int n,int *a,int *r)//0->n-1
{
	int T=1,pw=1;while(T<n+n-1) T<<=1;pinit(T);
	for(int i=0;i<n;i++,pw=1ll*pw*(n-1)%P) A[n-i-1]=1ll*a[i]*fc[i]%P,B[i]=1ll*pw*fi[i]%P;
	for(int i=n;i<T;i++) A[i]=B[i]=0;
	NTT(T,A,0),NTT(T,B,0);for(int i=0;i<T;i++) A[i]=1ll*A[i]*B[i]%P;
	NTT(T,A,1);for(int i=0;i<n;i++) r[i]=1ll*A[n-i-1]*fi[i]%P;
}
inline void solve(int n,int *r)
{
	int g;if(n==0) return r[0]=1,void();else solve(g=n>>1,r);
	int T=1;while(T<=n) T<<=1;getpn(g+1,r,C),pinit(T);
	for(int i=0;i<=n;i++) B[i]=r[i];
	for(int i=n+1;i<T;i++) C[i]=B[i]=0;
	NTT(T,C,0),NTT(T,B,0);for(int i=0;i<T;i++) C[i]=1ll*C[i]*B[i]%P;
	NTT(T,C,1);if(!(n&1)) for(int i=0;i<=n;i++) r[i]=C[i];
	else for(int i=0;i<=n;i++) r[i]=((i?C[i-1]:0)+(n-1ll)*C[i])%P;
}
inline void init(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int c(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	int x,y;read(n),read(x),read(y),init(n+n);if(x+y-2<0) return puts("0"),0;
	return solve(n-1,r),printf("%lld\n",1ll*r[x+y-2]*c(x+y-2,y-1)%P),0;
}