#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, m, k;
int B[Maxn][Maxn], tmp[Maxn][Maxn];
ll diag[Maxn][Maxn], col[Maxn][Maxn], wcol[Maxn][Maxn];
ll trian[Maxn][Maxn];
ll cur[Maxn][Maxn];
ll res[Maxn][Maxn];
ll best = -1ll;
int a, b;

void Rotate()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[m - 1 - j][i] = B[i][j];
	swap(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			B[i][j] = tmp[i][j];
}

void Solve(int k)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			diag[i][j] = col[i][j] = wcol[i][j] = trian[i][j] = cur[i][j] = 0ll;
	if (k <= 0) return;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			diag[i][j] = B[i][j];
			if (i && j + 1 < m) diag[i][j] += diag[i - 1][j + 1];
			if (i - k >= 0 && j + k < m) diag[i][j] -= B[i - k][j + k];
			col[i][j] = B[i][j];
			if (i) col[i][j] += col[i - 1][j];
			if (i - k >= 0) col[i][j] -= B[i - k][j];
			wcol[i][j] = ll(k) * ll(B[i][j]);
			if (i) wcol[i][j] += wcol[i - 1][j] - col[i - 1][j];
		}
	for (int i = 0; i <= k - 1; i++)
		for (int j = 0; j <= k - 1; j++) {
			int dist = abs(k - 1 - i) + abs(k - 1 - j);
			if (dist < k) {
				trian[k - 1][k - 1] += B[i][j];
				cur[k - 1][k - 1] += ll(k - dist) * ll(B[i][j]);
			}
		}
	for (int i = k - 1; i < n; i++) {
		if (i != k - 1) {
			for (int j = 0; j <= k - 1; j++) { trian[i][k - 1] += B[i][j]; cur[i][k - 1] += ll(j + 1) * ll(B[i][j]); }
			trian[i][k - 1] += trian[i - 1][k - 1] - diag[i - 1][0];
			cur[i][k - 1] += cur[i - 1][k - 1] - trian[i - 1][k - 1];
		}
		for (int j = k; j < m; j++) {
			trian[i][j] = trian[i][j - 1] - diag[i][j - k] + col[i][j];
			cur[i][j] = cur[i][j - 1] - trian[i][j - 1] + wcol[i][j]; 
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	Solve(k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] += cur[i][j];
	Rotate();
	Solve(k - 1);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (n - 1 - j - 1 >= 0) res[i][j] += cur[n - 1 - j - 1][i];
	Rotate();
	Solve(k - 2);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (n - 1 - i - 1 >= 0 && m - 1 - j - 1 >= 0) res[i][j] += cur[n - 1 - i - 1][m - 1 - j - 1];
	Rotate();
	Solve(k - 1);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (m - 1 - i - 1 >= 0) res[i][j] += cur[j][m - 1 - i - 1];
	swap(n, m);
	for (int i = k - 1; i <= n - k; i++)
		for (int j = k - 1; j <= m - k; j++)
			if (res[i][j] > best) { best = res[i][j]; a = i + 1; b = j + 1; }
	printf("%d %d\n", a, b);
	return 0;
}