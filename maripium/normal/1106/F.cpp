#include <bits/stdc++.h>
using namespace std;

const int step = 32123;
const int mod = 998244352;
const int mod2 = 998244353;

struct Matrix {
	vector<vector<int>> a;
	Matrix(int n = 0,int m = 0) {
		a.assign(n, vector<int>(m, 0));
	}
	Matrix operator * (const Matrix &b) const {
		int n = a.size(), m = a[0].size(), p = b.a[0].size();
		Matrix c(n, p);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < p; ++k) {
					c.a[i][k] += (long long) a[i][j] * b.a[j][k] % mod;
					if (c.a[i][k] >= mod) {
						c.a[i][k] -= mod;
					}
				}
			}
		}
		return c;
	}
};

Matrix base, mul;

int mult(int x,int y,int md) {
	return (long long) x * y % md;
}

Matrix power(int n) {
	Matrix ans = base;
	while (n) {
		if (n & 1) {
			ans = ans * mul;
		}
		mul = mul * mul;
		n >>= 1;
	}
	return ans;
}

int power(int x,int y,int md) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mult(ans, x, md);
		}
		x = mult(x, x, md);
		y >>= 1;
	}
	return ans;
}

int main() {
	int k;
	scanf("%d", &k);
	base = mul = Matrix(k, k);
	for (int i = 0; i < k; ++i) {
		base.a[i][i] = 1;
	}
	vector<int> a(k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < k; ++i) {
		mul.a[i][0] = a[i];
		if (i + 1 < k) {
			mul.a[i][i + 1] = 1;
		}
	}	
	int n, m;
	scanf("%d %d", &n, &m);
	Matrix ans(1, k);
	ans.a[0][0] = 1;
	ans = ans * power(n - k);
	int q = ans.a[0][0];
	// found x and x ^ q == m;
	auto find_log = [&](int m) {
		map<int,int> mp;
		int now = 1;
		for (int i = 0; i < step; ++i) {
			mp[now] = i;
			now = mult(now, 3, mod2);
		}
		int nw = 1;
		for (int i = 0; i < step; ++i) {
			int need = mult(m, power(nw, mod2 - 2, mod2), mod2);
			if (mp.count(need)) {
				return (int) i * step + mp[need];
			}
			nw = mult(nw, now, mod2);
		}
		assert(false);
	};
	// assert(power(6, q, mod2) == m);
	int mm = find_log(m);
	assert(power(3, mm, mod2) == m);
	m = mm;
	// x * q == m -> x = m * inv(q)
	// cout << q << ' ' << m << '\n';
	int g = __gcd(__gcd(mod, q), m);
	q /= g, m /= g;
	int md = mod / g;
	if (__gcd(md, q) > 1) {
		puts("-1");
		return 0;
	}
	// cout << q << ' ' << m << ' ' << md << '\n';
	int phi = 1;
	if (md % 7 == 0) {
		phi *= 6;
	}
	if (md % 17 == 0) {
		phi *= 16;
	}
	if (md % 2 == 0) {
		int now = md;
		while (now % 2 == 0) {
			phi *= 2;
			now /= 2;
		}
		phi /= 2;
	}
	int up = mult(m, power(q, phi - 1, md), md);
	cout << power(3, up, mod2) << '\n';
}