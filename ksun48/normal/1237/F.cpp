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

vector<num> fact;
vector<num> ifact;

void init(){
	fact = {1};
	for(int i = 1; i < 10000; i++) fact.push_back(i * fact[i-1]);
	for(num x : fact) ifact.push_back(1 / x);	
}

num ncr(int n, int k){
	if(k < 0 || k > n) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}

using grid = vector<vector<num> >;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> r(h, 1);
	vector<int> c(w, 1);
	for(int i = 0; i < 2*n; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		r[a] = 0;
		c[b] = 0;
	}
	vector<vector<int> > q = {r, c};
	vector<vector<num> > dps(2);
	vector<int> tot_empty(2);
	for(int j = 0; j < 2; j++){
		vector<int> nums = {0};
		int cur = 0;
		for(int i = 0; i < (int)q[j].size(); i++){
			if(q[j][i]){
				cur++;
				tot_empty[j]++;
			} else if(cur > 0){
				nums.push_back(cur);
				cur = 0;
			}
		}
		nums.push_back(cur);
		vector<num> dp_pairs(1, 1);
		for(int x : nums){
			vector<num> new_dp_pairs(dp_pairs.size() + x, 0);
			for(int j = 0; j * 2 <= x; j++){
				num mult = ncr(x-j, j);
				for(int i = 0; i < (int)dp_pairs.size(); i++){
					new_dp_pairs[i+j] += dp_pairs[i] * mult;
				}
			}
			dp_pairs = new_dp_pairs;
		}
		dps[j] = dp_pairs;
	}
	num ans = 0;
	for(int i = 0; i < (int)dps[0].size(); i++){
		for(int j = 0; j < (int)dps[1].size(); j++){
			if(2 * i + j > tot_empty[0]) continue;
			if(i + 2 * j > tot_empty[1]) continue;
			num f = dps[0][i] * dps[1][j] * fact[i] * fact[j] * ncr(tot_empty[0] - 2 * i, j) * ncr(tot_empty[1] - 2 * j, i);
			ans += f;
		}
	}
	cout << (int)ans << '\n';
}