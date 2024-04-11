#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int md = 1e9 + 7;

int fact[N * 2], inv[N * 2], pw2[N];
int d[N];
vector<int> dvs[N];
int q;

int pw(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1) res = 1LL * res * a % md; a = 1LL * a * a % md;
		b >>= 1;
	}
	return res;
}

int C(int n, int k) {
	if (n == k) return 1;
	if (n < 0 || k < 0 || n < k) return 0;
	return 1LL * fact[n] * (1LL * inv[k] * inv[n-k] % md) % md;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1; for (int i = 1; i < N * 2; ++i) fact[i] = 1LL * fact[i-1] * i % md;
	for (int i = 0; i < N * 2; ++i) inv[i] = pw(fact[i], md - 2);
	pw2[0] = 1; for (int i = 1; i < N; ++i) pw2[i] = 2LL * pw2[i-1] % md;

	d[0] = d[1] = 1;
	for (int i = 2; i < N; ++i) if (!d[i]) {
		for (int j = i; j < N; j += i) d[j] = i;
	}
	
	dvs[1].push_back(0);
	for (int i = 2; i < N; ++i) {
		int tmp = i;
		while(tmp > 1) {
			int dv = d[tmp], cnt = 0; 
			while(tmp % dv == 0) tmp /= dv, ++cnt;
			dvs[i].push_back(cnt);
		}
	}
	
	cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;
		int res = pw2[y - 1];
		for (auto p : dvs[x]) {
			res = 1LL * res * C(p + y - 1, y - 1) % md;
		}
		printf("%d\n", res);
	}
}