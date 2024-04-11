#include <bits/stdc++.h>
using namespace std;

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

using num = modnum<int(1e9)+7>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n, m;
	ll q;
	cin >> n >> m >> q;
	vector<int> u(m), v(m), w(m);
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i] >> w[i];
		u[i]--; v[i]--;
	}
	vector<ll> len(n, -1e18);
	len[0] = 0;
	vector<ll> best_path(m, -1e18);
	vector<ll> ans(n+1, -1e18);
	for(int d = 0; d <= n; d++){
		for(int i = 0; i < n; i++){
			ans[d] = max(ans[d], len[i]);
		}
		for(int i = 0; i < m; i++){
			best_path[i] = max(best_path[i], max(len[u[i]], len[v[i]]) - w[i] * d);
		}
		vector<ll> newlen(n, -1e18);
		for(int i = 0; i < m; i++){
			newlen[u[i]] = max(newlen[u[i]], len[v[i]] + w[i]);
			newlen[v[i]] = max(newlen[v[i]], len[u[i]] + w[i]);
		}
		len = newlen;
	}
	num total = 0;
	for(int d = 0; d <= q && d <= n; d++){
		total += ans[d];
	}
	auto get_best = [&](ll d) -> ll {
		ll best = -1;
		ll id = -1;
		for(int j = 0; j < m; j++){
			ll clen = best_path[j] + w[j] * d;
			if(clen > best){
				best = clen;
				id = j;
			}
		}
		return id;
	};
	if(n+1 <= q){
		y_combinator([&](auto self, ll l, ll lv, ll r, ll rv) -> void {
			if(l > r) return;
			if(lv == rv){
				total += num(r - l + 1) * best_path[lv];
				total += num(r - l + 1) * num(r + l) / 2 * w[lv];
			} else {
				ll m1 = (l + r) / 2;
				ll m2 = m1 + 1;
				ll m1v = get_best(m1);
				ll m2v = get_best(m2);
				self(l, lv, m1, m1v);
				self(m2, m2v, r, rv);
			}
		})(n+1, get_best(n+1), q, get_best(q));		
	}
	cout << total << '\n';
}