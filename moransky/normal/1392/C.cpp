// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); 
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		LL q = 0;
		for (int i = 2; i <= n; i++) {
			int t = a[i] - a[i - 1];
			if (t < 0) q += -t;
		}
		printf("%lld\n", q);
	}
	return 0;
}