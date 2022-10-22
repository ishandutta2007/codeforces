#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 20,S = 1 << 14,MOD = 1e9 + 7;
int n,a[N],id[S],U,pct[S];
ll dp[S],f[N][S],G[N][N];
ll qpow(ll a,int x) {
	ll res = 1;
	for(;x;x >>= 1,a = a * a % MOD) if(x & 1) res = res * a % MOD;
	return res;
}
ll calc(int s,int t) {
	ll res = 1;
	fr(i,1,n) if(s >> i-1 & 1) res = res * f[i][t] % MOD;
	return res;
}
int main() {
	cin >> n; U = (1 << n) - 1;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) fr(j,1,n) G[i][j] = a[i] * qpow(a[i] + a[j],MOD-2) % MOD;
	fr(i,1,n) id[1 << i-1] = i;
	fr(i,1,n) {
		f[i][0] = 1;
		fo(s,1,1 << n)
			f[i][s] = f[i][s & s-1] * G[i][id[s & -s]] % MOD;
	}
	fo(s,1,1 << n) {
		dp[s] = 1;
		for(int ss = s-1 & s;ss;ss = ss-1 & s)
			(dp[s] -= dp[ss] * calc(ss,s ^ ss)) %= MOD;
	}
	ll ans = 0;
	fo(s,1,1 << n) {
		pct[s] = pct[s >> 1] + (s&1);
		(ans += dp[s] * calc(s,U ^ s) % MOD * pct[s]) %= MOD;
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}