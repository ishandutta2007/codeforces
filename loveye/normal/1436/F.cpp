#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

#define LL long long
#define int long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &

const int N = 1e5 + 5;
int m = 1e5,n;
LL cnt[N],ans;
int p[N],mu[N];
bool np[N];

inline LL qpow(LL a,int x) {
	LL res = 1;if(x < 0) return 0;
	for(;x;x >>= 1) (x & 1) && (res = res * a % MOD),a = a * a % MOD;
	return res;
}
LL bs[N],gs[N];
inline void prepare_pow() {
	bs[0] = gs[0] = 1;
	for(int i = 1;i <= m;++i)
		bs[i] = (bs[i-1] << 1) % MOD;
	gs[1] = bs[m];
	for(int i = 1;i <= m;++i)
		gs[i] = gs[i-1] * gs[1] % MOD;
}
inline LL spow(int x) {
	return gs[x / m] * bs[x % m] % MOD;
}

inline void prepare() {
	np[1] = 1;
	mu[1] = 1;
	for(int i = 2,ni;i <= m;++i) {
		if(!np[i]) {
			p[++p[0]] = i;
			mu[i] = -1;
		}
		for(int j = 1;j <= p[0] && (ni = i*p[j]) <= m;++j) {
			np[ni] = 1;
			if(i % p[j] == 0) break;
			mu[ni] = -mu[i];
		}
	}
}
#define calc(n) spow(n)
#define calc2(n) (n * spow(n-1) % MOD)
#define calc3(n) (n * (n-1) % MOD * spow(n-2) % MOD)
#define calc4(n) (n * (n-1) % MOD * (n-2) % MOD * spow(n-3) % MOD)
signed main() {
	ios::sync_with_stdio(0);
	cin >> n;
	prepare();
	prepare_pow();
	for(int i = 1,x,v;i <= n;++i)
		cin >> x >> v,cnt[x] += v;
	for(int d = 1;d <= m;++d) {
		if(!mu[d]) continue;
		LL A = -1,AS2 = 0,AS = 0,S = 0,S2 = 0,res = 1;
		LL nA = -1,nAS2 = 0,nAS = 0,nS = 0,nS2 = 0,nres = 1;
		for(int i = d;i <= m;i += d) {
			if(cnt[i] == 0) continue;
			LL tmp = calc(cnt[i]),c1 = calc2(cnt[i]),c2 = (calc3(cnt[i])+calc2(cnt[i])) % MOD,
			c3 = (calc4(cnt[i])+calc3(cnt[i])*3+calc2(cnt[i])) % MOD;
			nres = res * tmp % MOD;
			nS = (S * tmp % MOD + c1 * i % MOD * res % MOD) % MOD;
			nS2 = (S2*tmp % MOD + 2 * i % MOD * S % MOD * c1 % MOD + i * i % MOD * c2 % MOD * res % MOD) % MOD;
			nA = (A * tmp % MOD + res * c1 % MOD) % MOD;
			nAS = (AS*tmp % MOD + i * A % MOD * c1 % MOD + S * c1 % MOD + i * c2 % MOD * res % MOD) % MOD;
			nAS2 = (AS2*tmp%MOD + 2*i%MOD*AS%MOD*c1%MOD + A*i%MOD*i%MOD*c2%MOD
					+ S2*c1%MOD + 2*i%MOD*S%MOD*c2%MOD + i*i%MOD*c3%MOD*res%MOD) % MOD;
			A = nA;
			AS2 = nAS2;
			AS = nAS;
			S = nS;
			S2 = nS2;
			res = nres;
		}
		(ans += mu[d] * AS2 % MOD) %= MOD;
	}
	cout << (ans+MOD)%MOD << endl;
	return 0;
}