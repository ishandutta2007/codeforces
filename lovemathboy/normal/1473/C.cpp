#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 1; i < k - (n - k); i++) {
			printf("%d ", i);
		}
		for (int i = k; i >= k - (n - k); i--) {
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}