#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 105;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) {
			if (i & 1) printf("%d ", abs(a[i]));
			else printf("%d ", -abs(a[i]));
		}
		puts("");
	}
	return 0;
}