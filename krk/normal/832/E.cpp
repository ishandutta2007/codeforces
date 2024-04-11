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

const int Mod = 1000000007;
const int Maxn = 505;
const int mod = 5;

int n, m;
char str[Maxn];
int B[Maxn][Maxn], C[Maxn][Maxn];
int tk[mod][mod];
int inrow[Maxn];
int spec;
int res;
int q;
char cur[Maxn];
int vals[Maxn];

void Swap(int r1, int r2)
{
	for (int i = 0; i < n; i++)
		swap(B[r1][i], B[r2][i]);
	for (int i = 0; i < m; i++)
		swap(C[r1][i], C[r2][i]);
}

void Eliminate(int r1, int r2, int mult)
{
	for (int i = 0; i < n; i++)
		B[r2][i] = (B[r2][i] - mult * B[r1][i] % mod + mod) % mod;
	for (int i = 0; i < m; i++)
		C[r2][i] = (C[r2][i] - mult * C[r1][i] % mod + mod) % mod;
}

bool Check()
{
	for (int i = 0; i < m; i++)
		vals[i] = cur[i] - 'a';
	for (int i = 0; i < m; i++) if (inrow[i] == -1) {
		int got = 0;
		for (int j = 0; j < m; j++)
			got = (got + vals[j] * C[i][j]) % mod;
		if (got) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0; j < m; j++)
			B[j][i] = str[j] - 'a';
	}
	for (int i = 0; i < m; i++)
		C[i][i] = 1;
	for (int i = 1; i < mod; i++)
		for (int j = 1; j < mod; j++)
			tk[i][i * j % mod] = j;
	fill(inrow, inrow + m, -1);
	int r = 0, c = 0;
	while (r < m && c < n) {
		int rw = r;
		while (rw < m && B[rw][c] == 0) rw++;
		if (rw == m) { spec++; c++; }
		else {
			if (r != rw) Swap(r, rw);
			for (int j = r + 1; j < m; j++)
				if (B[j][c]) Eliminate(r, j, tk[B[r][c]][B[j][c]]);
			inrow[r] = c;
			r++; c++;
		}
	}
	spec += n - c;
	res = 1;
	while (spec--) res = ll(res) * 5 % Mod;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", cur);
		printf("%d\n", Check()? res: 0);
	}
	return 0;
}