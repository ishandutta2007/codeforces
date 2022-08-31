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

num ans = 0;

using segList = vector<pair<ll,ll> >;

segList cut(segList a, ll mask, bool dir){
	segList b;
	for(pair<ll, ll> x : a){
		x.first = max(x.first - mask * ll(dir), mask * 0);
		x.second = min(x.second - mask * ll(dir), mask);
		if(x.first >= x.second) continue;
		b.push_back(x);
	}
	return b;
}

void solve(vector<pair<segList, segList> > q, ll bmask, ll top){
	if(q.empty()) return;
	/*cerr << " === " << bmask << ' ' << top << '\n';
	for(pair<segList, segList>& r : q){
		for(pair<ll, ll> a : r.first){
			cerr << "[" << a.first << ' ' << a.second << "] ";
		}
		cerr << " x ";
		for(pair<ll, ll> a : r.second){
			cerr << "[" << a.first << ' ' << a.second << "] ";
		}
		cerr << '\n';
	}*/
	bool done = false;
	for(pair<segList, segList>& r : q){
		assert(!r.first.empty());
		assert(!r.second.empty());
		for(pair<ll, ll> a : r.first){
			if(a.first == 0 && a.second == bmask) done = true;
		}
		for(pair<ll, ll> a : r.second){
			if(a.first == 0 && a.second == bmask) done = true;
		}
	}
	if(done){
		ans += num(top) * num(bmask) + num(bmask) * num(bmask - 1) / num(2);
		return;
	}
	ll mask = bmask >> 1;
	vector<pair<segList, segList> > d[4];
	for(pair<segList, segList>& r : q){
		for(int x = 0; x < 2; x++){
			for(int y = 0; y < 2; y++){
				segList f = cut(r.first, mask, x), g = cut(r.second, mask, y);
				if(!f.empty() && !g.empty()) d[(x << 1) ^ y].push_back({f, g});
			}
		}
	}
	d[0].insert(d[0].end(), d[3].begin(), d[3].end());
	d[1].insert(d[1].end(), d[2].begin(), d[2].end());
	solve(d[0], mask, top);
	solve(d[1], mask, top + mask);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int A;
	cin >> A;
	vector<pair<ll,ll> > As(A);
	for(int i = 0; i < A; i++){
		cin >> As[i].first >> As[i].second;
		As[i].second++;
	}
	int B;
	cin >> B;
	vector<pair<ll,ll> > Bs(B);
	for(int i = 0; i < B; i++){
		cin >> Bs[i].first >> Bs[i].second;
		Bs[i].second++;
	}
	solve({{As, Bs}}, 1ll << 61, 0);
	cout << (int)ans << '\n';
}