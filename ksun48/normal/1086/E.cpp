#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = (119 << 23) + 1, root = 3; // = 998244353
ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

// probability of exactly k monkeys defeating everyone else
// that group must be unique
// choose k monkeys, then it's a bunch of p's and a bunch of (1-p)'s
// # of 1-p's = sum of indices of the k - (k choose 2)
// take the product of (1 + (1-p)^i p^(n-1-i) x)
// what's P_{a,n}(x) = product_{i=0^n-1} (1 + a^i x)

int modinv(int a, int m) {
	a %= m;
	assert(a > 0);
	if (a == 1) return 1;
	return m - int(((long long)modinv(m, a)) * m / a);
}
template <int MOD_> struct modnum {
	using ll = long long;
	static const int MOD = MOD_;
	private:
	int v;
	public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () { return v; }

	friend std::ostream& operator << (std::ostream& o, const modnum& m) { return o << m.v; }
	modnum operator - () const {
		modnum res;
		res.v = (v ? MOD - v : 0);
		return res;
	}
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

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }

	modnum pow(ll e) const {
		assert(e >= 0);
		modnum r = 1;
		modnum a = *this;
		while (e) {
			if (e & 1) r *= a;
			a *= a, e /= 2;
		}
		return r;
	}

	ll get(){
		return v;
	}
};
using num = modnum<998244353>;
const num PRIMITIVE_ROOT = 3;
template <typename num> struct fft {
	const int L;
	const int N = (1 << L);
	using num_t = num;

	const num root;
	const num invRoot = num(1) / root;
	const num invN = num(1) / num(N);
	num roots[30+1];
	num invRoots[30+1];
	fft(int L_, num root_) : L(L_), root(root_) {
		roots[0] = root;
		invRoots[0] = invRoot;
		for (int i = 1; i <= L; i++) {
			roots[i] = roots[i-1] * roots[i-1];
			invRoots[i] = invRoots[i-1] * invRoots[i-1];
		}
		assert(roots[L] == 1);
		assert(invRoots[L] == 1);
	}

	void bitReversal(num* a) {
		for (int i = 1, j = 0; i < N-1; i++) {
			for (int k = N / 2; k > (j ^= k); k /= 2);
			if (j < i) {
				std::swap(a[j], a[i]);
			}
		}
	}

	void operator () (num* a, bool inv = false) {
		bitReversal(a);
		for (int l = 1, p = 0; l < N; l <<= 1, p++) {
			num w = inv ? invRoots[L - p - 1] : roots[L - p - 1];
			for (int k = 0; k < N; k += (2 * l)) {
				num v = 1;
				for (int i = k; i < k + l; i++, v *= w) {
					num x = a[i];
					num y = v * a[i+l];
					a[i] = x + y;
					a[i+l] = x - y;
				}
			}
		}
		if (inv) {
			for (int i = 0; i < N; i++) {
				a[i] *= invN;
			}
		}
	}
};
void conv(vector<num>& a, vector<num> b) {
	int s = int(a.size()) + int(b.size()) - 1;
	if (s <= 0) {
		a.clear();
		return;
	}
	if (s <= 200) {
		vector<num> c(s);
		for (int i = 0; i < int(a.size()); i++) {
			for (int j = 0; j < int(b.size()); j++) {
				c[i+j] += a[i] * b[j];
			}
		}
		a = c;
		return;
	}
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	fft<num> f(L, PRIMITIVE_ROOT.pow((num::MOD-1) / n));
	a.resize(n); f(&a[0], false);
	b.resize(n); f(&b[0], false);
	for (int i = 0; i < n; i++) a[i] *= b[i];
	f(&a[0], true); a.resize(s);
}

const LL MOD = mod;

LL dp[2100][2100];
LL ncr[2100][2100];
LL fact[2100];
void init(){
	for(int n = 0; n <= 2000; n++){
		for(int k = 0; k <= 2000; k++){
			if(k == 0 || k == n){
				ncr[n][k] = 1;
			} else if(k > n){
				ncr[n][k] = 0;
			} else {
				ncr[n][k] = (ncr[n-1][k] + ncr[n-1][k-1]) % MOD;
			}
		}
	}
	fact[0] = 1;
	for(int i = 1; i <= 2000; i++){
		fact[i] = (i * fact[i-1]) % MOD;
	}
	for(int k = 0; k <= 2000; k++){
		vector<num> f(2000+1, 0);
		for(int i = 0; i <= 2000; i++){
			f[i] = fact[i];
		}
		vector<num> stuff(k+1, 0);
		for(int i = 0; i <= k; i++){
			stuff[i] = ncr[k][i];
			if(i % 2 == 1) stuff[i] = MOD - stuff[i];
		}
		conv(f, stuff);
		for(int a = k; a <= 2000; a++){
			dp[a][k] = f[a].get();
			if(dp[a][k] < 0) dp[a][k] += MOD;
		}
	}	
}
int perm[2100][2100];
int BIT0[2100];
void upd0(int a, int v){
	while(a < 2100){
		BIT0[a] += v;
		a += a & -a;
	}
}
int q0(int a){
	int v = 0;
	while(a > 0){
		v += BIT0[a];
		a -= a & -a;
	}
	return v;
}
int BIT1[2100];
void upd1(int a, int v){
	while(a <= 2000){
		BIT1[a] += v;
		a += a & -a;
	}
}
int q1(int a){
	int v = 0;
	while(a > 0){
		v += BIT1[a];
		a -= a & -a;
	}
	return v;
}
bool occ1[2100];
bool occ2[2100];
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> perm[i][j];
			perm[i][j]--;
		}
	}
	LL ans = 0;
	{
		LL mult0 = modpow(dp[n][n], n-1);
		for(int j = 1; j <= n; j++){
			upd0(j, 1);
		}
		LL r0 = 0;
		for(int j = 0; j < n; j++){
			upd0(perm[0][j] + 1, -1);
			LL nless = q0(perm[0][j] + 1);
			r0 = (r0 + nless * fact[n-1-j]) % MOD;
		}
		ans = (ans + r0 * mult0) % MOD;
	}
	for(int a = 1; a < n; a++){
		LL mult = modpow(dp[n][n], n-1-a);
		for(int i = 0; i <= n; i++){
		}
		int shared = 0;
		LL cans = 0;
		for(int b = n-1; b >= 0; b--){
			occ2[perm[a][b]] = 1;
			if(occ1[perm[a][b]]){
				shared++;
				upd1(perm[a][b]+1, 1);
			}
			upd0(perm[a][b]+1, 1);

			int tot = q0(perm[a][b]);
			int sh = q1(perm[a][b]);
			tot -= sh;
			if(perm[a-1][b] < perm[a][b] && occ2[perm[a-1][b]]){
				tot--;
			}
			if(shared){
				cans += sh * dp[n-1-b][shared - 1];
			}
			cans += tot * dp[n-1-b][shared];
			cans %= MOD;

			occ1[perm[a-1][b]] = 1;
			if(occ2[perm[a-1][b]]){
				shared++;
				upd1(perm[a-1][b]+1, 1);
			}
		}
		ans = (ans + cans * mult) % MOD;
		for(int b = 0; b <= 2050; b++){
			occ1[b] = occ2[b] = BIT0[b] = BIT1[b] = 0;
		}
	}
	ans %= MOD;
	if(ans < 0) ans += MOD;
	cout << ans << endl;
}