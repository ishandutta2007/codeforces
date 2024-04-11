#include <bits/stdc++.h>
using namespace std;

#define INF 1000000005

int n;
int a[100005];
int ans = INF;

int xr[100005];
int rangeXor(int l, int r) {
	if (l == 0) return xr[r];
	else return xr[r] ^ xr[l - 1];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	if (n >= 103) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		xr[i] = a[i];
		if (i != 0) xr[i] ^= xr[i - 1];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			for (int k = i; k < n; k++) {
				if (rangeXor(j, i - 1) > rangeXor(i, k)) {
					ans = min(ans, k - j - 1);
				}
			}
		}
	}
	if (ans == INF) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}