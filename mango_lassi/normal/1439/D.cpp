#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;
 
template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v) {
	bool first = 1;
	string res = "{";
	for (const auto &x: v) {
		if (!first) res += ", ";
		first = 0;
		res += to_string(x);
	}
	res += "}";
	return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
 
void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) if(0) puts("No effect.")
#endif
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using db = double;
using ull = unsigned long long;
using uint = unsigned int;

struct Montgomery {
	constexpr static ull modPow(ull a, ull b, ull c) {
		ull r = 1;
		for (; b; b /= 2) {
			if (b & 1) r = (r*a) % c;
			a = (a*a) % c;
		}
		return r;
	}

	static constexpr ull R = (ull)1 << 32;
	uint P, P2, RR, MC; // Modulo, 2^64 mod P, x for which xP = -1 mod 2^32
	Montgomery(uint m = (uint)1e9 + 7) : P(m), P2(2*m), RR((R%m)*R % m), MC((R * modPow(R % m, m-2, m) - 1) / m) {}
	uint mult(uint a, uint b) const {
		ull t = (ull)a * b; // < 4P
		ull k = (uint)t * MC; // < 2^32
		return (t + k * P) >> 32; // < 2P, Exact division!
	}
};

template<const Montgomery& mt> struct Z {
	private:
		uint x;
	public:
		/// start-hash
		Z(ll a = 0) : x(mt.mult(a, mt.RR)) { assert(a >= 0); }
		explicit operator int() { uint res = mt.mult(x, 1); return (res < mt.P ? res : res - mt.P); }
		static int getP() { return mt.P; }
	
		Z& operator +=(Z b) { x += b.x; if (x >= mt.P2) x -= mt.P2; return *this; }
		Z& operator -=(Z b) { if (x < b.x) x += mt.P2; x -= b.x; return *this; }
		Z& operator *=(Z b) { x = mt.mult(x, b.x); return *this; }
		friend Z operator +(Z a, Z b) { return a += b; }
		friend Z operator -(Z a, Z b) { return a -= b; }
		friend Z operator *(Z a, Z b) { return a *= b; }
		bool operator ==(Z b) const { return (x > mt.P ? x - mt.P : x) == (b.x > mt.P ? b.x - mt.P : b.x); }
		/// end-hash

		// the following are needed for fft and polynomial operations.
		/// start-hash
		Z pow(ll k) const {
			Z res = 1, a = *this;
			for (; k; k >>= 1, a = a * a) if (k & 1) res = res * a;
			return res;
		}
		Z& operator /=(Z b) {
			assert(b.x != 0);
			*this = *this * b.pow(mt.P - 2);
			return *this;
		}
		friend Z operator /(Z a, Z b) { return a /= b; }
		/// end-hash

		friend string to_string(Z a) { return to_string((int)a); }
};

Montgomery mt;
using Mint = Z<mt>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int mod, n, m;
	cin >> n >> m >> mod;
	mt = Montgomery(mod);
	const int maxn = 500;
	
	vector<vector<Mint>> binom(maxn + 1, vector<Mint>(maxn + 1));
	rep(i, 0, maxn) {
		binom[i][0] = 1;
		rep(j, 1, i) binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
	}
 
	vector<Mint> cnt(m + 1), sum(m + 1);
	cnt[0] = 1;
	sum[0] = 0;
	rep(i, 1, m) rep(j, 0, i - 1) {
		cnt[i] += binom[i - 1][j] * cnt[j] * cnt[i - 1 - j] * (i + 1);
		sum[i] += binom[i - 1][j] * (cnt[j] * cnt[i - 1 - j] * (binom[j + 1][2] + binom[i - j][2])
									+ (sum[j] * cnt[i - 1 - j] + cnt[j] * sum[i - 1 - j]) * (i + 1));
	}
	vector<vector<Mint>> f(n + 1, vector<Mint>(n + 1)), g(f);
	f[0][0] = 1;
	g[0][0] = 0;
	rep(i, 1, n) {
		rep(j, 0, i - 1) {
			rep(k, 0, j) {
				f[i][j] += binom[j][k] * f[i - 1 - k][j - k] * cnt[k];
				g[i][j] += binom[j][k] * (f[i - 1 - k][j - k] * sum[k] + g[i - 1 - k][j - k] * cnt[k]);
			}
		}
		f[i][i] = cnt[i];
		g[i][i] = sum[i];
	}
	printf("%d\n", (int)g[n][m]);
	return 0;
}