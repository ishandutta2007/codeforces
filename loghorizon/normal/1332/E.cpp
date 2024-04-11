#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int P = 998244353;

typedef long long LL;

int n, m, L, R;

struct Mul{
    int n, m, w[2][2];
    Mul operator * (const Mul &b) {
        Mul c; c.n = n, c.m = b.m;
        memset(c.w, 0, sizeof c.w);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++)
                    c.w[i][j] = (c.w[i][j] + (LL) w[i][k] * b.w[k][j] ) % P;
        return c;
    }
} res, A;


LL power(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &L, &R);
	if (((LL)n * m) & 1) {
		printf("%lld\n", power(R - L + 1, (LL)n * m)); 
	} else {
		int c1 = ((R + 1) / 2) - L / 2;
		int c0 = (R / 2) - (L - 1) / 2;
		res.n = 1, res.m = A.n = A.m = 2;
		res.w[0][0] = 1;
		A.w[0][0] = c0;
		A.w[0][1] = c1;
		A.w[1][0] = c1;
		A.w[1][1] = c0;
		LL b = (LL) n * m;
		while (b) {
			if (b & 1) res = res * A;
			A = A * A;
			b >>= 1;
		}
		printf("%d\n", res.w[0][0]);
	}
	return 0;
}