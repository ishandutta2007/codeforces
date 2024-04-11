#include <bits/stdc++.h>
using namespace std;

namespace Interpolation {
	static const int N = 5005;
	static const int MOD = 1e9 + 7;
	int f[N];
	int fac[N], ifac[N];
	int prf[N], suf[N];
	int C[N][N], pw[N][N];
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
		for (int i = 1;i < N;++i) fac[i] = mul(fac[i - 1], i);
		ifac[N - 1] = fpow(fac[N - 1], MOD - 2);
		for (int i = N - 2;i >= 0;--i) ifac[i] = mul(ifac[i + 1], i + 1);
		for (int i = 0;i < N;++i) C[0][i] = C[i][i] = 1;
		for (int j = 1;j < N;++j) {
			for (int i = 1;i < j;++i) {
				C[i][j] = C[i - 1][j - 1];
				add(C[i][j], C[i][j - 1]);
			}
		}
		for (int i = 1;i < N;++i) {
			pw[i][0] = 1;
			for (int j = 1;j < N;++j) pw[i][j] = mul(pw[i][j - 1], i); 		
		}
	}
	void A06Xaoloz() {
		build();
		int n, k; cin >> n >> k;
		for (int i = 1;i <= k + 1;++i) {
			f[i] = 0;
			for (int j = 1;j <= i;++j) add(f[i], mul(pw[j][k], C[j][i]));
			f[i] = mul(f[i], fpow(fpow(2, i), MOD - 2));
		}
		prf[0] = suf[k + 2] = 1;
		for (int i = 1;i <= k + 1;++i) prf[i] = mul(prf[i - 1], MOD + n - i);
		for (int i = k + 1;i >= 1;--i) suf[i] = mul(suf[i + 1], MOD + n - i);
		int res = 0;
		for (int i = 1;i <= k + 1;++i) {
			if ((k + 1 - i) & 1) sub(res, mul(mul(f[i], mul(ifac[i - 1], ifac[k + 1 - i])), mul(prf[i - 1], suf[i + 1])));
			else add(res, mul(mul(f[i], mul(ifac[i - 1], ifac[k + 1 - i])), mul(prf[i - 1], suf[i + 1])));
		}
		cout << mul(res, fpow(2, n)) << endl;
	}	
}
int main() {
	ios_base::sync_with_stdio(false);
	Interpolation::A06Xaoloz();
}