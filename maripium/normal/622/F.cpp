#include <bits/stdc++.h>
using namespace std;

struct Lagrange {
	static const int K = 1e6 + 5;
	static const int MOD = 1e9 + 7;
	int f[K];
	int fac[K], ifac[K];
	int prf[K], suf[K];
	void add(int &x,int y) { x = x + y >= MOD ? x + y - MOD : x + y; }
	void sub(int &x,int y) { x = x >= y ? x - y : x - y + MOD; }
	int mul(int x,int y) { return 1LL * x * y % MOD; }
	int fpow(int x,int y) {
		int res = 1;
		while (y) {
			if (y & 1) res = mul(res, x);
			x = mul(x, x);
			y >>= 1;
		}
		return res;
	}
	void build() {
		fac[0] = 1;
		for (int i = 1;i < K;++i) fac[i] = mul(fac[i - 1], i);
		ifac[K - 1] = fpow(fac[K - 1], MOD - 2);
		for (int i = K - 2;i >= 0;--i) ifac[i] = mul(ifac[i + 1], i + 1);
	}
	void precalc(int k) {
		f[0] = 0;
		for (int i = 1;i < K;++i) { 
			f[i] = f[i - 1];
			add(f[i], fpow(i, k));
		}
	}
	int calc(int n,int k) {
		if (n < K) return f[n];
		int res = 0;
		int all = 1;
		for (int i = 1;i <= k + 2;++i) all = mul(all, n - i + MOD);
		for (int i = 1;i <= k + 2;++i) {
			int upd = mul(mul(all, fpow(n - i + MOD, MOD - 2)), mul(f[i], mul(ifac[i - 1], ifac[k + 2 - i])));
			if ((k + 2 - i) & 1) sub(res, upd);
			else add(res, upd);
		}
		return res;
	}
} lag;
int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	lag.build(), lag.precalc(k);
	cout << lag.calc(n, k) << endl;
}