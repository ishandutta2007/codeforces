#include <cstdio>

using namespace std;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	if (n < 1 + k * 2) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", n * k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			printf("%d %d\n", i, (i + j - 1) % n + 1);
		}
	}
	return 0;
}