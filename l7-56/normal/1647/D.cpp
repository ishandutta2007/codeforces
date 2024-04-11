#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

bool isprime(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return 0;
	return 1;
}

void work() {
	int x, d; scanf("%d%d", &x, &d);
	int k = 0;
	while (x % d == 0) x /= d, k++;
	if (k == 1) return printf("NO\n"), void();
	if (!isprime(x)) return printf("YES\n"), void();
	if (!isprime(d)) {
		if (k > 3) printf("YES\n");
		else if (x == 1) {
			if (k >= 3) printf("YES\n");
			else printf("NO\n");
		}
		else if (k == 3) {
			if (d != x * x) printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
		return;
	}
	printf("NO\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}