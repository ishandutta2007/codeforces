#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353, root = 3;
int n, a, b;
ll fac[MX];

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

void ntt (vi &X, int inv) {
	int n = X.size();

	for(int i = 1, j = 0; i < n - 1; i++){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j)
			swap(X[i], X[j]);
	}
	
	vl wp(n >> 1, 1);
	for(int k = 1; k < n; k <<= 1){
		ll wk = pot(root, inv * (mod - 1) / (k << 1));
		
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
		for(int i = 0; i < n; i++)
			X[i] = X[i] * nrev % mod;
	}
}

vi mul (vi &A, vi &B) {
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

ll comb (int n, int k) {
	if (n < k) return 0;
	return fac[n] * pot(fac[k], mod - 2) % mod * pot(fac[n - k], mod - 2) % mod;
}

vi f[MX];
ll sn1 (int n, int k) {
	if (n == 0) return k == 0;

	priority_queue<ii, vii, greater<ii>> pq;
	
	for (int i = 0; i < n; i++) {
		f[i] = {i, 1};
		pq.emplace(2, i);
	}

	while (pq.size() > 1) {
		int a = pq.top().se; pq.pop();
		int b = pq.top().se; pq.pop();

		f[a] = mul(f[a], f[b]);
		f[b].clear();
		pq.emplace(f[a].size(), a);
	}

	int a = pq.top().se; pq.pop();
	if (f[a].size() <= k) return 0;
	return f[a][k];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fac[0] = 1;
	for (ll i = 1; i < MX; i++)
		fac[i] = i * fac[i - 1] % mod;

	cin >> n >> a >> b;
	cout << sn1(n - 1, a + b - 2) * comb(a + b - 2, a - 1) % mod << endl;

	return 0;
}