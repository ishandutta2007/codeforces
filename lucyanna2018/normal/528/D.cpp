#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

namespace fft_um_nik {

	typedef long long ll;
	const ll MOD = 998244353;
	ll add(ll x, ll y) {
		x += y;
		if (x >= MOD) return x - MOD;
		return x;
	}
	ll sub(ll x, ll y) {
		x -= y;
		if (x < 0) return x + MOD;
		return x;
	}
	ll mult(ll x, ll y) {
		return (x * y) % MOD;
	}
	ll bin_pow(ll x, ll p) {
		if (p == 0) return 1;
		if (p & 1) return mult(x, bin_pow(x, p - 1));
		return bin_pow(mult(x, x), p / 2);
	}
	ll Rev(ll x) {
		return bin_pow(x, MOD - 2);
	}

	const int LOG = 20;
	const int N = 1 << LOG;
	const int NN = N + 5;
	ll W;
	ll w[NN];
	int rev[NN];

	void FFT_init() {
		W = 2;
		while (true) {
			ll x = W;
			for (int i = 1; i < LOG; i++)
				x = mult(x, x);
			if (x == MOD - 1)
				break;
			W++;
		}
		w[0] = 1;
		for (int i = 1; i < N; i++)
			w[i] = mult(w[i - 1], W);
		for (int mask = 1; mask < N; mask++) {
			int k = 0;
			while (((mask >> k) & 1) == 0) k++;
			rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (LOG - 1 - k));
		}
	}

	ll F[2][NN];
	void FFT(ll* A, int k) {
		int L = 1 << k;
		for (int i = 0; i < L; i++)
			F[0][rev[i] >> (LOG - k)] = A[i];
		int t = 0, nt = 1;
		for (int lvl = 0; lvl < k; lvl++) {
			int len = 1 << lvl;
			for (int st = 0; st < L; st += (len << 1))
				for (int i = 0; i < len; i++) {
					ll ad = mult(F[t][st + len + i], w[i << (LOG - 1 - lvl)]);
					F[nt][st + i] = add(F[t][st + i], ad);
					F[nt][st + len + i] = sub(F[t][st + i], ad);
				}
			swap(t, nt);
		}
		for (int i = 0; i < L; i++)
			A[i] = F[t][i];
	}

	ll tmpA[NN], tmpB[NN];
	void Polymul(ll*A, int N, ll*B, int M, ll*C) {
		int k = 0; while ((1 << k) < N + M) k++;
		memset(tmpA, 0, sizeof(ll)*(1LL << k));
		memset(tmpB, 0, sizeof(ll)*(1LL << k));
		for (int i = 0; i < N; i++)tmpA[i] = A[i];
		for (int i = 0; i < M; i++)tmpB[i] = B[i];
		FFT(tmpA, k);
		FFT(tmpB, k);
		for (int i = 0; i < (1 << k); i++)tmpA[i] = mult(tmpA[i], tmpB[i]);
		FFT(tmpA, k);
		ll rn = Rev(1LL << k);
		reverse(tmpA + 1, tmpA + (1LL << k));
		for (int i = 0; i < N + M - 1; i++)C[i] = mult(tmpA[i], rn);
	}
	void dot(ll*A, int N, ll*B, int M, ll*C) {
		int k = 0; while ((1 << k) < N + M) k++;
		memset(tmpA, 0, sizeof(ll)*(1LL << k));
		memset(tmpB, 0, sizeof(ll)*(1LL << k));
		for (int i = 0; i < N; i++)tmpA[i] = A[i];
		for (int i = 0; i < M; i++)tmpB[M - 1 - i] = B[i];
		FFT(tmpA, k);
		FFT(tmpB, k);
		for (int i = 0; i < (1 << k); i++)tmpA[i] = mult(tmpA[i], tmpB[i]);
		FFT(tmpA, k);
		ll rn = Rev(1LL << k);
		reverse(tmpA + 1, tmpA + (1LL << k));
		for (int i = 0; i < N + M - 1; i++)C[i - (M - 1)] = mult(tmpA[i], rn);
	}
}

#define ran 202222
int N, M, K;
char A[ran], B[ran];
bool bad[ran];
int sum[ran];

fft_um_nik::ll q[ran], r[ran], ss[ran * 2], *s;
void proc(char x) {
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + (A[i] == x);
	}
	int w = 0;
	for (int i = 0; i < M; i++) {
		q[i] = (B[i] == x ? 1 : 0);
		w += (B[i] == x);
	}
	for (int i = 0; i < N; i++) {
		r[i] = (sum[min(i + K + 1, N)] - sum[max(i - K, 0)] ? 1 : 0);
	}
	s = ss + M;
	fft_um_nik::dot(r, N, q, M, s);
	for (int i = 0; i <= N - M; i++)
		if (s[i] != w)bad[i] = true;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	scanf("%s%s", A, B);
	fft_um_nik::FFT_init();
	proc('A');proc('C');proc('G');proc('T');
	int res = 0;
	for (int i = 0; i <= N - M; i++)if (!bad[i])res++;
	printf("%d\n", res);
	return 0;
}