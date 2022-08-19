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


template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T _x=0, T _y=0) : x(_x), y(_y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }

	T dist2() const { return abs(x) + abs(y); }

	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

using ll = int64_t;
using P = Point<ll>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int n;
	cin >> n;
	vector<P> pt(n);
	for(P& p : pt){
		cin >> p.x >> p.y;
	}
	vector<int> vis(n, 0);
	vector<int> groups;
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		ll mindist = ll(1e18);
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			mindist = min(mindist, (pt[i] - pt[j]).dist2());
		}
		vector<int> group(n, 0);
		group[i] = 1;
		for(int j = 0; j < n; j++){
			if((pt[i] - pt[j]).dist2() == mindist){
				group[j] = 1;
			}
		}
		int works = true;
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				if(x == y) continue;
				if(group[x] && group[y] && (pt[x] - pt[y]).dist2() != mindist) works = false;
				if(group[x] != group[y] && (pt[x] - pt[y]).dist2() <= mindist) works = false;
			}
		}
		if(works){
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(group[j]){
					vis[j] = 1;
					cnt++;
				}
			}
			groups.push_back(cnt);
		}
	}
	int singles = n;
	for(int x : groups) singles -= x;
	vector<num> dp(n+1, 0);
	dp[n] = 1;
	for(int x : groups){
		vector<num> ndp(n+1, 0);
		for(int p = n; p >= 0; p--){
			if(p >= 1){
				ndp[p-1] += dp[p] * p;
			}
			if(p >= x){
				ndp[p-x] += dp[p] * fact[p] * ifact[p-x];
			}
		}
		dp = ndp;
	}{
		int x = singles;
		vector<num> ndp(n+1, 0);
		for(int p = n; p >= 0; p--){
			if(p >= x){
				ndp[p-x] += dp[p] * fact[p] * ifact[p-x];
			}
		}
		dp = ndp;
	}
	num ans = 0;
	for(num z : dp) ans += z;
	cout << ans << '\n';
}