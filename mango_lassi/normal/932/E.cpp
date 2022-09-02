#include <iostream>
using namespace std;

// 		(x + 1)^n 	= sum_{i=0}^{n} (n choose i) x^i
// d/dx 	x * (x + 1)^n 	= sum_{i=0}^{n} (n choose i) i x^i
// d/dx x d/dx  x * (x + 1)^n   = sum_{i=0}^{n} (n choose i) i^2 x^i
// ...
// op (x + 1)^n = xn(x + 1)^n-1
// op xn(x + 1)^n = xn(x + 1)^n-1 + x^2n^2(x + 1)^n-2

// d/dx f(x)g(x) = f'(x)g(x) + f(x)g'(x)

typedef long long ll;
const ll mod = 1e9 + 7;
const int K = 5002;
ll mult[K][K]; // after derivating i times, multiplier of x^j (x+1)^n-j

ll twopow(ll b) {
	if (b & 1) return (twopow(b-1) << 1) % mod;
	if (b == 0) return 1;
	ll sub = twopow(b>>1);
	return (sub * sub) % mod;
}

int main() {
	int n, k;
	cin >> n >> k;

	mult[0][0] = 1;
	for (int i = 0; i < k; ++i) {
		// d/dx a x^j (x+1)^(n-j) = aj x^(j-1) (x+1)^(n-j) + a(n-j) x^j (x-1)^(n-j-1)
		
		for (int j = 0; j <= min(i, n); ++j) {
			if (mult[i][j] == 0) continue;

			mult[i+1][j] += mult[i][j] * j;
			mult[i+1][j] %= mod;

			mult[i+1][j+1] += mult[i][j] * (n-j);
			mult[i+1][j+1] %= mod;
		}
	}
	// set x = 1
	ll res = 0;
	for (int j = 0; j <= min(k, n); ++j) {
		res += mult[k][j] * twopow(n-j);
		res %= mod;
	}
	cout << res << '\n';
}