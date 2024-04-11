#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5,MOD = 998244353;
int n,k,a[N],c;
ll fac[N],ifac[N];
ll qpow(ll a,int x) {
	ll res = 1;
	for(;x;x >>= 1,a = a * a % MOD)
		if(x & 1) res = res * a % MOD;
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	fr(i,1,n) cin >> a[i];
	a[n+1] = a[1];
	fr(i,1,n) if(a[i] != a[i+1]) ++c;
	fac[0] = 1; fr(i,1,n) fac[i] = fac[i-1] * i % MOD;
	ifac[n] = qpow(fac[n],MOD-2);
	rf(i,n,1) ifac[i-1] = ifac[i] * i % MOD;
	ll ans = 0;
	fr(i,0,c>>1) (ans += fac[c] * ifac[i] % MOD * ifac[i] % MOD * ifac[c-2*i] % MOD * qpow(k-2,c-2*i)) %= MOD;
	ans = (qpow(k,c) - ans + MOD) % MOD;
	cout << ans * qpow(2,MOD-2) % MOD * qpow(k,n-c) % MOD << endl;
	return 0;
}