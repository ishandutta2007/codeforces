#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9,mod=1e9+7;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k,fac[N],inv[N],ifac[N];
void pre(int n) {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,n) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
void add(int &x,int y) {x+=y; if(x>mod) x-=mod; if(x<0) x+=mod;}
int ksm(int x,int y,int ret=1) {
	while(y) {
		if(y%2) ret=ret*x%mod;
		x=x*x%mod, y>>=1;
	}
	return ret;
}

signed main() {
	int n=read(), k=read(), res1=0, res2=0;
	rep(i,1,n) add(res1,read());
	if(n==1) {printf("%lld\n",res1); return 0;}
	pre(n);
	rep(j,0,k-1) {
		int ret=ifac[j]*ifac[k-j-1]%mod;
		ret=ret*(ksm(k-j,n-1)+(n-1)*ksm(k-j,n-2)%mod)%mod;
		add(res2,(j%2?-1:1)*ret);
	}
	printf("%lld\n",res1*res2%mod);
	return 0;
}