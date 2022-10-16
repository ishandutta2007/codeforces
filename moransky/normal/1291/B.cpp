#include <cstdio>
#include <iostream>
using namespace std;
const int N = 300005;
int n, a[N];
bool L[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i), L[i] = false;
		for (int i = 1; i <= n; i++) 
			if (a[i] >= i - 1) L[i] = true;
		for (int i = 2; i <= n; i++) L[i] &= L[i - 1];
		bool ok = false;
		for (int i = n; i; i--) {
			if (a[i] < n - i) break;
			if (L[i]) { ok = true; break; }
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}