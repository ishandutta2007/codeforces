#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=3e6+9,mod=1e9+7;

int n,f[N],fac[N],inv[N],ifac[N],g[N];
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
	n=read(); pre(3*n+5);
	rep(i,0,3*n+3) f[i]=C(3*n+3,i); f[0]--, f[1]-=3, f[2]-=3, f[3]--;
	rep(i,0,3*n+3) f[i]=f[i+1], g[i]=f[i];
	per(i,3*n+1,0) f[i]=g[i+2], g[i+1]-=3*g[i+2], g[i]-=3*g[i+2], g[i+1]=(g[i+1]%mod+mod)%mod, g[i+2]=(g[i+2]%mod+mod)%mod;
	int Q=read();
	while(Q--) printf("%lld\n",f[read()]);
	return 0;
}