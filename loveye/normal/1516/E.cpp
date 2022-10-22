#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 205,MOD = 1e9 + 7;
int n,k;
LL f[N],g[N];
inline LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
I getexp() {
	g[0] = 1;
	fr(i,1,k) {
		fr(j,1,i) (g[i] += f[j] * j % MOD * g[i-j]) %= MOD;
		g[i] = g[i] * qpow(i,MOD-2) % MOD;
	}
}
LL dp[N],C[N][N];
int main() {
	scanf("%d%d",&n,&k);
	C[0][0] = 1;
	fr(i,1,k+1) {
		C[i][0] = 1;
		fr(j,1,i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}
	dp[0] = n;
	fr(i,1,k) {
		dp[i] = qpow(n,i+1);
		fr(j,0,i-1) (dp[i] -= C[i+1][j] * dp[j]) %= MOD;
		dp[i] = dp[i] * qpow(i+1,MOD-2) % MOD;
	}
	fr(i,1,k) f[i] = (i&1 ? 1 : -1) * qpow(i,MOD-2) * dp[i] % MOD;
	getexp();
	fr(i,2,k) g[i] = (g[i] + g[i-2]) % MOD;
	fr(i,1,k) printf("%lld ",(g[i] + MOD) % MOD);
	return 0;
}