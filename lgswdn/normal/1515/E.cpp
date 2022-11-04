#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=409;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,mod,f[N][N],fac[N],inv[N],ifac[N],pw[N],ans;
void pre() {
    inv[0]=inv[1]=fac[0]=ifac[0]=pw[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    rep(i,2,n) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,n) ifac[i]=ifac[i-1]*inv[i]%mod;
    rep(i,1,n) pw[i]=pw[i-1]*2%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

signed main() {
	n=read(), mod=read();
	pre();
	f[1][1]=1, f[2][1]=2;
	rep(i,3,n) {
		rep(j,1,(i+1)/2) {
			if(j!=1) {
				rep(k,1,i-2) {
					f[i][j]=(f[i][j]+f[k][j-1]*C(i-j+1,i-k-1)%mod*pw[i-k-2]%mod)%mod;
				}
			} else {
				f[i][j]=pw[i-1];
			}
			if(i==n) ans=(ans+f[i][j])%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}