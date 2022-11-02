//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;int T,n,K,fc[1005],fi[1005],tn[1005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	fc[0]=fi[0]=1;for(int i=1;i<=1000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[1000]=ksm(fc[1000]);for(int i=999;i;i--) fi[i]=1ll*fi[i+1]*(i+1)%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline void solve()
{
	read(n),read(K),memset(tn+1,0,(n+1)<<2);for(int i=1,x;i<=n;i++) read(x),tn[x]++;
	for(int i=n;i;tn[i]+=tn[i+1],i--) if(tn[i]+tn[i+1]>=K) return printf("%d\n",C(tn[i],K-tn[i+1])),void();
}
int main() {for(init(),read(T);T--;) solve();return 0;}