#include <bits/stdc++.h>

using namespace std;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
 
private:
	using ll = long long;
 
	int v;
 
	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
 
public:
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }
 
	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}
 
	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}
 
	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
 
template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<998244353>;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	const int MAXN = 1.01e5;
	vector<num> fact(MAXN);
	fact[0] = 1; for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i;
	vector<num> ifact(MAXN);
	ifact[MAXN - 1] = fact[MAXN - 1].inv();
	for (int i = MAXN - 1; i > 0; --i) ifact[i - 1] = ifact[i] * i;

	auto choose = [&](int x, int y) {
		return fact[x] * ifact[y] * ifact[x - y];
	};

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int64_t> A(1);
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			A.push_back(A.back() + a);
		} 
		map<int64_t, int> cnt;
		for (auto &a : A) cnt[a] ++;
		num ans = 1;

		for (auto [v, c0] : cnt) {
			if (2 * v < A[N] && cnt.count(A[N] - v)) {
				int c1 = cnt[A[N] - v];
				num cur = 0;
				if (v == 0) c0--, c1--;
				for (int i = 0; i <= min(c0, c1); ++i) cur += choose(c0, i) * choose(c1, i);
				ans *= cur;
			} else if (2 * v == A[N]) {
				num cur = 0;
				if (v == 0) c0 -= 2;
				for (int i = 0; i <= c0; ++i) cur += choose(c0, i);
				ans *= cur;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}