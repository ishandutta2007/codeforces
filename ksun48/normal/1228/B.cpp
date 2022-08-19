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

using num = modnum<int(1e9) + 7>;

vector<num> fact;
vector<num> ifact;

void init(){
	fact = {1};
	for(int i = 1; i < 100000; i++) fact.push_back(i * fact[i-1]);
	for(num x : fact) ifact.push_back(1 / x);	
}

num ncr(int n, int k){
	if(k < 0 || k > n) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}

num powmod(num x, int a){
	if(a == 0) return 1;
	if(a & 1) return x * powmod(x, a-1);
	return powmod(x * x, a/2);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int h, w;
	cin >> h >> w;
	vector<vector<int> > grid(h, vector<int>(w, 0));
	for(int i = 0; i < h; i++){
		int r;
		cin >> r;
		for(int j = 0; j < r; j++) grid[i][j] |= 1;
		if(r < w) grid[i][r] |= 2;
	}
	for(int i = 0; i < w; i++){
		int r;
		cin >> r;
		for(int j = 0; j < r; j++) grid[j][i] |= 1;
		if(r < h) grid[r][i] |= 2;
	}
	num ans = 1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(grid[i][j] == 3){
				ans *= 0;
			}
			if(grid[i][j] == 0){
				ans *= 2;
			}
		}
	}
	cout << (int)ans << '\n';
}