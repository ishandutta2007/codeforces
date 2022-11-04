#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef vector<ll> vl;
const int MX = 1000005, mod = 998244353, root = 3;

ll pot (ll b, ll p) {
	if (p < 0) p += mod - 1;
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int nearestPowerOfTwo (int n) {
	int ans = 1;
	while (ans < n)
		ans <<= 1;
	return ans;
}

void ntt (vi &x, int inv) {
	int n = x.size();

	for(int i = 1, j = 0; i < n - 1; i++){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j)
			swap(x[i], x[j]);
	}
	
	vl wp(n >> 1, 1);
	for(int k = 1; k < n; k <<= 1){
		ll wk = pot(root, inv * (mod - 1) / (k << 1));
		
		for (int j = 1; j < k; ++j)
			wp[j] = wp[j - 1] * wk % mod;
		
		for (int i = 0; i < n; i += k << 1) {
			for (int j = 0; j < k; ++j) {
				int u = x[i + j], v = x[i + j + k] * wp[j] % mod;
				x[i + j] = u + v < mod ? u + v : u + v - mod;
				x[i + j + k] = u - v < 0 ? u - v + mod : u - v;
			}
		}
	}

	if (inv == -1) {
		ll nrev = pot(n, mod - 2);
		for(int i = 0; i < n; i++)
			x[i] = x[i] * nrev % mod;
	}
}

vi mul (vi &a, vi &b) {
	int sz = a.size() + b.size() - 1;
	int size = nearestPowerOfTwo(sz);
	
	a.resize(size), b.resize(size);
	ntt(a, 1), ntt(b, 1);
	
	for(int i = 0; i < size; i++)
		a[i] = 1ll * a[i] * b[i] % mod;
	
	ntt(a, -1);
	a.resize(sz);
	
	return a;
}

int p[MX];
ll at[MX], as[MX], f[MX];
string s, t;
vi a, b;

ll sum (ll acu[], int a, int b) {
	if (a > b) return 0;
	if (a) return acu[b] - acu[a - 1];
	return acu[b];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<> dis(0, mod - 1);

	for (int i = 1; i <= 26; i++) {
		cin >> p[i];
		f[i] = dis(rng);
	}

	cin >> s >> t;

	forn (i, s.size()) {
		int c = s[i] - 'a' + 1;
		a.pb((f[c] + f[p[c]]) % mod);
		as[i] = f[c] * f[p[c]] % mod;
		if (i) (as[i] += as[i - 1]) %= mod;
	}

	forn (i, t.size()) {
		int c = t[i] - 'a' + 1;
		b.pb(f[c]);
		at[i] = f[c] * f[c] % mod;
		if (i) (at[i] += at[i - 1]) %= mod;
	}

	reverse(all(a));
	a = mul(a, b);

	for (int i = 0; i + s.size() <= t.size(); i++) {
		ll x = sum(at, i, i + int(s.size()) - 1) + as[int(s.size()) - 1] - a[i + (int)s.size() - 1];
		cout << 1 - bool(MOD(x, mod));
	}
	cout << endl;

	return 0;
}