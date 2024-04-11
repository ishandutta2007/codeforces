#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
	}
	printf("%d\n", 3 * n);
	for (int i = 1; i <= n; i += 2) {
		int j = i + 1;
		printf("1 %d %d\n", i, j);
		printf("2 %d %d\n", i, j);
		printf("1 %d %d\n", i, j);
		printf("2 %d %d\n", i, j);
		printf("1 %d %d\n", i, j);
		printf("2 %d %d\n", i, j);
	}
	}

}