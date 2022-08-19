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

using ll = int64_t;

const ll MOD = 998244353;
const ll MOD2 = int(1e9) + 7;

using num = modnum<MOD2>;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll n;
	cin >> n;
	n++;
	ll B = n / MOD + 1;
	auto get_idx = [&](ll x) -> ll {
		ll cnt = 0;
		string s = to_string(x);
		for(int d = 0; d <= 13; d++){
			if(d == 0){
				cnt += (0 < x);
				continue;
			}
			ll minv = 1;
			for(int j = 0; j < d-1; j++) minv *= 10;
			ll r;
			if(d < (int)s.size()){
				r = stoll(s.substr(0, d)) + 1;
			} else {
				r = x;
				for(int j = (int)s.size(); j < d; j++) r *= 10;
			}
			r = min(r, n);
			if(r > minv){
				cnt += r - minv;
			}
		}
		return cnt;
	};
	ll tcnt = 0;
	for(ll c = -B; c <= B; c++){
		ll thresh = MOD * c;
		ll rcnt = 0;
		for(int d = 0; d <= 13; d++){
			ll minv, maxv;
			if(d == 0){
				minv = 0;
				maxv = 1;
			} else {
				minv = 1;
				for(int i = 0; i < d-1; i++) minv *= 10;
				maxv = minv * 10;
			}
			maxv = min(maxv, n);
			if(maxv <= minv) continue;
			ll s = minv - 1;
			ll e = maxv;
			while(s + 1 < e){
				ll m = (s + e) >> 1;
				if(get_idx(m) - m >= thresh){
					e = m;
				} else {
					s = m;
				}
			}
			rcnt += (maxv - e);
		}
		tcnt += rcnt;
	}
	num ans = tcnt - num(B+1) * num(n);
	ans *= (-MOD);
	cout << ans << '\n';
}