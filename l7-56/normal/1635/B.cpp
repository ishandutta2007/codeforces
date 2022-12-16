#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10, inf = 1e9 + 10;
int n,a[maxn],f[maxn];
void work() {
	scanf("%d", &n);
	a[0] = a[n + 1] = inf;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) f[i] = (a[i] > a[i - 1] && a[i] > a[i + 1]);
	int ans = 0;
	for (int i = 2; i < n; ++i)
		if (f[i - 1] && f[i + 1]) {
			a[i] = max(a[i - 1], a[i + 1]);
			f[i - 1] = f[i + 1] = 0;
			ans++;
		}
	for (int i = 2; i < n; ++i)
		if (f[i]) {
			a[i] = max(a[i - 1], a[i + 1]);
			f[i] = 0;
			ans++;
		}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}