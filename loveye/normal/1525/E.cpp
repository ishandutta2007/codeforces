#include<bits/stdc++.h>
using namespace std;

int read();
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

const int N = 25,M = 5e4 + 5,MOD = 998244353;
int n,m,d[N][M];
LL ans,iv;
inline LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
int buc[N],sum[N];
inline LL calc(int id) {
	fr(i,0,n) buc[i] = 0;
	fr(i,1,n) buc[d[i][id]-1]++;
	LL res = 1;
	if(buc[0]) return 0;
	fr(i,1,n) {
		sum[i] = sum[i-1] + buc[i];
		if(sum[i] > i) return 0;
		fo(j,0,buc[i]) res = res * (i-sum[i-1]-j) % MOD;
	}
	return res;
}
int main() {
	scanf("%d%d",&n,&m);
	fr(i,1,n) fr(j,1,m) scanf("%d",&d[i][j]);
	iv = 1;
	fr(i,1,n) iv = iv * i % MOD;
	fr(i,1,m) (ans += iv-calc(i)) %= MOD;
	iv = qpow(iv,MOD-2);
	printf("%lld\n",((ans * iv % MOD) + MOD) % MOD);
	return 0;
}