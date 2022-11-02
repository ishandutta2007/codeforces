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
const int P=1e9+7;int n,K,sm=0,rs=0,fc[200005],fi[200005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n),read(K);for(int i=1,w;i<=n;i++) read(w),sm=(sm+w)%P;
	if(n==1||K==1) return printf("%lld\n",1ll*sm*n%P),0;
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[n]=ksm(fc[n]);for(int i=n;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	for(int i=0;i<K;i++) rs=(rs+1ll*(i&1?P-1:1)*fi[i]%P*fi[K-1-i]%P*ksm(K-i,n-2)%P*(K-i+n-1))%P;
	return printf("%lld\n",1ll*rs*sm%P),0;
}