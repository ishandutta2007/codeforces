#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9,mod=1e9+7;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k,a[N],p[N],s[N],inv[N],ifac[N],ans;

int ksm(int x,int y,int res=1) {
	while(y) {
		if(y%2) res=res*x%mod;
		x=x*x%mod, y>>=1;
	}
	return res;
}

void pre() {
	inv[0]=inv[1]=ifac[0]=ifac[1]=p[0]=s[k+3]=1;
	rep(i,2,k+2) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,2,k+2) ifac[i]=ifac[i-1]*inv[i]%mod;
	rep(i,1,k+2) p[i]=p[i-1]*(n-i)%mod;
	per(i,k+2,1) s[i]=s[i+1]*(n-i)%mod;
	rep(i,1,k+2) a[i]=(a[i-1]+ksm(i,k))%mod;
}

signed main() {
	n=read(), k=read();
	pre();
	rep(i,1,k+2) if(n==i) {printf("%lld\n",a[i]); return 0;}
	rep(i,1,k+2) {
		int res=a[i];
		res=res*p[i-1]%mod*s[i+1]%mod*ifac[i-1]%mod*ifac[k+2-i]%mod;
		ans+=res*((k+2-i)%2?-1:1);
		if(ans>mod) ans-=mod; if(ans<0) ans+=mod;
	}
	printf("%lld\n",ans);
	return 0;
}