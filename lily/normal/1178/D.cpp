#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

int n;
bool isprime(int x) {
	if (x == 1) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	read(n);
	for (int i = 0; i <= n / 2; i++) {
		if (isprime(n + i)) {
			printf("%d\n", n + i);
			for (int j = 1; j <= n; j++) {
				printf("%d %d\n", j, j == n ? 1 : j + 1);
			}
			for (int j = 0; j < i; j++) {
				printf("%d %d\n", j + 1, j + 1 + n / 2);
			}
			return 0;
		}
	}
	puts("-1");


}