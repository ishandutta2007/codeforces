#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
const int mod = 1e9 + 7;

void add(int &x,int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

void sub(int &x,int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int f[N], a[N], b[N], c[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++a[x];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i; j > 0; j = (j - 1) & i) {
			add(b[i], mul(a[j], a[i ^ j]));
		}
		add(b[i], mul(a[0], a[i]));
	}
	for (int i = 0; i < N; ++i) {
		c[i] = a[i];
	}
	for (int i = 1; i < N; i <<= 1) {
		for (int j = 0; j < N; j += i << 1) {
			for (int k = 0; k < i; ++k) {
				int u = c[j + k], v = c[i + j + k];
				c[j + k] = u;
				add(c[j + k], v);
				c[i + j + k] = u;
				sub(c[i + j + k], v);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		c[i] = mul(c[i], c[i]);
	}
	for (int i = 1; i < N; i <<= 1) {
		for (int j = 0; j < N; j += i << 1) {
			for (int k = 0; k < i; ++k) {
				int u = c[j + k], v = c[i + j + k];
				c[j + k] = u;
				add(c[j + k], v);
				c[i + j + k] = u;
				sub(c[i + j + k], v);
			}
		}
	}
	int inv = 1;
	for (int i = 0; i < 17; ++i) {
		inv = mul(inv, mod + 1 >> 1);
	}
	for (int i = 0; i < N; ++i) {
		c[i] = mul(c[i], inv);
	}
	f[1] = 1;
	for (int i = 2; i < N; ++i) {
		f[i] = f[i - 1];
		add(f[i], f[i - 2]);
	}
	for (int i = 0; i < N; ++i) {
		a[i] = mul(a[i], f[i]);
		b[i] = mul(b[i], f[i]);
		c[i] = mul(c[i], f[i]);
	}
	for (int i = 1; i < N; i <<= 1) {
		for (int j = 0; j < N; j += i << 1) {
			for (int k = 0; k < i; ++k) {
				add(a[j + k], a[i + j + k]);
				add(b[j + k], b[i + j + k]);
				add(c[j + k], c[i + j + k]);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		a[i] = mul(a[i], mul(b[i], c[i]));
	}
	for (int i = 1; i < N; i <<= 1) {
		for (int j = 0; j < N; j += i << 1) {
			for (int k = 0; k < i; ++k) {
				sub(a[j + k], a[i + j + k]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 17; ++i) {
		add(ans, a[1 << i]);
	}
	printf("%d\n", ans);
}