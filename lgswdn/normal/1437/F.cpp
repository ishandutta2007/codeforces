#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=5009, mod=998244353;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,a[N],l[N],f[N];

int fac[N], inv[N], ifac[N];
void pre() {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=1;i<=n;i++) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int A(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[x-y]%mod;
}

signed main() {
	n=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	if(a[n]<a[n-1]*2) return puts("0"), 0;
	pre();
	rep(i,1,n) rep(j,1,n) if(a[i]>=2*a[j]) l[i]=j;
	f[0]=1; l[0]=-1;
	rep(i,1,n) rep(j,0,l[i]) f[i]=(f[i]+f[j]*A(n-2-l[j],l[i]-l[j]-1)%mod)%mod;
	printf("%lld\n",f[n]);
	return 0;
}