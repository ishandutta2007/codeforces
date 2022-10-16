#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL n, a, b, t;
bool check(LL x) {
	LL g = x / (a + b) * a;
	LL o = x % (a + b);
	g += min(a, o);
	if (g >= t && x >= n) return true;
	return false;
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &n, &a, &b);
		t = n % 2 ? n / 2 + 1 : n / 2;
		LL l = 0, r = n * (a + b);
		while (l < r) {
			LL mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%lld\n", r);
	}
}