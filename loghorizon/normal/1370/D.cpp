#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 200005;

int n, K, a[N], f[N];

bool inline check(int x) {
	if (K % 2 == 0) {
		f[0] = 0;
		f[1] = (a[1] <= x) ? 1 : 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] <= x) f[i] = max(f[i - 1], f[i - 2] + 1);
			else f[i] = f[i - 1];
		}	
		if (f[n - 1] >= (K / 2)) return true;
		f[1] = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] <= x) f[i] = max(f[i - 1], f[i - 2] + 1);
			else f[i] = f[i - 1];
		}	
		return f[n] >= (K / 2);
	} else {
		f[0] = 0;
		f[1] = (a[1] <= x) ? 1 : 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] <= x) f[i] = max(f[i - 1], f[i - 2] + 1);
			else f[i] = f[i - 1];
		}	
		if (f[n] >= (K / 2) + 1) return true;
		f[1] = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] <= x) f[i] = max(f[i - 1], f[i - 2] + 1);
			else f[i] = f[i - 1];
		}	
		return f[n - 1] >= (K / 2);
	}
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}