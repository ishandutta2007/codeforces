#include <cstdio>
#include <iostream>

using namespace std;

const int N = 300005;

typedef long long LL;

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	LL c0 = 0, c1 = 0;
	for (int i = 1; i <= n; i++) {
		c0 += a[i] / 2, c1 += a[i] / 2;
		if (a[i] & 1) {
			if (i & 1) c0++;
			else c1++;
		}
	}
	printf("%lld\n", min(c0, c1));
	return 0;
}