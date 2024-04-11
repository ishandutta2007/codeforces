#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
	if (b & 1) return (a * modpow(a, b-1)) % MOD;
	if (b == 0) return 1;
	return modpow((a*a) % MOD, b / 2);
}
ll modinv(ll a) {
	return modpow(a, MOD - 2);
}

vector<ll> matmul(int n, const vector<ll>& a, const vector<ll>& b) {
	vector<ll> res(n*n, 0);
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int i = 0; i < n; ++i) {
				res[x+y*n] += (a[i+y*n] * b[x+i*n]) % MOD;
			}
			res[x+y*n] %= MOD;
		}
	}
	return res;
}

vector<ll> matpow(int n, vector<ll> a, int k) {
	vector<ll> unit(n*n, 0);
	for (int i = 0; i < n; ++i) unit[i+n*i] = 1;

	for (int j = 0; (1<<j) <= k; ++j) {
		if (k & (1<<j)) {
			unit = matmul(n, a, unit);
		}
		a = matmul(n, a, a);
	}
	return unit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int zeros = 0;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] == 0) ++zeros;
	}
	if (zeros > n-zeros) {
		zeros = n - zeros;
		for (int i = 0; i < n-1-i; ++i) {
			swap(v[i], v[n-1-i]);
			v[i] ^= 1;
			v[n-1-i] ^= 1;
		}
	}

	int m = 0;
	for (int i = 0; i < zeros; ++i) {
		if (v[i] == 1) ++m;
	}
	int d = zeros + 1; // Maximum amount of positions we can have wrong

	ll choose2 = (((n * (n-1)) % MOD) * modinv(2)) % MOD;
	ll chances = (zeros * (n-zeros)) % MOD;
	ll mult = (chances * modinv(choose2)) % MOD;
	ll othmult = ((choose2 - chances) * modinv(choose2)) % MOD;
	if (othmult < 0) othmult += MOD;

	// mult: chance we pick two from different sides
	// othmult: chance we don't

	vector<ll> transition(d*d);
	for (int i = 0; i < d; ++i) {
		ll pa1 = ((zeros - i) * modinv(zeros)) % MOD;
		ll pa2 = (i * modinv(zeros)) % MOD;
		ll pb1 = ((n-zeros - i) * modinv(n - zeros)) % MOD;
		ll pb2 = (i * modinv(n - zeros)) % MOD;
		for (int j = 0; j < d; ++j) {
			// We have i misses, how likely we have j misses in the next step
			int ind = j + d*i;

			if (i + 1 == j) {
				// pick correct and incorrect
				transition[ind] = (mult * ((pa1 * pb1) % MOD)) % MOD;
			} else if (i == j) {
				ll add = (((pa1 * pb2) % MOD) + ((pa2 * pb1) % MOD)) % MOD;
				transition[ind] = ((othmult) + (mult * add) % MOD) % MOD;
			} else if (i - 1 == j) {
				transition[ind] = (mult * ((pa2 * pb2) % MOD)) % MOD;
			} else {
				transition[ind] = 0;
			}
		}
	}

	/*
	cout << d << '\n';
	for (int y = 0; y < d; ++y) {
		for (int x = 0; x < d; ++x) {
			cout << transition[x+y*d] << ' ';
		}
		cout << '\n';
	}
	*/

	vector<ll> mat = matpow(d, transition, k);
	cout << mat[0+d*m] << '\n';
}