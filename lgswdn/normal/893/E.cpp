#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e6+9,mod=1e9+7;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,x,y,fac[N],inv[N],ifac[N];
void pre(int n=2000000) {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,n) ifac[i]=ifac[i-1]*inv[i]%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int ksm(int x,int y) {
	if(y==0) return 1;
	else return ksm(x*x%mod,y/2)*(y%2?x:1)%mod;
}

signed main() {
	pre();
	int T=read();
	while(T--) {
		int y=read(), x=read(), ans=ksm(2,x-1);
		for(int i=2;i*i<=y;i++) {
			if(y%i) continue;
			int cnt=0;
			while(y%i==0) y/=i, cnt++;
			ans=ans*C(cnt+x-1,x-1)%mod;
		}
		if(y!=1) ans=ans*x%mod;
		printf("%lld\n",ans);
	}
	return 0;
}