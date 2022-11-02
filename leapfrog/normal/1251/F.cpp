//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=998244353;int a[300005],b[300005],N=0;
int n,k,Q,rev[4800005],g[23][2],A[4800005],B[4800005],inv[600005],fac[600005],q[300005],r[300005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void Rinit()
{
	if(g[23][0]) return;else g[23][0]=ksm(3,119),g[23][1]=ksm(332748118,119);
	for(int i=22;i;i--) g[i][0]=1ll*g[i+1][0]*g[i+1][0]%P,g[i][1]=1ll*g[i+1][1]*g[i+1][1]%P;
}
inline void init(int T) {Rinit(),rev[0]=0;for(int i=1;i<T;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(T>>1):0);}
inline void NTT(int n,int *a,int fg)
{
	for(int i=0;i<n;i++) if(rev[i]<i) swap(a[i],a[rev[i]]);
	for(int d=1,rp=1;d<n;d<<=1,rp++)
		for(int i=0,wn=g[rp][fg];i<n;i+=(d<<1))
			for(int k=0,w=1;k<d;k++,w=1ll*w*wn%P)
				{int x=a[i+k],y=1ll*a[i+k+d]*w%P;a[i+k]=(x+y)%P,a[i+k+d]=(P+x-y)%P;}
	if(fg) {int iv=ksm(n);for(int i=0;i<n;i++) a[i]=1ll*a[i]*iv%P;}
}
inline int C(int n,int m) {if(n<m||n<0||m<0) return 0;else return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;}
inline void solve(int maxn)
{
	int T=1;while(T<n+n) T<<=1;
	int two=0,one=0;memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
	for(int i=1;i<maxn;i++) if(a[i]==1) one++;else if(a[i]>1) ++++two;
	for(int i=0;i<T;i++) A[i]=1ll*ksm(2,i)*C(one,i)%P;
	for(int i=0;i<T;i++) B[i]=C(two,i);
	init(T),NTT(T,A,0),NTT(T,B,0);for(int i=0;i<T;i++) A[i]=1ll*A[i]*B[i]%P;
	NTT(T,A,1);for(int i=1;i<=Q;i++) if(q[i]>maxn) (r[i]+=A[q[i]-maxn-1])%=P;
}
int main()
{
	read(n),read(k),fac[0]=inv[0]=1;for(int i=1;i<=600000;i++) fac[i]=1ll*fac[i-1]*i%P;
	inv[600000]=ksm(fac[600000]);for(int i=599999;i;i--) inv[i]=1ll*inv[i+1]*(i+1)%P;
	for(int i=1,x;i<=n;i++) read(x),a[x]++;
	for(int i=1;i<=k;i++) read(b[i]);
	read(Q);for(int i=1;i<=Q;i++) read(q[i]),q[i]>>=1;
	for(int i=1;i<=k;i++) solve(b[i]);
	for(int i=1;i<=Q;i++) printf("%d\n",r[i]);
	return 0;
}