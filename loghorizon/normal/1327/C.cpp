#include <cstdio>
#include <iostream>

using namespace std;

const int N = 205;

int n, m, K, sx[N], sy[N], tx[N], ty[N], tot;

char ans[N * N];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= K; i++)
		scanf("%d%d", sx + i, sy + i);
	for (int i = 1; i <= K; i++)
		scanf("%d%d", tx + i, ty + i);
	for (int i = 1; i < n; i++) ans[++tot] = 'U';
	for (int j = 1; j < m; j++) ans[++tot] = 'L';
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j < m; j++) ans[++tot] = 'R';
			if (i < n) ans[++tot] = 'D';
		} else {
			for (int j = 1; j < m; j++) ans[++tot] = 'L';
			if (i < n) ans[++tot] = 'D';
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) putchar(ans[i]);
	return 0;
}