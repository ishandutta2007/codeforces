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
	const int n = 6;
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
	const int f = 20;
	vector<vector<num> > sets(2, vector<num>(1 << f, 0));
	vector<vector<int> > masks(2);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < j; k++){
				masks[0].push_back((1 << i) ^ (1 << j) ^ (1 << k));
				masks[1].push_back(((1 << n) - 1) ^ masks[0].back());
			}
		}
	}
	assert(f == masks[0].size());
	for(int t = 0; t < 2; t++){
		for(int e = 0; e < (1 << (n/2 * n)); e++){
			num prob = 1;
			int edges[n/2];
			for(int i = 0; i < n/2; i++) edges[i] = 0;
			for(int i = 0; i < n/2 * n; i++){
				bool r = (e >> i) & 1;
				num pp = p[(i / n) * 2 + t][i % n];
				prob *= r ? pp : (1 - pp);
				edges[i/n] |= int(r) << (i % n);
			}
			int work_mask = 0;
			for(int a = 0; a < (int)masks[t].size(); a++){
				int mask = masks[t][a];
				int r[n/2];
				for(int i = 0; i < n/2; i++) r[i] = edges[i] & mask;
				if(r[0] && r[1] && r[2]){
					if(__builtin_popcount(r[0] | r[1] | r[2]) == 3){
						int x = __builtin_popcount(r[0] | r[1]);
						int y = __builtin_popcount(r[0] | r[2]);
						int z = __builtin_popcount(r[1] | r[2]);
						if(x >= 2 && y >= 2 && z >= 2){
							work_mask |= (1 << a);
						}
					}
				}
			}
			sets[t][work_mask] += prob;
		}
	}
	for(int i = 0; i < f; i++){
		for(int j = 0; j < (1 << f); j++){
			if((j >> i) & 1) continue;
			sets[0][j ^ (1 << i)] += sets[0][j];
		}
	}
	num ans = 0;
	for(int j = 0; j < (1 << f); j++){
		ans += sets[0][j] * sets[1][((1 << f) - 1) ^ j];
	}
	ans = 1 - ans;
	cout << (int)ans << '\n';
}