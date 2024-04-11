#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
	scanf("%d", &tc);
	int n;
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d", &n);
		if (n == 1) {
			printf("0\n");
			continue;
		}
		int ans = n-1;
		for (int i = max(1, (int)sqrt(n)-10); i <= min(n, (int)sqrt(n)+10); i++) {
			ans = min(ans, i-1 + ((n-1)/i));
		}
		printf("%d\n", ans);
	}
	return 0;
}