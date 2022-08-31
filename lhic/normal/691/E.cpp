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
const int MX = 110;
const ll MOD = 1e9 + 7;
int n;
ll k;

struct matrix {
	ll a[MX][MX];
	matrix() {
		for (int i = 0; i < MX; ++i)
			for (int j = 0; j < MX; ++j)
				a[i][j] = 0;
	}
	matrix operator*(matrix x) {
		matrix ans;
		for (int i = 0; i < MX; ++i)
			for (int j = 0; j < MX; ++j) {
				for (int k = 0; k < MX; ++k)
					ans.a[i][k] = (ans.a[i][k] + a[i][j] * x.a[j][k]) % MOD;
			}
		return ans;
	}
};

matrix pw(matrix a, ll b) {
	matrix ans;
	for (int i = 0; i < n; ++i)
		ans.a[i][i] = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = a * a;
		--b;
		ans = ans * a;
	}
	return ans;
}

ll a[1200];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	matrix m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
				m.a[i][j] = 1;
	}
	m = pw(m, k - 1);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans = (ans + m.a[i][j]) % MOD;
	cout << ans << "\n";
	return 0;
}