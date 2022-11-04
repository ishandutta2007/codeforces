#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353, g = 3;
int n, a[MX], b[MX];
ll fac[MX], inv[MX];

ll pot (ll b, ll p) {
	ll res = 1;
	if (p < 0) p += mod - 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int nearestPowerOfTwo (int n) {
	int ans = 1;
	while (ans < n) ans <<= 1;
	return ans;
}

void ntt (vi &X, int inv) {
	int n = X.size();
	
	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	
	vector<ll> wp(n >> 1, 1);
	for (int k = 1; k < n; k <<= 1) {
		ll wk = pot(g, inv * (mod - 1) / (k << 1));
		
		for (int j = 1; j < k; ++j)
			wp[j] = wp[j - 1] * wk % mod;
		
		for (int i = 0; i < n; i += k << 1) {
			for (int j = 0; j < k; ++j) {
				int u = X[i + j], v = X[i + j + k] * wp[j] % mod;
				X[i + j] = u + v < mod ? u + v : u + v - mod;
				X[i + j + k] = u - v < 0 ? u - v + mod : u - v;
			}
		}
	}
	
	if (inv == -1) {
		ll nrev = pot(n, mod - 2);
		for(int i = 0; i < n; ++i)
			X[i] = X[i] * nrev % mod;
	}
}

vi convolution (vi A, vi B){
	int sz = A.size() + B.size() - 1;
	int size = nearestPowerOfTwo(sz);
	
	A.resize(size), B.resize(size);
	ntt(A, 1), ntt(B, 1);
	
	for(int i = 0; i < size; i++)
		A[i] = 1ll * A[i] * B[i] % mod;
	
	ntt(A, -1);
	A.resize(sz);
	
	return A;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = i * fac[i - 1] % mod;
		inv[i] = pot(fac[i], mod - 2);
	}
	
	cin >> n;
	forn (i, n) cin >> a[i] >> b[i];
	
	vi res = {1};
	forn (i, n) {
		int sz = (int)res.size() + a[i] - b[i];
		int ini = max(0, b[i] - (int)res.size() + 1);
		int fin = min(a[i] + b[i], b[i] + sz - 1);
		
		vi p(fin - ini + 1);
		forn (j, p.size())
			p[j] = comb(a[i] + b[i], ini + j);
		
		vi q = convolution(res, p);
		
		res.resize(sz);
		for (int j = 0, k = b[i] - ini; j < sz; j++, k++)
			res[j] = q[k];
	}
	
	cout << accumulate(all(res), 0, [&] (int a, int b) {
		return (a + b) % mod;
	}) % mod << endl;

	return 0;
}