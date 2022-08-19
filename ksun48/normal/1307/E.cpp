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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<int(1e9) + 7>;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> grass(n);
	vector<vector<int> > cows(n);
	for(int i = 0; i < n; i++){
		cin >> grass[i];
		grass[i]--;
	}
	for(int i = 0; i < m; i++){
		int f, h;
		cin >> f >> h;
		f--;
		cows[f].push_back(h);
	}
	for(int i = 0; i < n; i++){
		sort(cows[i].begin(), cows[i].end());
	}
	int best = -1;
	num ans = 0;
	for(int cut = -1; cut < n; cut++){
		vector<int> lgrass(n, 0), rgrass(n, 0);
		for(int j = 0; j <= cut; j++) lgrass[grass[j]]++;
		for(int j = cut+1; j < n; j++) rgrass[grass[j]]++;
		int special = -1;
		if(cut >= 0) special = grass[cut];

		int cbest = 0;
		num cans = 1;
		for(int b = 0; b < n; b++){
			if(b == special){
				if(find(cows[b].begin(), cows[b].end(), lgrass[b]) == cows[b].end()){
					goto failed;
				}
				cbest += 1;
				int nc = 0;
				for(int f : cows[b]){
					if(f != lgrass[b] && f <= rgrass[b]){
						nc++;
					}
				}
				if(nc){
					cbest += 1;
					cans *= nc;
				}
			} else {
				int ok1 = 0;
				int ok2 = 0;
				for(int f : cows[b]){
					if(f <= lgrass[b]) ok1++;
					if(f <= rgrass[b]) ok2++;
				}
				int res = (ok1 * ok2) - min(ok1, ok2);
				if(res > 0){
					cbest += 2;
					cans *= res;
				} else if(ok1 > 0 || ok2 > 0){
					cbest += 1;
					cans *= (ok1 + ok2);
				}
			}
		}
		if(cbest > best){
			best = cbest;
			ans = 0;
		}
		if(cbest == best) ans += cans;
		failed:;
	}
	cout << best << ' ' << ans << '\n';
}