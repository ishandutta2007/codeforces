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

const int X = 2.1e5;

bitset<X> is_prime;
vector<int> pr;
vector<int> mu(X, 0);

void init(){
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	mu[1] = 1;
	for(int i = 2; i < X; i++){
		if(is_prime[i]){
			pr.push_back(i);
			mu[i] = -1;
		}
		for(int p : pr){
			if(i * p >= X) break;
			is_prime[i * p] = false;
			if(i % p == 0){
				mu[i * p] = 0;
			} else {
				mu[i * p] = -mu[i];
			}
			if(i % p == 0) break;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int n, m;
	cin >> n >> m;
	vector<int> l(n), r(n);
	int maxr = 0;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		maxr = max(maxr, r[i]);
	}
	num total = 0;
	for(int g = 1; g <= maxr; g++){
		if(mu[g] == 0) continue;
		int S = m / g + 1;
		vector<num> dp(S, 0);
		dp[0] = 1;
		for(int i = 0; i < n; i++){
			int newl = (l[i] + g-1) / g;
			int newr = r[i] / g;
			vector<num> psum(S+1, 0);
			for(int x = 0; x < S; x++) psum[x+1] = psum[x] + dp[x];
			vector<num> ndp(S, 0);
			if(newl <= newr){
				for(int x = 0; x < S; x++){
					ndp[x] = psum[max(x-newl+1, 0)] - psum[max(x-newr, 0)];
				}
			}
			dp = ndp;
		}
		num ans = 0;
		for(num v : dp) ans += v;
		total += ans * mu[g];
	}
	cout << total << '\n';
}