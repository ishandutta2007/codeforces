#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, k, a[N], c[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%1d", a + i), c[i] = a[i];
	bool f = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] != a[i % k]) f = 0;
	}
	if (f) {
		printf("%d\n", n);
		for (int i = 0; i < n; i++) printf("%d", a[i]);
		return 0;
	}
	int p = -1;
	for (int i = k; i < n; i++) {
		if (a[i] < a[i % k]) {
			p = i;
		}
		if (a[i] != a[i % k]) break;
	}
	printf("%d\n", n);
	if (p == -1) {
		for (int i = k - 1; ~i; i--) {
			if (c[i] < 9) {
				c[i]++;
				for (int j = i + 1; j < k; j++) c[j] = 0;
				break;
			}
		}
		for (int i = 0; i < n; i++) printf("%d", c[i % k]);
	} else {
		for (int i = 0; i < n; i++) printf("%d", c[i % k]);
	}
	return 0;
}