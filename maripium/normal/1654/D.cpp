#include <bits/stdc++.h>

using namespace std;

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

using num = modnum<998244353>;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	const int MAXN = 200200;
	vector<int> pr(MAXN, -1);
	for (int i = 2; i < MAXN; ++i) if (pr[i] == -1) {
		for (int j = i; j < MAXN; j += i) pr[j] = i;
	}	
	
	vector<vector<int>> factor(MAXN);
	for (int i = 2; i < MAXN; ++i) {
		factor[i] = factor[i / pr[i]];
		factor[i].push_back(pr[i]);
	}

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<vector<tuple<int, int, int>>> adj(N);
		for (int i = 0; i < N - 1; ++i) {
			int v, u, x, y; cin >> v >> u >> x >> y;
			--v, --u;
			adj[v].emplace_back(u, y, x);
			adj[u].emplace_back(v, x, y);
		}		

		vector<int> curFactor(N + 1);
		vector<int> worstFactor(N + 1);

		auto update = [&](int val, int delta) {
			for (int p : factor[val]) {
				curFactor[p] += delta;
				worstFactor[p] = min(worstFactor[p], curFactor[p]);
			}
		};

		num ans;
		function<void(int, int, num)> dfs = [&](int v, int p, num ratio) {
			ans += ratio;
			for (auto [u, x, y] : adj[v]) if (u != p) {
				update(x, +1);
				update(y, -1);
				dfs(u, v, ratio * x / y);
				update(y, +1);
				update(x, -1);
			}
		};

		dfs(0, -1, 1);
		for (int i = 1; i <= N; ++i) if (worstFactor[i] < 0) {
			while (worstFactor[i]++) ans *= i;
		}
		cout << ans << '\n';
	}
}