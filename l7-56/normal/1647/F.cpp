#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 5e5 + 10;
int n, pos = 1,a[maxn],f[maxn],g[maxn],h[2][maxn];

int calc() {
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	memset(h[0], 0x3f, sizeof h[0]);
	memset(h[1], 0xaf, sizeof h[1]);
	f[1] = 0;
	for (int i = 2; i <= pos; ++i) {
		if (f[i - 1] < a[i]) f[i] = min(f[i], a[i - 1]);
		if (a[i - 1] < a[i]) f[i] = min(f[i], f[i - 1]);
	}
	g[n] = 0;
	for (int i = n - 1; i >= pos; --i) {
		if (g[i + 1] < a[i]) g[i] = min(g[i], a[i + 1]);
		if (a[i + 1] < a[i]) g[i] = min(g[i], g[i + 1]);
	}
	int res = 0;
	h[0][pos] = f[pos];
	for (int i = pos + 1; i <= n; ++i) {
		if (a[i] < a[i - 1]) h[0][i] = min(h[0][i], h[0][i - 1]);
		if (a[i] < h[1][i - 1]) h[0][i] = min(h[0][i], a[i - 1]);
		if (a[i] > a[i - 1]) h[1][i] = max(h[1][i], h[1][i - 1]);
		if (a[i] > h[0][i - 1]) h[1][i] = max(h[1][i], a[i - 1]);
		res += (h[1][i] > g[i]);
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > a[pos]) pos = i;
	}
	int res = calc();
	reverse(a + 1, a + n + 1), pos = n - pos + 1;
	res += calc();
	printf("%d\n", res);
	return 0;
}