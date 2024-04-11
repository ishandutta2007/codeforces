#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n == 1) puts("FastestFinger");
		else if (n & 1) puts("Ashishgup");
		else if (n == 2) puts("Ashishgup");
		else {
			int c0 = 1, c1 = 0;
			for (int i = 2; i * i <= n; i++) {
				while (n % i == 0) {
					if (i & 1) c1++;
					else c0 *= i;
					n /= i;
				}
			}
			if (n > 1) {
				if (n & 1) c1++;
				else c0 *= n;
			}
			if (c0 == 2) {
				if (c1 == 1) puts("FastestFinger");
				else puts("Ashishgup");
			} else {
				if (c1 > 0) puts("Ashishgup");
				else puts("FastestFinger");
			}
		}
	}
	return 0;
}