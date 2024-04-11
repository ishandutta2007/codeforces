#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned uint;
typedef pair <int, int> pii;
mt19937 rng(123);
LL myRand(LL mod) { return rng() % mod; }
#define read(a) scanf("%d", &a)


const uint MOD = 998244353;
template<uint mod = MOD> struct mint { // 1000000007  1000000009
	uint x;
 
	mint() : x(0) {}
	mint(LL _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = uint(_x);
	}
 
	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = uint((ULL)x * a.x % mod);
		return *this;
	}
	mint pow(LL pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		uint t = x;
		uint res = 1;
		while(t != 1) {
			uint z = mod / t;
			res = uint((ULL)res * (mod - z) % mod);
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}
 
	bool sqrt(mint &res) const {
		if (mod == 2 || x == 0) {
			res = *this;
			return true;
		}
		if (pow((mod - 1) / 2) != 1) return false;
		if (mod % 4 == 3) {
			res = pow((mod + 1) / 4);
			return true;
		}
		int pw = (mod - 1) / 2;
		int K = 30;
		while((1 << K) > pw) K--;
		while(true) {
			mint t = myRand(mod);
			mint a = 0, b = 0, c = 1;
			for (int k = K; k >= 0; k--) {
				a = b * b;
				b = b * c * 2;
				c = c * c + a * *this;
				if (((pw >> k) & 1) == 0) continue;
				a = b;
				b = b * t + c;
				c = c * t + a * *this;
			}
			if (b == 0) continue;
			c -= 1;
			c *= mint() - b.inv();
			if (c * c == *this) {
				res = c;
				return true;
			}
		}
		assert(false);
	}
 
	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};
const int N = 3e5 + 5;
using Mint = mint<MOD>;
struct Factorials {
	vector<Mint> f, fi;
 
	Factorials() : f(), fi() {}
	Factorials(int n) {
		n += 10;
		f = vector<Mint>(n);
		fi = vector<Mint>(n);
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		fi[n - 1] = f[n - 1].inv();
		for (int i = n - 1; i > 0; i--)
			fi[i - 1] = fi[i] * i;
	}
 
	Mint C(int n, int k) {
		if (k < 0 || k > n) return 0;
		return f[n] * fi[k] * fi[n - k];
	}
} fac(N);

Mint f[N], ff[N];

void work() {
	int n;
	scanf("%d", &n);
	Mint ans = 0, ww = 1;
	for (int k = 0; 4 * k <= n; k++) {
		ans = ans + fac.C(n - 2 * k, 2 * k) * (k > 0 ? ff[2 * k - 1] * ww : Mint(1)) * f[n - 4 * k];
		ww = ww * 2;
	}
	printf("%d\n", (int)ans.x);
}

int main() {
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < N; i++) {
		f[i] = f[i - 1] + Mint(i - 1) * f[i - 2];
	}
	ff[0] = ff[1] = 1;
	for (int i = 2; i < N; i++) ff[i] = ff[i - 2] * i;
	int T;
	cin >> T;
	while (T--) work();
}