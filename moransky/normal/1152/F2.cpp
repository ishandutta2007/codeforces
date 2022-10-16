#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int S = 13, M = 4, SZ = S * (1 << M), P = 1e9 + 7;

int n, K, m, s, sum;

struct Mat{
	int w[SZ][SZ], n, m;
	Mat inline operator * (Mat b) {
		Mat c; memset(c.w, 0, sizeof c.w);
		c.n = n, c.m = b.m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					c.w[i][j] = (c.w[i][j] + (LL)w[i][k] * b.w[k][j]) % P;
				}
			}
		}
		return c;
	}
} A, res;

int inline get(int i, int j) {
	return i * (1 << m) + j;
}

int inline bits(int x) {
	int cnt = 0;
	while (x) cnt++, x -= x & -x;
	return cnt;
}

void inline add(int u, int v, int w) {
	(A.w[u][v] += w) %= P;
}

int inline An(int x) {
	return x & s;
}

int main() {
	scanf("%d%d%d", &n, &K, &m); s = (1 << m) - 1;
	sum = (K + 1) * (1 << m);
	A.n = A.m = res.m = sum, res.n = 1;
	res.w[0][0] = 1; 
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < (1 << m); j++) {
			add(get(i, j), get(i, An(j << 1)), 1);
			if (i < K) add(get(i, j), get(i + 1, An(j << 1 | 1)), 1 + bits(j));
		}
	}
	while (n) {
		if (n & 1) res = res * A;
		A = A * A;
		n >>= 1;
	}
	int ans = 0;
	for (int i = 0; i < (1 << m); i++)
		ans = (ans + res.w[0][get(K, i)]) % P;
	printf("%d\n", ans);
	return 0;
}