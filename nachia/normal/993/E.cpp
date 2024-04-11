#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct FFT {
	ULL M, g, invg, inv2;
	ULL powm(ULL a, ULL i, ULL M) {
		if (i == 0) return 1;
		ULL tmp = powm(a, i >> 1, M);
		tmp = tmp * tmp % M;
		if (i & 1) tmp = tmp * a % M;
		return tmp;
	}
	void query(const ULL* src, ULL* res, UL len, bool inv, UL str = 1, ULL Z = -1) {
		if (len == 1) { res[0] = src[0]; return; }
		if (Z == -1) Z = powm((inv ? invg : g), (M - 1) / len, M);
		ULL Y = 1;
		query(src, res, len >> 1, inv, str << 1, Z * Z % M);
		query(src + str, res + (len >> 1), len >> 1, inv, str << 1, Z * Z % M);
		for (UL i = 0; i < (len >> 1); i++) {
			ULL r1 = res[i], r2 = res[i + (len >> 1)];
			r2 = r2 * Y % M;
			res[i] = (r1 + r2) % M;
			res[i + (len >> 1)] = (r1 + M - r2) % M;
			Y = Y * Z % M;
		}
		if (str == 1) {
			if (inv) {
				ULL mul = 1;
				for (UL t = len; t != 1; t >>= 1) mul = mul * inv2 % M;
				rep(i, len) res[i] = res[i] * mul % M;
			}
			else rep(i, len) res[i] %= M;
		}
	}
	vector<ULL> convolute(vector<ULL>& a, vector<ULL>& b) {
		UL sz = 1; while (sz < a.size() + b.size()) sz *= 2;
		a.resize(sz); b.resize(sz);
		vector<ULL> fa(sz), fb(sz);
		query(&a[0], &fa[0], sz, false);
		query(&b[0], &fb[0], sz, false);
		rep(i, sz) fb[i] = fa[i] * fb[i] % M;
		query(&fb[0], &fa[0], sz, true);
		return move(fa);
	}
} fft[2] = {
	{ 998244353, 3, 332748118, 499122177 },
	{ 1107296257, 10, 775107380, 553648129 }
};

struct Problem {
    void Solve() {
		//1022119632, 76788018
        UL N; int X;
        scanf("%d", &N); scanf("%d", &X);
        vector<ULL> S(N + 1); S[0] = 1;
        UL p = 0;
		rep(i, N) { int a; scanf("%d", &a); if (a < X) p++; S[p]++; }
        vector<ULL> rS = S; reverse(rS.begin(), rS.end());
		vector<ULL> FS0 = fft[0].convolute(S, rS);
		vector<ULL> FS1 = fft[1].convolute(S, rS);
		rep(i, FS0.size()) {
			FS1[i] = (FS1[i] + fft[1].M - FS0[i]) % fft[1].M;
			FS1[i] = FS1[i] * 1022119632 % fft[1].M * 998244353 + FS0[i];
		}
        printf("%lld", (FS1[N] - N - 1) / 2);
        rep(i, N) printf(" %lld", FS1[N + 1 + i]);
        printf("\n");
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}