//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
#define int long long
int fc[1000005],fi[1000005];const int P=1e9+7;
int n,m,rs,l,r,a[1000005];char v[1000005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	fc[0]=1;for(int i=1;i<=1000000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[1000000]=ksm(fc[1000000]);for(int i=1000000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline int Calc1(int x)
{
	if(x<=0) return 0;
	int a=max(x+l-1,0ll),b=max(n-r+x,0ll);if(a+b>n) return 0;
	if(n&1) return (C(n-a-b,n/2-a)+C(n-a-b,n/2-a+1))%P;
	else return C(n-a-b,n/2-a);
}
inline int Calc2()
{
	if(n&1) return (C(n,n/2)+C(n,n/2+1))%P;
	else return C(n,n/2);
}
inline void solve()
{
	int rs=0;read(n),read(l),read(r);
	for(int i=min(-l,r-n);i<=min(n-l,r);i++) rs=(rs+Calc1(i))%P;
	printf("%lld\n",(rs+max(min(-l,r-n)-1,0ll)*Calc2())%P);
}
signed main() {init();int Ca;for(read(Ca);Ca--;) solve();return 0;}