#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, k;
int x[N], y[N];
int f[N][2];

int calc(int remX,int remY, int addX,int addY) {
	int ret = k + 1;
	if (remX <= k) {
		int L = (addY + k - 1) / k;
		long long R = 1LL * addY * k + k - remX;
		if (L <= addX && addX <= R) {
			ret = min(1LL * ret, max(1LL, k - R + addX));
		}
	}
	if (remY <= k) {
		long long RY = 1LL * (addX - 1) * k + k - remY;
		long long RX = 1LL * (addY + 1) * k;
		if (addY <= RY && addX <= RX) {
			ret = min(1LL * ret, max(1LL, k - RX + addX));
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", x + i);
	for (int i = 1; i <= n; ++i) scanf("%d", y + i);
	for (int i = 1; i <= n; ++i) {
		f[i][0] = calc(f[i - 1][0], f[i - 1][1], x[i], y[i]);
		f[i][1] = calc(f[i - 1][1], f[i - 1][0], y[i], x[i]);
	}	
	printf((f[n][0] <= k || f[n][1] <= k) ? "YES" : "NO");
}