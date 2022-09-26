#include <bits/stdc++.h>

using namespace std;

template <int& MOD_> struct modnum {
	static constexpr int& MOD = MOD_;
	//static_assert(MOD_ > 0, "MOD must be positive");

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

int MOD;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N >> MOD;
    using num = modnum<MOD>;

    vector<num> fact(N+1, 1); for (int i = 1; i <= N; ++i) fact[i] = fact[i-1] * i;
    vector<num> ifact; for (auto &a : fact) ifact.push_back(inv(a));
    vector<vector<num>> binom(N+1, vector<num>(N+1));
    for (int i = 0; i <= N; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j) binom[i][j] = binom[i-1][j] + binom[i-1][j-1];
    }

    vector<num> dp(N+1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            int l = j-1;
            int r = i-j;
            dp[i] += binom[l+r][l];
        }
    }
    vector<vector<num>> ways(N+2, vector<num>(N+1));
    ways[0][0] = 1;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int l = 1; i + l + 1 <= N+1 && j+l <= N; ++l) {
                ways[i+1+l][j+l] += dp[l] * ways[i][j] * ifact[l];
            }
        }
    }
    num ans = 0;
    for (int l = 0; l <= N; ++l) {
        ans += fact[l] * ways[N+1][l];
    }
    cout << ans << '\n';
    return 0;
}