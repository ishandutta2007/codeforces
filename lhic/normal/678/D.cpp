#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const ll MOD = 1000000007;

struct matrix {
	ll a[2][2];
	matrix() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				a[i][j] = 0;
	}
	matrix operator*(matrix x) {
		matrix ans;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					ans.a[i][k] = (ans.a[i][k] + a[i][j] * x.a[j][k]) % MOD;
		return ans;
	}
};

matrix pw(matrix a, ll b) {
	matrix ans;
	for (int i = 0; i < 2; ++i)
		ans.a[i][i] = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = a * a;
		--b;
		ans = ans * a;
	}
	return ans;
}


ll a, b, n, x;


int main() {
	cin >> a >> b >> n >> x;
	matrix m;
	m.a[0][0] = a;
	m.a[0][1] = b;
	m.a[1][0] = 0;
	m.a[1][1] = 1;
	m = pw(m, n);
	ll ans = (m.a[0][0] * x + m.a[0][1]) % MOD;
	cout << ans << "\n";
	return 0;
}