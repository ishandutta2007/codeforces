#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int itwo = 500000004;
const int Maxd = 2;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = (i == j) * diag;
	}
	matrix operator*(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int l = 0; l < Maxd; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j]) % mod;
		return c;
	}
};

int k;

int main()
{
	scanf("%d", &k);
	int q = 2;
	matrix A;
	A.m[0][0] = A.m[0][1] = itwo;
	A.m[1][0] = 1;
	while (k--) {
		ll pw; scanf("%I64d", &pw);
		int r = 1;
		matrix R(1);
		while (pw) {
			if (pw & 1ll) {
				r = ll(r) * q % mod;
				R = R * A;
			}
			pw >>= 1ll; 
			q = ll(q) * q % mod;
			A = A * A;
		}
		q = r; A = R;
	}
	int p = (ll(A.m[0][0]) + ll(A.m[0][1]) * (mod - 1)) % mod;
	q = ll(q) * itwo % mod;
	p = ll(p) * q % mod;
	printf("%d/%d\n", p, q);
	return 0;
}