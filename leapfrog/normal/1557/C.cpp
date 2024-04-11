//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,K,fc[200005],fi[200005];const int P=1e9+7;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	fc[0]=1;for(int i=1;i<=200000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[200000]=ksm(fc[200000]);for(int i=200000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline void solve()
{
	read(n),read(K);int rs1=0,rs2=0,rs=0,nw=1;
	for(int i=0;i<=n;i++)
		if((i&1)<(i==n)) rs1=(rs1+C(n,i))%P;
		else if((i&1)==(i==n)) rs2=(rs2+C(n,i))%P;
	for(int i=1;i<=K;i++) rs=(rs+1ll*nw*rs1%P*ksm(ksm(2,n),K-i))%P,nw=1ll*nw*rs2%P;
	printf("%d\n",(nw+rs)%P);
}
int main() {int Ca;for(init(),read(Ca);Ca--;) solve();return 0;}