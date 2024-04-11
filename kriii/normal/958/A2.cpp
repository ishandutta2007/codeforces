#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void proc()
{
	int N, M;
	scanf("%d %d", &N, &M);

	char A[2020][202], B[202][2020];
	for (int i = 0; i < N; i++) scanf("%s", A[i]);
	for (int i = 0; i < M; i++) scanf("%s", B[i]);

	long long AH[2020],BH[202][2020];
	const long long mod = 1200000041, base = 257;
	long long rbase = 1, abase = 1;
	for (int j = 0; j < M; j++) rbase = rbase * base % mod;
	for (int j = 0; j < M; j++) abase = abase * rbase % mod;
	for (int i = 0; i < N; i++) {
		long long h = 0;
		for (int j = 0; j < M; j++) {
			h = (h * base + A[i][j]) % mod;
		}
		AH[i] = h;
	}

	for (int i = 0; i < M; i++) {
		long long h = 0;
		for (int j = 0; j < N; j++) {
			h = (h * base + B[i][j]) % mod;
			if (j >= M) h = (h + mod - rbase * B[i][j - M] % mod) % mod;
			if (j >= M-1) BH[i][j-(M-1)] = h;
		}
	}

	map<long long, int> r, c;
	long long h = 0;
	for (int i = 0; i < N; i++) {
		h = (h * rbase + AH[i]) % mod;
		if (i >= M) h = (h + mod - abase * AH[i - M] % mod) % mod;
		if (i >= M - 1) r[h] = i - (M - 1);
	}
	for (int j = 0; j <= N-M; j++) {
		long long h = 0;
		for (int i = 0; i < M; i++) {
			h = (h * rbase + BH[i][j]) % mod;
		}
		c[h] = j;
	}

	for (auto &p : r) {
		if (c.count(p.first)) {
			printf("%d %d\n", p.second+1, c[p.first]+1);
			return;
		}
	}
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}