#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

vector<ll> matMult(const vector<ll>& a, const vector<ll>& b, int m) {
	vector<ll> res(m*m, 0);
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < m; ++x) {
			for (int i = 0; i < m; ++i) {
				res[x+y*m] += (a[i+y*m] * b[x+i*m]) % MOD;
			}
			res[x+y*m] %= MOD;
		}
	}
	return res;
}

vector<ll> matPow(vector<ll> mat, ll n, int m) {
	vector<ll> res(m*m, 0);
	for (int i = 0; i < m; ++i) res[i + m*i] = 1;

	while(n > 0) {
		if (n & 1) res = matMult(res, mat, m);
		mat = matMult(mat, mat, m);
		n >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	int m;
	cin >> n >> m;
	// DP[i] = DP[i-1] + DP[i-m] -> m x m matrix power

	vector<ll> mat(m*m,0);
	for (int i = 1; i < m; ++i) {
		mat[i + (i-1)*m] = 1;
	}
	mat[0] = 1;
	mat[(m-1)*m] = 1;

	vector<ll> res_mat = matPow(mat, n, m);

	ll ans = res_mat[0+0*m];
	cout << ans << '\n';
}