#include <cstdio>

using namespace std;

int n;
int a[105];
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		ans += 1 + (long long) (i + 1) * (a[i] - 1);
	printf("%lld\n", ans);
	return 0;
}