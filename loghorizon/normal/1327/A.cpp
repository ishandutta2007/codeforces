#include <iostream>
#include <cstdio>

using namespace std;

int n, K;

typedef long long LL;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		if ((n & 1) != (K & 1)) puts("NO");
		else {
			puts((LL)(1 + 2 * K - 1) * K / 2 <= n ? "YES" : "NO");
		}
	}
	return 0;
}