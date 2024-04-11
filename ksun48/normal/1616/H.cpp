#include <bits/stdc++.h>

template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

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
		res.v = mod_inv_in_range(v, MOD);
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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using num = modnum<998244353>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);


	int N, K; cin >> N >> K;

	vector<num> p2(2*N+1);
	p2[0] = 1;
	for(int i = 1; i <= 2*N; i++) p2[i] = p2[i-1] * 2;

	const int B = 31;
	std::vector<std::array<int, 2>> ch; ch.reserve(1 + N * B);
	std::vector<int> sz; sz.reserve(1 + N*B);
	ch.push_back({-1, -1});
	sz.push_back(0);
	const int ROOT = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		int cur = ROOT;
		sz[cur]++;
		for (int b = B-1; b >= 0; b--) {
			int d = (a >> b) & 1;
			if (ch[cur][d] == -1) {
				ch[cur][d] = int(ch.size());
				ch.push_back({-1, -1});
				sz.push_back(0);
			}
			cur = ch[cur][d];
			sz[cur]++;
		}
	}

	auto get_sz = [&](int l){
		return (l == -1) ? 0 : sz[l];
	};

	num ans = std::y_combinator([&](auto self, int l, int r, int b) -> num {
		if (l == -1 && r == -1) return 1;
		if (l == -1) return p2[sz[r]];
		if (r == -1) return p2[sz[l]];
		if (b == -1) {
			if (l == r) {
				return p2[sz[l]];
			} else {
				return p2[sz[l] + sz[r]];
			}
		}
		if (K & (1 << b)) {
			if (l == r) {
				return self(ch[l][0], ch[r][1], b-1);
			} else {
				return self(ch[l][0], ch[r][1], b-1) * self(ch[r][0], ch[l][1], b-1);
			}
		} else {
			if (l == r) {
				return self(ch[l][0], ch[r][0], b-1) + self(ch[l][1], ch[r][1], b-1) - 1;
			} else {
				return self(ch[l][0], ch[r][0], b-1) + self(ch[l][1], ch[r][1], b-1)
					+ p2[sz[l]] + p2[sz[r]]
					- p2[get_sz(ch[l][0])] - p2[get_sz(ch[l][1])] 
					- p2[get_sz(ch[r][0])] - p2[get_sz(ch[r][1])] 
					+ 1;
			}
		}
	})(ROOT, ROOT, B-1);
	cout << (ans-1) << '\n';

	return 0;
}