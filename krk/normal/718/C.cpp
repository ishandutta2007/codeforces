#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxd = 2;
const int mod = 1000000007;
const int Maxn = 100005;
const int Maxm = 524288;

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
	matrix operator+(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				c.m[i][j] = (m[i][j] + b.m[i][j]) % mod;
		return c;
	}
	bool One() const {
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++)
				if (m[i][j] != bool(i == j)) return false;
		return true;
	}
};

int n, m;
int a[Maxn];
matrix st[Maxm], flag[Maxm];

matrix toPower(int p)
{
	matrix R(1), A;
	A.m[0][0] = A.m[0][1] = A.m[1][0] = 1;
	while (p) {
		if (p & 1) R = R * A;
		p >>= 1; A = A * A;
	}
	return R;
}

void downOn(int v, const matrix &b)
{
	st[v] = st[v] * b; flag[v] = flag[v] * b;
}

void Down(int v)
{
	if (!flag[v].One()) {
		downOn(2 * v, flag[v]); downOn(2 * v + 1, flag[v]);
		flag[v] = matrix(1);
	}
}

void Union(int v)
{
	st[v] = st[2 * v] + st[2 * v + 1];
}

void Create(int v, int l, int r)
{
	flag[v] = matrix(1);
	if (l == r) st[v] = toPower(a[l]);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Update(int v, int l, int r, int a, int b, const matrix &M)
{
	if (l == a && r == b) downOn(v, M);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), M);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, M);
		Union(v);
	}
}

matrix Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		Down(v);
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Get(2 * v, l, m, a, m) + Get(2 * v + 1, m + 1, r, m + 1, b);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	while (m--) {
		int typ, l, r; scanf("%d %d %d", &typ, &l, &r);
		if (typ == 1) {
			int x; scanf("%d", &x);
			Update(1, 1, n, l, r, toPower(x));
		} else {
			matrix R = Get(1, 1, n, l, r);
			printf("%d\n", R.m[0][1]);
		}
	}
	return 0;
}