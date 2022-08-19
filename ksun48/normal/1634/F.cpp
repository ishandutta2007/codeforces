#include <bits/stdc++.h>
using namespace std;

int MOD;

struct modnum {
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

using num = modnum;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	cin >> MOD;
	vector<num> a(n+2, 0);
	int nonzero = 0;
	auto upd = [&](int x, num v){
		if(a[x] != 0) nonzero--;
		a[x] += v;
		if(a[x] != 0) nonzero++;
	};
	for(int i = 0; i < n; i++){
		num x;
		cin >> x;
		upd(i, x);
		upd(i+1, -x);
		upd(i+2, -x);
	}
	for(int i = 0; i < n; i++){
		num x;
		cin >> x;
		upd(i, -x);
		upd(i+1, x);
		upd(i+2, x);
	}
	vector<num> fib(n+3, 0);
	fib[0] = fib[1] = 1;
	for(int i = 2; i < fib.size(); i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		char c;
		cin >> c;
		cin >> l >> r;
		l--; r--;
		int sgn = (c == 'A') ? 1 : -1;
		if(l == r){
			upd(l, fib[0] * sgn);
			upd(l+1, -fib[0] * sgn);
			upd(l+2, -fib[0] * sgn);
		} else if(l + 1 == r){
			upd(l, fib[0] * sgn);
			upd(l+1, (fib[1] - fib[0]) * sgn);
			upd(l+2, (-fib[1] - fib[0]) * sgn);
			upd(l+3, -fib[1] * sgn);
		} else {
			upd(l, fib[0] * sgn);
			upd(l+1, (fib[1] - fib[0]) * sgn);
			upd(r+1, (-fib[r-l-1] - fib[r-l]) * sgn);
			upd(r+2, -fib[r-l] * sgn);
		}
		cout << (nonzero == 0 ? "YES" : "NO") << '\n';
	}
}