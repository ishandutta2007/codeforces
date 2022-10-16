#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1) {
		puts("0");
		return 0;
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d\n", i + 1);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", i * (n + j));
		}
		puts("");
	}
	return 0;
}