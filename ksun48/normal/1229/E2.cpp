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

using num = modnum<int(1e9)+7>;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	const int n = 7;
	vector<vector<num> > p(n, vector<num>(n, 0));
	int _n;
	cin >> _n;
	for(int i = 0; i < n; i++) p[i][i] = 1;
	for(int i = 0; i < _n; i++){
		for(int j = 0; j < _n; j++){
			int a;
			cin >> a;
			p[i][j] = num(a) / num(100);
		}
	}
	vector<int> lookup(1 << n, 0); 
	vector<vector<int> > masks(n+1);
	for(int i = 0; i < (1 << n); i++){
		int a = __builtin_popcount(i);
		lookup[i] = (int)masks[a].size();
		masks[a].push_back(i);
	}
	map<ll, num> dp;
	dp[1] = 1;
	for(int i = 0; i < n; i++){
		map<ll, num> newdp;
		for(auto r : dp){
			vector<ll> new_mask(n);

			ll z = masks[i].size();
			for(ll f = 0; f < z; f++){
				if((r.first >> f) & 1){
					ll g = masks[i][f];
					for(int j = 0; j < n; j++){
						if((g >> j) & 1) continue;
						new_mask[j] |= (1ll << lookup[g ^ (1 << j)]);
					}
				}
			}
			for(int s = 0; s < (1 << n); s++){
				num prob = 1;
				ll tot_mask = 0;
				for(int j = 0; j < n; j++){
					if((s >> j) & 1){
						prob *= p[i][j];
						tot_mask |= new_mask[j];
					} else {
						prob *= (1 - p[i][j]);
					}
				}
				newdp[tot_mask] += prob * r.second;
			}
		}
		dp = newdp;
	}

	num ans = dp[1];
	cout << (int)ans << '\n';
}