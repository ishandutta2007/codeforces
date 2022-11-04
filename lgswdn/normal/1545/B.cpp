#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9,mod=998244353;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n;
char s[N];

int fac[N],inv[N],ifac[N];
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

signed main() {
	T=read();
	pre(100000);
	while(T--) {
		scanf("%lld%s",&n,s+1);
		int cnt=0,rn=0;
		rep(i,1,n-1) {
			if(s[i]=='1'&&s[i+1]=='1') cnt++,i++;
			else if(s[i]=='0') rn++;
		}
		rn+=(s[n]=='0'); 
		printf("%lld\n",C(rn+cnt,cnt));
	}
	return 0;
}