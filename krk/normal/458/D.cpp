#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxm = 100005;
const int Maxn = 305;
const int nil = 615;
const int Maxp = nil * 2 + 5;

int n, m, k;
ld C[Maxn][Maxn];
ld f[Maxm];
ld sub[Maxn][Maxn], prob[Maxn][Maxn];
ld res;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1.0l;
		for (int j = 0; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	f[0] = 1.0l;
	for (int X = 1; X <= k; X++)
		f[X] = f[X - 1] * (ld(k - X + 1) / (m - X + 1));
	for (int r = 0; r <= n; r++)
		for (int c = 0; c <= n; c++) {
			int X = n * n - (n - r) * (n - c);
			if (X <= k) {
				res += C[n][r] * f[X] * C[n][c];
			} else prob[r][c] = 0;
		}
	if (res < 1e99) cout << fixed << setprecision(17) << res << endl;
	else printf("1e99\n");
	return 0;
}