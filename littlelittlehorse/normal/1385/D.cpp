#include <bits/stdc++.h>

using namespace std;

int test, n;
char s[200001];

int solve(int l, int r, int k) {
	if (l == r) {
		if (s[l] == k)
			return 0;
		return 1;
	}
	int m = (l + r) / 2;
	int x = solve(l, m, k + 1);
	for (int i = m + 1; i <= r; i++)
		if (s[i] != k)
			++x;
	int y = solve(m + 1, r, k + 1);
	for (int i = l; i <= m; i++)
		if (s[i] != k)
			++y;
	return min(x, y);
}

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d%s", &n, s + 1);
		printf("%d\n", solve(1, n, 'a'));
	}
}