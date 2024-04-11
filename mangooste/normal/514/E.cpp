#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXA = 100;

inline int add(int a, int b) {
	a += b;
	return a - MOD * (a >= MOD);
}

inline int mult(int a, int b) {
	return (ll) a * b % MOD;
}

vector<vector<int>> operator * (vector<vector<int>> a, vector<vector<int>> b) {
	int n = a.size();
	vector<vector<int>> prod(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				prod[i][j] = add(prod[i][j], mult(a[i][k], b[k][j]));
			}
		}
	}
	return prod;
}

vector<vector<int>> power(vector<vector<int>> a, int b) {
	if (!b) {
		vector<vector<int>> res(MAXA + 1, vector<int>(MAXA + 1, 0));
		for (int i = 0; i < MAXA + 1; i++) {
			res[i][i] = 1;
		}
		return res;
	}
	if (b % 2) {
		return a * power(a, b - 1);
	}
	return power(a * a, b / 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, x;
	cin >> n >> x;
	vector<vector<int>> m(MAXA + 1, vector<int>(MAXA + 1, 0));
	m[0][0] = m[0][MAXA] = 1;
	for (int i = 1; i < MAXA; i++) {
		m[i + 1][i]++;
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		m[MAXA - d[i] + 1][MAXA]++;
	}

	vector<int> base(MAXA, 0);
	for (int i = 0; i < MAXA; i++) {
		for (int j = 1; j <= MAXA; j++) {
			if (i - (MAXA + 1 - j) >= 0) {
				base[i] = add(base[i], mult(m[j][MAXA], base[i - (MAXA + 1 - j)]));
			}
		}
		base[i] = add(base[i], 1);
	}
	base.insert(base.begin(), 1);

	int ans = 0;
	m = power(m, x);
	for (int i = 0; i < MAXA + 1; i++) {
		ans = add(ans, mult(base[i], m[i][1]));
	}
	cout << ans << '\n';
}