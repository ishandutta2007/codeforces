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
	fact.push_back(1);
	for(int i = 1; i <= 2e6; i++){
		fact.push_back(fact.back() * i);
	}
	ifact.resize(fact.size());
	ifact.back() = 1 / fact.back();
	for(int i = (int)fact.size() - 1; i >= 1; i--){
		ifact[i-1] = ifact[i] * i;
	}
}

num ncr(int n, int k){
	if(n < k) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int k;
	cin >> k;
	vector<int> a(k);
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());


	num ans = 0;
	ans += 1;

	multiset<int> v;
	vector<int> freq(a.back() + 1, 0);
	for(int x : a){
		freq[x]++;
		v.insert(x);
	}

	vector<int> modfreq(k, 0);
	int forced_moves = 0;

	int sum = 0;

	for(int b = 1; b <= a.back(); b++){
		// is it possible to make b moves?
		v.insert(*v.begin() + k);
		v.erase(v.begin());
		if(*v.begin() < b) break;
		// add something to ans;

		sum += freq[b-1];
		modfreq[(b-1) % k] += freq[b-1];
		forced_moves += modfreq[(b-1) % k];
		assert(forced_moves <= b);


		num v = ncr(b - forced_moves + k-1, k-1) 
		- ncr(b - forced_moves + k-1 - (k - sum), k-1);
		ans += v;
	}
	cout << (int)(ans) << '\n';
}