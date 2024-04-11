#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool done = false;
		for (int i = 0; i < n; i++) {
			if (7 * i > n) break;
			for (int j = 0; j < n; j++) {
				int cur = 7 * i + 5 * j;
				if (cur > n) break;
				if ((n - cur) % 3 == 0) {
					printf("%d %d %d\n", (n - cur) / 3, j, i);
					done = true;
					break;
				}
			}
			if (done) break;
		}
		if (!done) printf("-1\n");
	}
	return 0;
}