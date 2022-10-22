#include<bits/stdc++.h>
using namespace std;

int read();
#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e6 + 10,MOD = 1e9 + 7,iv3 = (MOD+1) / 3;
int n,q;
ll fac[3*N],ifac[3*N],f[N*3];
ll C(int n,int m) {
	if(n < m) return 0;
	return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}
ll qpow(ll a,int x) {
	ll res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
int main() {
	scanf("%d%d",&n,&q);
	fac[0] = 1; ++n;
	fr(i,1,3*n) fac[i] = fac[i-1] * i % MOD;
	ifac[3*n] = qpow(fac[3*n],MOD-2);
	rf(i,3*n-1,0) ifac[i] = ifac[i+1] * (i+1) % MOD;

	fr(i,0,2) fo(j,0,n) (f[i] += C(3*j,i)) %= MOD;
	fr(i,4,n*3+1) f[i-1] = (C(3*n,i) - f[i-2] * 3 - f[i-3]) * iv3 % MOD;
	while(q--) {
		static int x;
		scanf("%d",&x);
		printf("%lld\n",(f[x] + MOD) % MOD);
	}
	return 0;
}