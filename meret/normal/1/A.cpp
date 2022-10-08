#include <cstdio>

typedef long long LL;

int n, m, a;

int main() {
	scanf("%d %d %d", &n, &m, &a);
	printf("%lld\n", ((n + a - 1) / a) * LL((m + a - 1) / a));
}