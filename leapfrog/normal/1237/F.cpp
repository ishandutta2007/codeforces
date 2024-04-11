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
const int N=3605,P=998244353;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
int n,m,K,f[N][N],g[N][N];char vx[N],vy[N];
int main()
{
	read(n,m,K);for(int i=1,x,y,a,b;i<=K;i++) read(a,x,b,y),vx[a]=vx[b]=vy[x]=vy[y]=1;
	vx[0]=1,f[0][0]=1;for(int i=1;i<=n;i++) for(int j=0;j<=n/2;j++)
		if(vx[i]||vx[i-1]) f[i][j]=f[i-1][j];else f[i][j]=(f[i-1][j]+(j?f[i-2][j-1]:0))%P;
	vy[0]=1,g[0][0]=1;for(int i=1;i<=m;i++) for(int j=0;j<=m/2;j++)
		if(vy[i]||vy[i-1]) g[i][j]=g[i-1][j];else g[i][j]=(g[i-1][j]+(j?g[i-2][j-1]:0))%P;
	dbinit();int rs=0,c1=n,c2=m;
	for(int i=1;i<=n;i++) c1-=vx[i];
	for(int i=1;i<=m;i++) c2-=vy[i];
	for(int i=0;i*2<=c1;i++) for(int j=0;j*2<=c2-i&&j<=c1-i*2;j++)
		rs=(rs+1ll*f[n][i]*g[m][j]%P*fc[c2-j*2]%P*fi[c2-j*2-i]%P*fc[c1-i*2]%P*fi[c1-i*2-j])%P;
	return printf("%d\n",rs),0;
}