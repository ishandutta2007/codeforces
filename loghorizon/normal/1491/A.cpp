// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, a[N], m;

int main() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == 1) cnt++;
	}
	while (m--) {
		int op, x; scanf("%d%d", &op, &x);
		if (op == 1) {
			a[x] ^= 1;
			if (a[x] == 1) cnt++;
			else cnt--;
		} else {
			printf("%d\n", x <= cnt ? 1 : 0);
		}
	}
	return 0;
}