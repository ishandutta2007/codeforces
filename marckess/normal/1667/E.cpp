// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

using poly = vector<ll>;

const int MX = 200005, mod = 998244353, g = 3;

int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}

ll powerMod(ll b, ll e, ll m){
	ll ans = 1;
	e %= m-1;
	if(e < 0) e += m-1;
	while(e){
		if(e & 1) ans = ans * b % m;
		e >>= 1;
		b = b * b % m;
	}
	return ans;
}

void ntt(poly & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	vector<ll> wp(n>>1, 1);
	for(int k = 1; k < n; k <<= 1){
		ll wk = powerMod(g, inv * (mod - 1) / (k<<1), mod);
		for(int j = 1; j < k; ++j)
			wp[j] = wp[j - 1] * wk % mod;
		for(int i = 0; i < n; i += k << 1){
			for(int j = 0; j < k; ++j){
				int u = X[i + j], v = X[i + j + k] * wp[j] % mod;
				X[i + j] = u + v < mod ? u + v : u + v - mod;
				X[i + j + k] = u - v < 0 ? u - v + mod : u - v;
			}
		}
	}
	if(inv == -1){
		ll nrev = powerMod(n, mod - 2, mod);
		for(int i = 0; i < n; ++i)
			X[i] = X[i] * nrev % mod;
	}
}

poly convolution(poly A, poly B){
	int sz = A.size() + B.size() - 1;
	int size = nearestPowerOfTwo(sz);
	A.resize(size), B.resize(size);
	ntt(A, 1), ntt(B, 1);
	for(int i = 0; i < size; i++)
		A[i] = (ll)A[i] * B[i] % mod;
	ntt(A, -1);
	A.resize(sz);
	return A;
}

int n, m;
ll fac[MX], inv[MX];

void main_() {
	cin >> n;
	m = n / 2;
	
	poly A(n), B(n - m - 1);
	
	forr (i, m + 1, n - 1)
		A[i] = fac[n - i - 1] * powerMod(i, -1, mod) % mod;
	
	forr (i, 0, n - m - 2)
		B[i] = inv[n - m - 2 - i];
	
	reverse(all(B));
	auto C = convolution(A, B);
	
	ll acu = 0;
	forr (k, 1, n) {
		ll res = C[n - k];
		(res *= k) %= mod;
		(res *= fac[n - k]) %= mod;
		res = (fac[n - 1] - res) % mod;
		(res -= acu) %= mod;
		
		cout << MOD(res, mod) << " ";
		
		(acu += res) %= mod;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	forr (i, 1, MX - 1) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = powerMod(fac[i], -1, mod);
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}