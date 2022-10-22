#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int Maxd = 4;

ll n;
ull k; 
int l;
int mod;
int res0, res1;
int res;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = (i == j) * diag;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int l = 0; l < Maxd; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j]) % mod;
		return c;
	}
};

void Solve(ll n)
{
	matrix R(1), A;
	A.m[0][0] = A.m[0][1] = 1;
	A.m[1][0] = 1;
	A.m[2][2] = A.m[2][3] = 1;
	A.m[3][1] = A.m[3][2] = A.m[3][3] = 1;
	while (n) {
		if (n & 1) R = R * A;
		n >>= 1; A = A * A;
	}
	res0 = (R.m[0][0] + R.m[1][0]) % mod;
	res1 = (R.m[2][0] + R.m[3][0]) % mod;
}

int Bits(ull k)
{
	int res = 0;
	while (k) {
		res++; k >>= ull(1);
	}
	return res;
}

int main()
{
	cin >> n >> k >> l >> mod;
	if (mod == 1 || Bits(k) > l) { printf("0\n"); return 0; }
	Solve(n);
	res = 1;
	for (int i = 0; i < l; i++)
		if (k & ull(1) << i) res = ll(res) * res1 % mod;
		else res = ll(res) * res0 % mod;
	printf("%d\n", res);
	return 0;
}