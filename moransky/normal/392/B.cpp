#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 45;

typedef long long LL;

int t[3][3], g[3][3], n;
LL f[N][3][3];


int main() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) scanf("%d", &t[i][j]), g[i][j] = t[i][j];
	scanf("%d", &n);
	for (int k = 0; k < 3; k++)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			f[1][i][j] = t[i][j];

	for (int i = 2; i <= n; i++) {
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				if (a == b) continue;
				int c = 3 - a - b;
				f[i][a][b] = min(f[i - 1][a][c] + g[a][b] + f[i - 1][c][b], f[i - 1][a][b] + g[a][c] + f[i - 1][b][a] + g[c][b] + f[i - 1][a][b]);
			}
		}
	}
	printf("%lld\n", f[n][0][2]);
	return 0;
}