#include<cstdio>
#include<cstring>
#include<algorithm>
#include<complex>
using namespace std;

namespace fft_um_nik {

	typedef complex<double> ll;
	const double PI = acos(-1.0);
	ll add(ll x, ll y) {
		return x + y;
	}
	ll sub(ll x, ll y) {
		return x - y;
	}
	ll mult(ll x, ll y) {
		return x * y;
	}
	ll Rev(ll x) {
		return complex<double>(1.0, 0.0) / x;
	}

	const int LOG = 19;
	const int N = 1 << LOG;
	const int NN = N + 5;
	ll W;
	ll w[NN];
	int rev[NN];

	void FFT_init() {
		for (int i = 0; i < N; i++)
			w[i] = complex<double>(cos(2 * PI * i / N), sin(2 * PI * i / N));

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
		ll rn = Rev(complex<double>(1LL << k, 0.0));
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
		ll rn = Rev(complex<double>(1LL << k, 0.0));
		reverse(tmpA + 1, tmpA + (1LL << k));
		for (int i = 0; i < N + M - 1; i++)C[i - (M - 1)] = mult(tmpA[i], rn);
	}
}

#define ran 202222
int N, sum[ran], aa[ran];

fft_um_nik::ll q[ran], ss[ran * 2], *s;
int main() {
	int X, Y;
	fft_um_nik::FFT_init();
	scanf("%d%d", &N, &X);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &Y);
		sum[i] = sum[i - 1] + (X > Y);
	}
	for (int i = 0; i <= N; i++) aa[sum[i]] ++;
	for (int i = 0; i <= N; i++)q[i] = complex<double>(aa[i], 0);
	s = ss + N + 1;
	fft_um_nik::dot(q, N + 1, q, N + 1, s);
	long long int fir = (long long int)(s[0].real() + 0.5);
	for (int i = 0, j; i <= N; i = j) {
		for (j = i; j <= N && sum[j] == sum[i]; j++);
		long long int L = j - i;
		fir -= L;
		fir -= L * (L - 1) / 2;
	}
	printf("%I64d", fir);
	for (int i = 1; i <= N; i++)
		printf(" %I64d", (long long int)(s[i].real() + 0.5));
	puts("");
	return 0;
}