#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxd = 16;
const int mod = 1000000007;
const int Maxn = 105;

struct matrix {
	int m[Maxd][Maxd];
	matrix(int diag = 0) {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				m[i][j] = diag * (i == j);
	}
	matrix operator*(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				for (int k = 0; k < Maxd; k++)
					c.m[i][j] = (c.m[i][j] + ll(m[i][k]) * b.m[k][j]) % mod;
		return c;
	}
};

int n;
ll k;
vector <int> V;
ll a[Maxn], b[Maxn];
int c[Maxn];

matrix toPower(matrix A, ll p)
{
	matrix R(1);
	while (p) {
		if (p & 1ll) R = R * A;
		p >>= 1ll; A = A * A;
	}
	return R;
}

vector <int> Trans(vector <int> V, int c, ll moves)
{
	for (int i = c + 1; i < Maxd; i++)
		V[i] = 0;
	matrix A;
	for (int i = 0; i <= c; i++) {
		if (i > 0) A.m[i][i - 1] = 1;
		A.m[i][i] = 1;
		if (i + 1 <= c) A.m[i][i + 1] = 1;
	}
	A = toPower(A, moves);
	vector <int> nV(Maxd, 0);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			nV[i] = (nV[i] + ll(A.m[i][j]) * V[j]) % mod;
	return nV;
}

int main()
{
	scanf("%d %I64d", &n, &k);
	V.resize(Maxd);
	for (int i = 0; i < Maxd; i++)
		V[i] = i == 0;
	for (int i = 0; i < n; i++)
		scanf("%I64d %I64d %d", &a[i], &b[i], &c[i]);
	ll cur = 0;
	for (int i = 0; i < n - 1; i++) {
		V = Trans(V, c[i], b[i] - cur);
		cur = b[i];
	}
	V = Trans(V, c[n - 1], k - cur);
	printf("%d\n", V[0]);
	return 0;
}