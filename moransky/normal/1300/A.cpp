#include <cstdio>
#include <iostream>
using namespace std;
const int N = 105;
int n, a[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ans = 0, s = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			s += a[i];
			if (a[i] == 0) s++, ans++;
		}
		if (s == 0) ans++;
		printf("%d\n", ans);
	}
	return 0;
}