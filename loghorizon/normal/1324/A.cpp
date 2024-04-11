#include <iostream>
#include <cstdio>

using namespace std;

const int N = 105;

int n, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		int b = a[1] & 1;
		bool ok = true;
		for (int i = 2; i <= n; i++) {
			if ((a[i] & 1) != b) {
				ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}