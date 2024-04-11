#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, x, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		bool o = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == x) {
				o = 1;
			}
		}
		if (o) puts("1");
		else {
			sort(a + 1, a + 1 + n);
			if (a[n] > x) puts("2");
			else {
				printf("%d\n", (x + a[n] - 1) / a[n]);
			}
		}
	}
	return 0;
}