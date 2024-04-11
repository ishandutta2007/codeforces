#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int f[2005];
int ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &f[i]);
	sort(f, f + n);

	for (int i = n - 1; i >= 0; i -= k) ans += (f[i] - 1) * 2;
	printf("%d\n", ans);
	return 0;
}