#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h> /** keep-include */

using ll = long long;
ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
private:
	int v;
public:
	static const int MOD = MOD_;

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
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
		return *this *= (~o);
	}

	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename A, typename B> struct pairnum {
	A a;
	B b;
	pairnum() : a(), b() {}
	pairnum(ll v) : a(v), b(v) {}
	ll get_val(){
		return (ll(int(a)) << 32) ^ (ll(int(b)));
	}
	friend std::ostream& operator << (std::ostream& o, const pairnum& n) { return o << '(' << n.a << ',' << n.b << ')'; }
	friend bool operator == (const pairnum& a, const pairnum& b) { return a.a == b.a && a.b == b.b; }
	friend bool operator != (const pairnum& a, const pairnum& b) { return a.a != b.a || a.b != b.b; }
	pairnum& operator += (const pairnum& o) {
		a += o.a, b += o.b;
		return *this;
	}
	pairnum& operator -= (const pairnum& o) {
		a -= o.a, b -= o.b;
		return *this;
	}
	pairnum& operator *= (const pairnum& o) {
		a *= o.a, b *= o.b;
		return *this;
	}
	pairnum& operator /= (const pairnum& o) {
		a /= o.a, b /= o.b;
		return *this;
	}
	friend pairnum operator + (const pairnum& a, const pairnum& b) { return pairnum(a) += b; }
	friend pairnum operator - (const pairnum& a, const pairnum& b) { return pairnum(a) -= b; }
	friend pairnum operator * (const pairnum& a, const pairnum& b) { return pairnum(a) *= b; }
	friend pairnum operator / (const pairnum& a, const pairnum& b) { return pairnum(a) /= b; }
};
using num = pairnum<modnum<int(1e9)+7>, modnum<int(1e9)+9>>;

num B;
num C;
num invB;

ll ans = 0;
vector<ll> make_hashes(vector<int> f){
	vector<ll> hashes;
	num cur = C;
	vector<int> stk;
	for(int a : f){
		if(stk.empty() || stk.back() != a){
			stk.push_back(a);
			cur = cur * B + num(a);
		} else {
			stk.pop_back();
			cur = (cur - num(a)) * invB;
		}
		hashes.push_back(cur.get_val());
	}
	return hashes;
}

void cnt(const vector<int>& v, int x, int y){
	if(x == y) return;
	int z = (x + y) / 2;
	vector<int> f1, f2;
	for(int i = z; i >= x; i--) f1.push_back(v[i]);
	for(int i = z+1; i <= y; i++) f2.push_back(v[i]);
	vector<ll> h1 = make_hashes(f1);
	vector<ll> h2 = make_hashes(f2);
	unordered_map<ll, int> cnt1;
	for(ll a : h1) cnt1[a]++;
	for(ll b : h2) ans += cnt1[b];
	cnt(v, x, z);
	cnt(v, z+1, y);
}

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	ans = 0;
	cnt(v, 0, n-1);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	B = rng();
	C = rng();
	invB = 1 / B;

	int Q;
	cin >> Q;
	for(int _ = 0; _ < Q; _++) solve();
}