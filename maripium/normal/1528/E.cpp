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
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
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
 
using num = modnum<998244353>;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	auto C2 = [&](num v) -> num {
		return v * (v + 1) / 2;
	};
	auto C3 = [&](num v) -> num {
		return v * (v + 1) * (v + 2) / 6;
	};

	vector<array<num, 2>> dp(N + 1);
	vector<num> pref(N + 1);
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	pref[0] = 1;
	pref[1] = 3;
	for (int i = 2; i <= N; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = C2(pref[i - 1]) - C2(pref[i - 2]);
		pref[i] = pref[i - 1] + dp[i][0] + dp[i][1];
	}
	num ans = 0;
	for (int a = 1; a < N; ++a) {
		ans += dp[a][1] * dp[N - a][0];
	}
	ans += dp[N][0] + dp[N][1];
	ans += C3(pref[N - 1]);
	if (N > 1) ans -= C3(pref[N - 2]);
	ans += dp[N][1];
	ans += C3(pref[N - 1]);
	if (N > 1) ans -= C3(pref[N - 2]);
	cout << ans << '\n';
	return 0;
}