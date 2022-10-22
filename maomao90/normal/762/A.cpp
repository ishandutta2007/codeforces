#include <cstdio>

using namespace std;

long long n;
int k;
int cnt;

int main() {
	scanf("%lld", &n);
	scanf("%d", &k);
	long long i = 1;
	for (; i * i <= n; i++) {
		if (n % i == 0) cnt++;
		if (cnt == k) {
			printf("%lld\n", i);
			return 0;
		}
	}
	i--;
	for (; i >= 1; i--) {
		if (n % i == 0 && i * i != n) cnt++;
		if (cnt == k) {
			printf("%lld\n", n / i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}