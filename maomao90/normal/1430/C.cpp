#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("2\n");
		if (n == 2) {
			printf("1 2\n");
			continue;
		}
		printf("%d %d\n", n, n - 2);
		printf("%d %d\n", n - 1, n - 1);
		for (int i = n - 3; i > 0; i--) {
			printf("%d %d\n", i, i + 2);
		}
	}
	return 0;
}