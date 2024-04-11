#include <bits/stdc++.h>
using namespace std;

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

using num = modnum<998244353>;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<num> p(n);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		p[i] = num(a) / num(100);
	}
	vector<bool> state(n+1);
	set<int> which;
	state[0] = state[n] = true;
	which.insert(0);
	which.insert(n);

	vector<num> pref_product(n+1);
	vector<num> pref_sum(n+1);
	pref_product[0] = 1;
	pref_sum[0] = 0;
	for(int i = 0; i < n; i++){
		pref_sum[i+1] = pref_sum[i] + pref_product[i];
		pref_product[i+1] = p[i] * pref_product[i];
	}	

	auto get_val = [&](int i, int j) -> num {
		return (pref_sum[j] - pref_sum[i]) / pref_product[j];
	};

	num ans = get_val(0, n);
	for(int _ = 0; _ < q; _++){
		int f;
		cin >> f;
		f--;
		if(!state[f]){
			which.insert(f);
		}
		auto a = which.find(f);
		auto g = *prev(a);
		auto h = *next(a);

		num del = get_val(g, h) - get_val(g, f) - get_val(f, h);

		if(state[f]){
			ans += del;
			which.erase(a);
		} else {
			ans -= del;
		}
		state[f] = !state[f];
		cout << (int)ans << '\n';
	}
}