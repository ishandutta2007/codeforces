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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

vector<num> fact;
vector<num> ifact;

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

map<int, vector<num> > z;

num compute_sum(int qcnt, int f){
	if(!z.count(qcnt)){
		vector<num> x;
		num cur = 0;
		for(int j = 0; j <= qcnt; j++){
			x.push_back(cur);
			cur += ncr(qcnt, j);
		}
		for(int j = 0; j <= qcnt; j++){
			x[j] = cur - x[j];
		}
		z[qcnt] = x;
	}
	return z[qcnt][f];
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	string s;
	cin >> s;
	int n = (int)s.size();
	int cnt = -1;
	int lqcnt = 0, rqcnt = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == ')') cnt++;
		if(s[i] == '?') rqcnt++;
	}
	num ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != ')'){
			int f = lqcnt - cnt;
			int qcnt = lqcnt + rqcnt;
			if(f <= qcnt){
				ans += compute_sum(qcnt, max(0, f));
			}
		}
		// upd
		if(i < n){
			if(s[i] == '?') lqcnt++;
			if(s[i+1] == '?') rqcnt--;
			if(s[i] == '(') cnt--;
			if(s[i+1] == ')') cnt--;
		}
	}
	cout << (int)ans << '\n';
}