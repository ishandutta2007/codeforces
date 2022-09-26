#include <bits/stdc++.h>
using namespace std;

const int MAGIC = 12345;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d", &x);
		int len = __lg(x) + 1;
		if (x + 1 == (1 << len)) {
			int ans = 1;
			for (int i = 2; i < MAGIC; ++i) {
				if (x % i == 0) {
					ans = max(ans, x / i);
				}
			}
			printf("%d\n", ans);
		} else {
			printf("%d\n", (1 << len) - 1);
		}
	}
}