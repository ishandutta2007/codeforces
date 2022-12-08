#include <stdio.h>

const long long mod = 998244353;

int N, S, A[100100]; long long v[300300], inv[300300] = { 0,1 };

int main()
{
	for (int i = 2; i < 300300; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;

	scanf ("%d", &N);
	for (int i = 0; i < N; i++){
		scanf ("%d", &A[i]);
		S += A[i];
	}

	v[0] = v[1] = 0;
	for (int i = 1; i < S; i++){
		long long a = 1ll * (N - 1) * i % mod * (v[i] - v[i - 1] - 1 + mod) % mod;
		a = a * inv[S - i] % mod;
		v[i + 1] = (v[i] + a + mod) % mod;
	}

	long long last = v[S];
	for (int i = 0; i < N; i++) last = (last - v[A[i]] + mod) % mod;
	printf ("%lld\n", (mod - last) % mod);
	return 0;
}