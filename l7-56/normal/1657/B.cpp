#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n,b,x,y;
void work() {
	scanf("%d%d%d%d", &n, &b, &x, &y);
	ll ans = 0;
	for (int i = 1, a = 0; i <= n; ++i) {
		if (a + x <= b) a += x;
		else a -= y;
		ans += a;
	}
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}