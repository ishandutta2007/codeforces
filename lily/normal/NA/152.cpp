#include <bits/stdc++.h>
using namespace std;

#define N 1005

int n;
int a[N], b[N][N];
pair<int, int> c[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) c[i] = {a[i], i};
	sort(c + 1, c + n + 1);
//	reverse(c + 1, c + n + 1);
	memset(b, -1, sizeof b);
	for (int i = 1; i <= n; i++) {
		a[c[i].second]--;
		b[i][c[i].second] = 1;
		b[i + 1][c[i].second] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; a[c[i].second] && j <= n + 1; j++) {
			if (b[j][c[i].second] == -1) b[j][c[i].second] = 1, a[c[i].second]--;
		}
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++) flag |= b[n + 1][i] == 1;
	printf("%d\n", n + flag);
	for (int i = 1; i <= n + flag; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", max(0, b[i][j]));
		}
		puts("");
	}
}