#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=1e5+5,MOD=998244353;
int n;
ll a[N],s[N];
ll fac[N],ifac[N];
ll qpow(ll a,int x) {
	ll z=1;
	for(;x;x>>=1,a=a*a%MOD)
		if(x&1) z=z*a%MOD;
	return z;
}
map<ll,int> cnt;
ll C(int n,int m) {return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;}
int main() {
	int T=read();
	while(T--) {
		n=read();
		*fac=1; fr(i,1,n) fac[i]=fac[i-1]*i%MOD;
		ifac[n]=qpow(fac[n],MOD-2);
		rf(i,n,1) ifac[i-1]=ifac[i]*i%MOD;
		fr(i,1,n) a[i]=read(),s[i]=s[i-1]+a[i];
		cnt.clear();
		fr(i,1,n-1) ++cnt[s[i]];
		ll ans=1;
		for(auto p:cnt) if(p.first<=s[n]/2) {
			if(p.first*2==s[n])
				ans=ans*qpow(2,p.second)%MOD;
			else {
				int A=p.second,B=cnt[s[n]-p.first];
				ans=ans*C(A+B,A)%MOD;
			}
		} else break;
		printf("%lld\n",ans);
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}