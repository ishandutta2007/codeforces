#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2005;
int n, m, a[N], b[N], c[N];
bool check() {
	for (int i = 1; i <= n; i++) if(c[i] != b[i]) return false;
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	sort(b + 1, b + 1 + n);
	int ans = 2e9;
	for (int i = 1; i <= n; i++) {
		int t = (b[i] + m - a[1]) % m;
		for (int j = 1; j <= n; j++) c[j] = (a[j] + t) % m;
		sort(c + 1, c + 1 + n);
		if(check()) ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}