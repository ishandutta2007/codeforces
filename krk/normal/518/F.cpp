#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
bool U[Maxn][Maxn], D[Maxn][Maxn], L[Maxn][Maxn], R[Maxn][Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			U[i][j] = (i == 0 || U[i - 1][j]) && B[i][j] == '.';
			L[i][j] = (j == 0 || L[i][j - 1]) && B[i][j] == '.';
		}
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			D[i][j] = (i == n - 1 || D[i + 1][j]) && B[i][j] == '.';
			R[i][j] = (j == m - 1 || R[i][j + 1]) && B[i][j] == '.';
		}

	for (int i = 1; i + 1 < n; i++)
		res += L[i][m - 1];
	for (int j = 1; j + 1 < m; j++)
		res += U[n - 1][j];

	for (int i = 1; i + 1 < n; i++)
		for (int j = 1; j + 1 < m; j++)
			res += int(U[i][j] && L[i][j]) + int(U[i][j] && R[i][j]) + int(D[i][j] && L[i][j]) + int(D[i][j] && R[i][j]);

	for (int i = 1; i + 1 < n; i++) {
		int ft = 0, fb = 0, fts = 0, fbs = 0;
		for (int j = 1; j + 1 < m; j++) {
			if (U[i][j]) res += fb + fts;
			if (D[i][j]) res += ft + fbs;
			if (B[i][j] == '.') {
				ft += U[i][j];
				fb += D[i][j];
				if (j - 1 > 0) { fts += U[i][j - 1]; fbs += D[i][j - 1]; }
			} else ft = fb = fts = fbs = 0;
		}
	}
	for (int j = 1; j + 1 < m; j++) {
		int fl = 0, fr = 0, fls = 0, frs = 0;
		for (int i = 1; i + 1 < n; i++) {
			if (L[i][j]) res += fr + fls;
			if (R[i][j]) res += fl + frs;
			if (B[i][j] == '.') {
				fl += L[i][j];
				fr += R[i][j];
				if (i - 1 > 0) { fls += L[i - 1][j]; frs += R[i - 1][j]; }
			} else fl = fr = fls = frs = 0;
		}
	}

	printf("%I64d\n", res);
	return 0;
}