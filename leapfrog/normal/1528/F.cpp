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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=100000<<2,P=998244353;int n,K,rev[N],g[26][2],A[N],B[N],S[N],iv[N],fi[N],fc[N];
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
inline void init(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
	int T=1;while(T<=n+n) T<<=1;pinit(T);
	for(int i=0;i<=n;i++) A[i]=i&1?(P-fi[i]):fi[i],B[i]=1ll*ksm(i,n)*fi[i]%P;
	NTT(T,A,0),NTT(T,B,0);for(int i=0;i<T;i++) A[i]=1ll*A[i]*B[i]%P;
	NTT(T,A,1);for(int i=0;i<=n;i++) S[i]=A[i];
}
int main()
{
	read(n,K),init(K);int rs=0,pw=ksm(n+1,n),iv=ksm(n+1),zh=1;
	for(int j=0;j<=K;j++) rs=(rs+1ll*S[j]*zh%P*pw)%P,zh=1ll*zh*(n-j)%P,pw=1ll*pw*iv%P;
	return printf("%d\n",rs),0;
}