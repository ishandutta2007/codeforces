#include <cstdio>
#include <iostream>
using namespace std;
int x, y, a, b;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		int p = y - x;
		if (p % (a + b)) puts("-1");
		else printf("%d\n", p / (a + b));
	}
	return 0;
}