#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1010;
int a[maxn][maxn],n,b[maxn][maxn];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;
void click(int x, int y) {
	for (int k = 0; k < 4; ++k)
		b[x + dx[k]][y + dy[k]] ^= 1;
	ans ^= a[x][y];
}

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]), b[i][j] = 0;
	ans = 0;
	for (int j = 1; j < n; j += 4)
		click(1, j), click(1, j + 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (!b[i - 1][j]) {
				if (j < n && !b[i - 1][j + 1]) click(i, j), click(i, j + 1);
				else click(i, j), click(i + 1, j);
			}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}