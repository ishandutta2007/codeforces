#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int _n,n,a[maxn],c[maxn];

int binary_search(int st, int lim) {
	int l = st, r = n, mid, ans = st - 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (c[mid] - c[st - 1] <= lim) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

void work() {
	scanf("%d", &_n);
	for (int i = 1; i <= _n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + _n + 1);
	n = 0;
	for (int i = 1; i <= _n; ++i)
		if (!n || a[i] != a[n]) a[++n] = a[i], c[n] = 1 + c[n - 1];
		else ++c[n];
	// for (int i = 1; i <= n; ++i) printf("%d %d\n", a[i], c[i]);
	int ans = 1e9;
	for (int x = 0; x < 20; ++x) {
		int px = binary_search(1, 1 << x);
		for (int y = 0; y < 20; ++y) {
			int py = binary_search(px + 1, 1 << y);
			int z = 0;
			while (c[n] - c[py] > (1 << z)) ++z;
			ans = min(ans, (1 << x) + (1 << y) + (1 << z) - _n);
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}