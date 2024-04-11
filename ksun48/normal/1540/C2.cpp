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

using num = modnum<int(1e9) + 7>;

vector<num> fact, ifact;

void init(){
	int N = 1100000;
	fact = {1};
	for(int i = 1; i < N; i++) fact.push_back(i * fact[i-1]);
	ifact.resize(N);
	ifact.back() = 1 / fact.back();
	for(int i = N - 1; i > 0; i--) ifact[i-1] = i * ifact[i];
}

num ncr(int n, int k){
	if(k < 0 || k > n) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int n;
	cin >> n;
	vector<int> c(n);
	for(int& x : c) cin >> x;
	vector<int> b(n-1);
	for(int& x : b) cin >> x;
	int q;
	cin >> q;
	int V = 0;
	{
		int bound = 0;
		int psum = 0;
		for(int i = 0; i < n; i++){
			if(i > 0) psum += b[i-1];
			bound += psum;
			V = min(V, -(bound / (i+1)));
		}
	}
	const int C = int(1e4) + 1;
	map<int, num> memo;
	num prod = 1;
	for(int x : c) prod *= (x+1);
	for(int _ = 0; _ < q; _++){
		int X;
		cin >> X;
		if(X < V - 120){
			cout << prod << '\n';
		} else if(X > V + 120){
			cout << 0 << '\n';
		} else if(memo.count(X)){
			cout << memo[X] << '\n';
		} else {
			vector<num> dp(C, 0);
			dp[0] = 1;
			int bound = 0;
			int psum = 0;
			for(int i = 0; i < n; i++){
				if(i > 0) psum += b[i-1];
				bound += psum;
				vector<num> ndp(C, 0);
				for(int j = 0; j < C; j++){
					ndp[j] += dp[j];
					if(j > 0) ndp[j] += ndp[j-1];
					if(j > c[i]) ndp[j] -= dp[j-c[i]-1];
				}
				for(int k = 0; k < C; k++){
					if(k < X * (i+1) + bound) ndp[k] = 0;
				}
				dp = ndp;
			}
			num ans = 0;
			for(num x : dp) ans += x;
			memo[X] = ans;
			cout << ans << '\n';
		}
	}
}