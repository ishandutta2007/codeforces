#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define bp __builtin_parity
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

const int N=5009;
int n,mod;

int fac[N],inv[N],ifac[N],f[N];
int ksm(int x,int y,int res=1) {
    for(;y;y>>=1,x=x*x%mod) if(y%2==1) res=res*x%mod;
    return res;
}
void pre(int n) {
    inv[0]=inv[1]=fac[0]=ifac[0]=1;
    rep(i,1,n) fac[i]=fac[i-1]*i%mod;
    ifac[n]=ksm(fac[n],mod-2);
    per(i,n-1,1) ifac[i]=ifac[i+1]*(i+1)%mod;
    rep(i,2,n) inv[i]=ifac[i]*fac[i-1]%mod;
}
int C(int x,int y) {
    if(x<0||y<0||x<y) return 0;
    else return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

signed main() {
	n=read(), mod=read();
	pre(n);
	f[0]=fac[n], f[1]=n*fac[n-1]%mod;
	rep(k,2,n) {
		rep(i,2,(n+1)/2) f[k]=(f[k]+n*C(i-2,k-2))%mod;
		f[k]=f[k]*fac[n-k]%mod*fac[k]%mod;
	}
	rep(k,0,n) {
		f[k]=(f[k]-f[k+1]+mod)%mod;
	}
	int ans=0;
	rep(k,0,n) {
		ans=(ans+f[k]*ifac[k]%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}