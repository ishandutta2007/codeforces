#include <bits/stdc++.h>
using namespace std;

const int N = 107;

int n, k;
int a[N];
double f[2][N][N];

int F(int x) { return x * (x + 1) / 2; }

int main() {
	scanf("%d %d", &n, &k); k = min(k, 1007);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			f[0][i][j] = (a[i] > a[j]);
		}
	}
	int segs = F(n);
	for (int turn = 1; turn <= k; ++turn) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				f[1][i][j] = f[0][i][j] * 1.0 * (F(i - 1) + F(j - i - 1) + F(n - j));
				for (int sum = j + 1; sum <= i + n; ++sum) {
					int from = max(1, sum - n);
					int to = min(i, sum - j);
					f[1][i][j] += (1.0 - f[0][sum - j][sum - i]) * (to - from + 1);
				}
				for (int sum = i + 1; sum <= i + j - 1; ++sum) {
					int from = max(1, sum - j + 1);
					int to = min(i, sum - i);
					f[1][i][j] += f[0][sum - i][j] * (to - from + 1);
				}
				for (int sum = i + j + 1; sum <= j + n; ++sum) {
					int from = max(i + 1, sum - n);
					int to = min(j, sum - j);
					f[1][i][j] += f[0][i][sum - j] * (to - from + 1);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				f[0][i][j] = f[1][i][j] / segs;
				f[1][i][j] = 0.0;
			}
		}
	}
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans += f[0][i][j];
		}
	}
	printf("%.9lf\n", ans);
}