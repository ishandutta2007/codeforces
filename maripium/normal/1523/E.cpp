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
 
using num = modnum<1000000007>;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	const int V = 1.01e5;
	vector<num> fact(V);
	fact[0] = 1; for (int i = 1; i < V; ++i) fact[i] = fact[i - 1] * i;
	vector<num> ifact(V);
	ifact[V - 1] = 1 / fact[V - 1]; for (int i = V - 1; i > 0; --i) ifact[i - 1] = ifact[i] * i;
	vector<num> invs(V); for (int i = 1; i < V; ++i) invs[i] = fact[i - 1] * ifact[i];

	auto choose = [&](int x, int y) {
		if (x < y || y < 0) return num(0);
		return fact[x] * ifact[y] * ifact[x - y]; 
	};

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		num ans = 1;
		num prob = 1;
		for (int i = 1; (i - 1) * (K - 1) <= N; ++i) {
			prob *= invs[N - i + 1];
			ans += choose(N - (i - 1) * (K - 1), i) * prob * fact[i];
		}
		cout << ans << '\n';
	}
	return 0;
}