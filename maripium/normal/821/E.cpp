#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
const int mod = 1e9 + 7;

int n;
int k;
int a[N], b[N]; int c[N];

struct matrix {
	vector < vector<int> > M;
	int size() { return (int)M.size(); }
	matrix(int n = 0, int m = 0) { M.assign(n + 1, vector <int> (m + 1, 0)); }
	vector<int>& operator [] (int x) { return M[x]; }
};

matrix operator * (matrix &a, matrix &b) {
	int m = a.size() - 1, n = b.size() - 1, p = b[0].size() - 1;
	matrix c = matrix(m, p);
	for (int i = 0; i <= m; ++i) for (int j = 0; j <= p; ++j) {
		for (int k = 0; k <= n; ++k) c[i][j] = (c[i][j] +  a[i][k] * b[k][j]) % mod;
	}
	return c;
}

matrix pow(matrix &a, int n) {
	int m = a.size() - 1; matrix res = matrix(m,m); for (int i = 0; i <= m; ++i) res[i][i] = 1;
	for (int i = n;i > 0;i >>= 1) {
		if (i&1LL) res = res * a;
		a = a * a;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
	b[n] = k;

	matrix cur = matrix(15,0); c[0] = 15;
	cur[0][0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		matrix nxt = matrix(c[i], 0);
		for (int j = 0; j <= min(c[i], c[i-1]); ++j) nxt[j][0] = cur[j][0];
		cur = nxt;

		matrix base = matrix(c[i], c[i]);
		for (int j = 0; j <= c[i]; ++j) {
			for (int k = -1; k <= 1; ++k) {
				if (j + k < 0 || j + k > c[i]) continue;
				base[j][j + k] = 1;
			}
		}

		base = pow(base, b[i] - a[i]);
		cur = base * cur;
	}

	cout << cur[0][0] << endl;
}