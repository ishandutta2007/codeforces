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

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<num> powk = {1};
	for(int i = 1; i <= 4 * n; i++){
		powk.push_back(powk.back() * k);
	}
	vector<num> cnt(n+1, 0);
	vector<num> phi(2*n+1);
	vector<num> mu(2*n+1);
	for(int i = 1; i <= 2*n; i++){
		phi[i] = i;
		mu[i] = (i == 1);
	}
	for(int i = 1; i <= 2*n; i++){
		for(int d = 2*i; d <= 2*n; d += i){
			phi[d] -= phi[i];
			mu[d] -= mu[i];
		}
	}

	for(int g = 1; g < n; g++){
		int rmax = (n-1) / g;
		int sum_thresh = rmax + 1;
		vector<num> phi2(2 * rmax + 1, 0);
		for(int i = 1; i <= 2 * rmax; i++){
			for(int d = 1; d <= 2 * rmax / i; d ++){
				phi2[d * i] += (rmax / d) * mu[d];
			}
		}
		for(int s = 2; s <= rmax * 2; s += 1){
			if(s <= sum_thresh){
				cnt[g] += phi[s];
			} else {
				num z = 2 * phi2[s] - phi[s];
				cnt[g * s - n] += z;
			}
		}
	}

	num tot = 0;
	for(int i = 1; i < n; i++){
		tot += powk[i] * cnt[i];
	}
	tot /= powk[n];
	cout << (int)tot << '\n';
}