#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, a[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) scanf("%d", a + i);
		sort(a + 1, a + 1 + 2 * n);
		printf("%d\n", a[n + 1] - a[n]);
	}
	return 0;
}