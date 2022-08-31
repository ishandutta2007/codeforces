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

vector<int> par;
vector<vector<int> > ch;

vector<num> dp(int v){
	vector<num> take, ntake;
	if(ch[v].size() == 0){
		return {0, 0, 1};
	}
	for(int x : ch[v]){
		vector<num> q = dp(x);
		take.push_back(q[1] + q[2]);
		ntake.push_back(q[0] + q[2]);
	}

	int n = take.size();
	num tot = 1;

	num tot0 = 1;
	for(int i = 0; i < n; i++){
		tot = tot * (take[i] + ntake[i]);
		tot0 = tot0 * ntake[i];
	}
	vector<num> ans(3);
	ans[0] = tot0;

	vector<num> pp;
	vector<num> sp;
	for(int q = 0; q < 2; q++){	
		num cur = 1;
		vector<num> part;
		for(int i = 0; i < n; i++){
			part.push_back(cur);
			cur = cur * ntake[i];
		}
		if(q == 0){
			pp = part;
		} else {
			sp = part;
		}
		reverse(ntake.begin(), ntake.end());
	}
	reverse(sp.begin(), sp.end());
	for(int i = 0; i < n; i++){
		ans[1] += pp[i] * sp[i] * take[i];
	}

	ans[2] = tot - ans[0] - ans[1];
	return ans;
}

int main(){
	int n;
	cin >> n;
	par.resize(n);
	ch.resize(n);
	for(int i = 1; i < n; i++){
		cin >> par[i];
		par[i]--;
		ch[par[i]].push_back(i);
	}
	vector<num> ans = dp(0);
	cout << int(ans[0] + ans[2]) << '\n';
}