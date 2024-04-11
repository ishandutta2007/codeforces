#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int x, y, a, b; scanf("%d%d%d%d", &x, &y, &a, &b);
		printf("%lld\n", min((LL)min(x, y) * b, (LL)min(x, y) * 2 * a) + (LL)abs(x - y) * a);
	}
	return 0;
}