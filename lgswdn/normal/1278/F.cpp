#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=5009,mod=998244353;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k,m,fac[N],inv[N],s[N][N],ans,c=1;
void pre(int n) {
    inv[0]=inv[1]=fac[0]=s[0][0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,n) rep(j,1,i) s[i][j]=(s[i-1][j-1]+s[i-1][j]*j%mod)%mod;
}
int ksm(int x,int y,int res=1) {
	while(y) {
		if(y%2) res=res*x%mod;
		x=x*x%mod, y>>=1;
	}
	return res;
}

signed main() {
	n=read(), m=read(), k=read();
	pre(k);
	rep(j,1,min(n,k))
		c=c*(n-j+1)%mod*inv[j]%mod,
		ans=(ans+s[k][j]*fac[j]%mod*c%mod*ksm(m,n-j)%mod)%mod;
	printf("%lld\n",ans*ksm(ksm(m,n),mod-2)%mod);
	return 0;
}