#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, r, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &r, &c);
		int ans = r + c - 2;
		ans = max(ans, n - r + m - c);
		ans = max(ans, r - 1 + m - c);
		ans = max(ans, n - r + c - 1);
		printf("%d\n", ans);
	}
	return 0;
}