#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int mod = 998244353;

int n, k;
int f[N], g[N], prf[N];

int add(int x,int y) {
	x += y; if (x >= mod) x -= mod;
	return x;
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int l = 1; l <= n; ++l) {
		for (int i = 0; i <= n; ++i) {
			g[i] = 0, prf[i] = 0;
		}
		g[0] = 1;
		prf[1] = 1;
		for (int i = 1; i <= n; ++i) {
			g[i] = add(prf[i], mod - prf[max(i - l, 0)]);
			prf[i + 1] = add(prf[i], g[i]); 
		}
		f[l] = g[n];
	}
	
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = add(res, mul(add(f[i], mod - f[i - 1]), f[min(n, (k - 1) / i)]));
	}
	cout << mul(res, 2) << '\n';
}