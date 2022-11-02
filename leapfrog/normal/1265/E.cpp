#include<bits/stdc++.h>
using namespace std;const int P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,p[200005],a[200005],sm;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),a[0]=sm=1;for(int i=1;i<=n;i++) read(p[i]),p[i]=1ll*p[i]*ksm(100)%P;
	for(int i=1;i<n;i++) a[i]=1ll*a[i-1]*p[i]%P,sm=(sm+a[i])%P;
	return printf("%lld\n",1ll*sm*ksm(1ll*a[n-1]*p[n]%P)%P),0;
}