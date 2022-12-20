#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int ask(int w) {
	if (w < 1) return 0;
	printf("? %d\n", w);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

int n;

int main() {
	scanf("%d", &n);
	int l = 1, r = 1e8, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (ask(mid) == 1) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	for (int i = 1; i <= n; ++i) {
		int w = (ans - 1) / i, h = ask(w);
		if (h) ans = min(ans, h * w);
	}
	printf("! %d\n", ans), fflush(stdout);
	return 0;
}