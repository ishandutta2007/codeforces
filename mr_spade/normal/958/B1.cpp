#include <cstdio>

const int N = 100005;

int n, cnt, dg[N];

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; ++i) scanf("%d%d", &x, &y), ++dg[x], ++dg[y];
	for (int i = 1; i <= n; ++i) if (dg[i] == 1) ++cnt;
	printf("%d\n", cnt);
	
	return 0;
}