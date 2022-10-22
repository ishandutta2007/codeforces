#include <cstdio>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 505;
const ld eps = 1e-12l;
const int Maxk = 102;

struct matrix {
	ld m[Maxk][Maxk];
	matrix(ld diag = 0.0l) {
		for (int i = 0; i < Maxk; i++)
			for (int j = 0; j < Maxk; j++)
				m[i][j] = (i == j) * diag;
	}
	matrix operator *(const matrix &b) const {
		matrix c;
		for (int i = 0; i < Maxk; i++)
			for (int j = 0; j < Maxk; j++)
				for (int l = 0; l < Maxk; l++)
					c.m[i][j] += m[i][l] * b.m[l][j];
		return c;
	}
};

int n, m, k;
int trap[Maxn];
int neigh[Maxn][Maxn], tot[Maxn];
ld A[Maxn][Maxn], INV[Maxn][Maxn];
ld st[Maxn];
matrix TR;
int id, myid[Maxn];

void Swap(ld M[][Maxn], int r1, int r2)
{
	for (int i = 1; i <= n; i++)
		swap(M[r1][i], M[r2][i]);
}

void Add(ld M[][Maxn], int r2, ld mult, int r1)
{
	for (int i = 1; i <= n; i++)
		M[r2][i] += mult * M[r1][i];
}

void Mult(ld M[][Maxn], int r, ld mult)
{
	for (int i = 1; i <= n; i++)
		M[r][i] *= mult;
}

ld Get(ld M[][Maxn], ld cur[], int r)
{
	ld res = 0.0;
	for (int j = 1; j <= n; j++)
		res += M[r][j] * cur[j];
	return res;
}

ld getRes(int p)
{
	matrix R(1), A = TR;
	while (p) {
		if (p & 1) R = R * A;
		p >>= 1; A = A * A;
	}
	ld res = 0.0;
	for (int j = 0; j < id; j++)
		res += R.m[id - 1][j] * st[j];
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &trap[i]);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a][b]++; tot[a]++;
		neigh[b][a]++; tot[b]++;
	}
	for (int i = 1; i <= n; i++) {
		A[i][i] = INV[i][i] = 1.0;
		for (int j = 1; j <= n; j++) if (i != j && !trap[j])
			A[i][j] -= ld(neigh[i][j]) / ld(tot[i]);
	}
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (fabs(A[j][i]) < eps) j++;
		if (j != i) { Swap(A, i, j); Swap(INV, i, j); }
		for (int l = j + 1; l <= n; l++) { 
			ld mult = -A[l][i] / A[i][i];
			Add(A, l, mult, i); Add(INV, l, mult, i); 
		}
	}
	for (int i = n; i > 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			ld tmp = -A[i][j];
			Add(A, i, tmp, j); Add(INV, i, tmp, j);
		}
		ld mult = 1.0 / A[i][i];
		Mult(A, i, mult); Mult(INV, i, mult);
	}

	for (int i = 1; i <= n; i++) if (trap[i])
		myid[i] = id++;
	ld cur[Maxn];
	for (int i = 1; i <= n; i++) if (trap[i]) {
		for (int j = 1; j <= n; j++)
			cur[j] = ld(neigh[j][i]) / ld(tot[j]);
		st[myid[i]] = Get(INV, cur, 1);
		for (int j = 1; j <= n; j++) if (trap[j])
			TR.m[myid[i]][myid[j]] = Get(INV, cur, j);
	}
	cout << fixed << setprecision(8) << getRes(k - 2) << endl;
	return 0;
}