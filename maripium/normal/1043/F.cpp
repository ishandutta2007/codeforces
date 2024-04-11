#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int mod = 1e9 + 7;

int n;
int cnt[N];
int f[N];
int fac[N], ifac[N];
vector<int> dvs[N];

void add(int &x,int y) {
	x += y; if (x >= mod) x -= mod;
}

int mul(int x,int y) {
	return 1LL * x * y % mod;
}

int pw(int x,int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = mul(ret, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ret;
}

int C(int n,int k) {
	if (n < k || k < 0) return 0;
	return mul(fac[n], mul(ifac[k], ifac[n - k]));
}

int main() {
	ios_base::sync_with_stdio(false);
	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) dvs[j].push_back(i);
	}
	cin >> n;
	int g = 0;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		g = __gcd(g, x);
		for (int v : dvs[x]) cnt[v]++;
	}
	if (g > 1) {
 		cout << -1 << '\n';
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
	ifac[N - 1] = pw(fac[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
	for (int it = 1; ; ++it) {
		for (int i = N - 1; i > 0; --i) {
			f[i] = C(cnt[i], it);
			for (int j = i + i; j < N; j += i) add(f[i], mod - f[j]);
		}
		if (f[1]) {
			cout << it << '\n';
			return 0;
		}
	}
}