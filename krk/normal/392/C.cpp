#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxd = 85;

int C[Maxd][Maxd];
ll n;
int k;
int D;
int res;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < D; i++)
			for (int j = 0; j < D; j++)
				m[i][j] = (i == j) * diag;
	} 
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < D; i++)
			for (int j = 0; j < D; j++)
				for (int l = 0; l < D; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j] % mod) % mod;
		return c;
	}
};

int main()
{
	for (int i = 0; i < Maxd; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%I64d %d", &n, &k); D = 2 * k + 3;
	matrix r(1), a;
	a.m[0][0] = 1; a.m[0][D - 1] = 1;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= i; j++)
			a.m[1 + i][1 + j] = C[i][i - j];
		for (int j = 0; j <= i; j++)
			a.m[1 + i][k + 2 + j] = (1ll << i - j) % mod * C[i][i - j] % mod;
	}
	for (int i = 0; i <= k; i++)
		a.m[k + 2 + i][1 + i] = 1;
	while (n) {
		if (n & 1ll) r = r * a;
		n >>= 1ll; a = a * a;
	}
	for (int i = 0; i <= k; i++)
		res = (res + (1ll << i + 1) % mod * r.m[0][1 + i] % mod) % mod;
	for (int i = 0; i <= k; i++)
		res = (res + r.m[0][k + 2 + i]) % mod;
	printf("%d\n", res);
	return 0;
}