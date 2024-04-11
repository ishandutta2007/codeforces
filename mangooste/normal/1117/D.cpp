#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

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

vector<vector<int>> power(vector<vector<int>> a, ll b) {
	if (!b) {
		int n = a.size();
		vector<vector<int>> prod(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			prod[i][i]++;
		}
		return prod;
	}
	if (b % 2) {
		return a * power(a, b - 1);
	}
	return power(a * a, b / 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll n;
	int m;
	cin >> n >> m;
	vector<vector<int>> mat(m, vector<int>(m, 0));
	for (int i = 0; i < m - 1; i++) {
		mat[i + 1][i]++;
	}
	mat[0][m - 1]++;
	mat[m - 1][m - 1]++;
	mat = power(mat, n);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans = add(ans, mat[i][0]);
	}
	cout << ans << '\n';
}