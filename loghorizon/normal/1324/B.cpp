#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5005;

int n, a[N], L[N], R[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) L[i] = R[i] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) {
			if (!L[a[i]]) L[a[i]] = i;
			R[a[i]] = i;
		}
		bool ok = false;
		for (int i = 1; i <= n; i++) {
			if (R[i] - L[i] >= 2) {
				ok = true;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}