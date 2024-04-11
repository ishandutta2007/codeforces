#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int mod = 1000000007;

struct matrix {
	int m[Maxn][Maxn];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxn; i++)
			for (int j = 0; j < Maxn; j++)
				m[i][j] = (i == j) * diag;
	}
	matrix operator*(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxn; i++)
			for (int j = 0; j < Maxn; j++)
				for (int l = 0; l < Maxn; l++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][l]) * b.m[l][j]) % mod;
		return c;
	}
};

int n;
ll k;
ll a[Maxn];

int main()
{
	scanf("%d %I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	matrix R(1), A;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) A.m[i][j] = 1;
	k--;
	while (k) {
		if (k & 1ll) R = R * A;
		k >>= 1ll; A = A * A;
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res = (res + R.m[i][j]) % mod;
	printf("%d\n", res);
	return 0;
}