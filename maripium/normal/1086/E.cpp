#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int mod = 998244353;

void add(int& x,int y) {
	x += y; if (x >= mod) x -= mod;
}

void sub(int& x,int y) {
	x -= y; if (x < 0) x += mod;
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int n;
int a[N][N];
int f[N], pw[N];
int f2[N][N];
int fw[2][N];
int cnt[N];
int now;

void reset() {
	for (int i = 1; i <= n; ++i) {
		fw[0][i] = fw[1][i] = 0;
		cnt[i] = 0;
	}
	now = 0;
}

void upd(int t, int p,int v) {
	for (; p <= n; p += p & -p) {
		fw[t][p] += v;
	}
}

int get(int t,int p) {
	int res = 0;
	for (; p > 0; p -= p & -p) {
		res += fw[t][p];
	}
	return res;
}

void add(int x) {
	if (++cnt[x] == 2) {
		++now;
		upd(0, x, 1);
	}
}

int F2(int x,int y) {
	if (x < y || y < 0) {
		return 0;
	} else {
		return f2[x][y];
	}
}

int main() {
	scanf("%d", &n);
	f[1] = 0, f[2] = 1;
	for (int i = 3; i <= n; ++i) {
		f[i] = mul(i - 1, f[i - 1] + f[i - 2]);
	}
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = mul(pw[i - 1], f[n]);
	}
	f2[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		f2[i][0] = mul(f2[i - 1][0], i);
		for (int j = 1; j <= i; ++j) {
			f2[i][j] = f2[i][j - 1];
			sub(f2[i][j], f2[i - 1][j - 1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	{
		for (int i = 1; i <= n; ++i) {
			upd(0, i, 1);
		}
		int coef = pw[n - 1];
		for (int i = 1; i <= n; ++i) {
			upd(0, a[1][i], -1);
			add(ans, mul(F2(n - i, 0), mul(coef, get(0, a[1][i] - 1))));
		}
	}
	for (int i = 2; i <= n; ++i) {
		reset();
		int coef = pw[n - i];
		for (int j = n; j > 0; --j) {
			add(a[i - 1][j]);
			add(a[i][j]);
			upd(1, a[i][j], 1);
			int u = get(0, a[i][j] - 1), v = get(1, a[i][j] - 1) - u;
			add(ans, mul(u, mul(coef, F2(n - j, now - (cnt[a[i - 1][j]] == 2) - 1))));
			add(ans, mul(v, mul(coef, F2(n - j, now - (cnt[a[i - 1][j]] == 2)))));
			if (cnt[a[i - 1][j]] == 2 && a[i - 1][j] < a[i][j]) {
				sub(ans, mul(coef, F2(n - j, now - 2)));
			}
		}
	}
	printf("%d\n", ans);
}