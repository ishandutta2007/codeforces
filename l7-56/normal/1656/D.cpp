#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll n;
void work() {
	scanf("%lld", &n);
	if (n == (n & (-n))) return printf("-1\n"), void();
	ll k = (n & (-n)) << 1;
	printf("%lld\n", min(k, n * 2 / k));
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}