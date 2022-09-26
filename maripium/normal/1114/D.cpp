#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
bool in[5005][5005];
int f[5005][5005];
int m, b[5005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	int l = 1;
	while (l <= n) {
		b[++m] = a[l];
		int r = l;
		while (r + 1 <= n && a[r + 1] == a[l]) {
			++r;
		}
		l = r + 1;
	}
	for (int l = m; l > 0; --l) {
		for (int r = l; r <= m; ++r) {
			if (l == r) {
				f[l][r] = 0;
			}
			else if (b[l] == b[r]) {
				f[l][r] = f[l + 1][r - 1] + 1;
			} else {
				f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;
			}
		}
	}
	printf("%d\n", f[1][m]);
}