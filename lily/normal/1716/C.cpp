#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
const int N = 2e5 + 5;
int n, a[2][N], b[2][N], c[2][N];

int ans;
void goright(int t, int x, int y, int other) {
	ans = min(ans, t + (n - 1 - y) * 2 + (!other) + max(0, x == 0 ? b[1][y + other] - (t - y) : c[0][y + other] - (t - y)));
}

void work() {
	read(n);
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < n; j++) {
			scanf("%d", a[i] + j);
			if (a[i][j] != 0) a[i][j] ++;
		}
	int last = 0;
	for (int j = 0; j < n; j++) {
		b[0][j] = max(last, a[0][j] - j);
		last = b[0][j];
	}
	for (int j = n - 1; j >= 0; j--) {
		b[1][j] = max(last, a[1][j] - (n - j) - (n - 1));
		last = b[1][j];
	}
	last = 0;
	for (int j = 0; j < n; j++) {
		c[1][j] = max(last, a[1][j] - j);
		last = c[1][j];
	}
	for (int j = n - 1; j >= 0; j--) {
		c[0][j] = max(last, a[0][j] - (n - j) - (n - 1));
		last = c[0][j];
	}
	ans = 0x7fffffff;
	int x = 0, t = 0;
	for (int y = 0; y < n; y++) {
		goright(t, x, y, 0);
		t ++;
		x ^= 1;
		t = max(t, a[x][y]);
		goright(t, x, y, 1);
		t++;
		t = max(t, a[x][y + 1]);
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}