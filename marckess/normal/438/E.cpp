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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 998244353, g = 3;
const ll inv2 = (mod + 1) / 2;

ll pot (ll b, int p) {
	if (p < 0) {
		p %= mod - 1;
		p += mod - 1;
	}
	
	ll res = 1;
	while (p) {
		if (p & 1)
			(res *= b) %= mod;
		(b *= b) %= mod;
		p >>= 1;
	}
	return res;
}

int npo2 (int n) {
	int res = 1;
	while(res < n)
		res <<= 1;
	return res;
}

void ntt (vi &X, int inv) {
	int n = X.size();
	
	for (int i = 1, j = 0; i < n - 1; i++) {
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		if (i < j)
			swap(X[i], X[j]);
	}
	
	vector<ll> wp(n >> 1, 1);
	for (int k = 1; k < n; k <<= 1) {
		ll wk = pot(g, inv * (mod - 1) / (k << 1));
		
		for (int j = 1; j < k; j++)
			wp[j] = wp[j - 1] * wk % mod;
		
		for (int i = 0; i < n; i += k << 1) {
			forn (j, k) {
				int u = X[i + j], v = X[i + j + k] * wp[j] % mod;
				X[i + j] = u + v < mod ? u + v : u + v - mod;
				X[i + j + k] = u - v < 0 ? u - v + mod : u - v;
			}
		}
	}
	
	if (inv == -1) {
		ll nrev = pot(n, mod - 2);
		forn (i, n)
			X[i] = X[i] * nrev % mod;
	}
}

vi operator + (vi A, vi B) {
	if (A.size() < B.size())
		swap(A, B);
		
	forn (i, B.size()) {
		A[i] += B[i];
		if (A[i] >= mod) A[i] -= mod;
		if (A[i] < 0) A[i] += mod;
	}
	
	return A;
}

vi operator - (vi A) {
	for (auto &a : A) {
		a = -a;
		if (a < 0) a += mod;
	}
	return A;
}

vi operator - (vi A, vi B) {
	forn (i, B.size()) {
		if (i < A.size())
			A[i] -= B[i];
		else
			A.pb(-B[i]);
		
		if (A[i] >= mod) A[i] -= mod;
		if (A[i] < 0) A[i] += mod;
	}
	
	return A;
}

vi operator * (int k, vi A) {
	for (auto &a : A) {
		a = 1ll * a * k % mod;
		if (a < 0) a += mod;
	}
	return A;
}

vi operator * (vi A, vi B){
	int sz = A.size() + B.size() - 1;
	int size = npo2(sz);
	A.resize(size), B.resize(size);
	
	ntt(A, 1), ntt(B, 1);
	for(int i = 0; i < size; i++)
		A[i] = 1ll * A[i] * B[i] % mod;
	ntt(A, -1);
	
	A.resize(sz);
	return A;
}

vi inv (const vi &A) {
	assert(A.size() && A[0]);
	vi R(1, pot(A[0], mod - 2));
	
	while (R.size() < A.size()) {
		int c = 2 * R.size();
		R.resize(c);
		
		vi R2 = R, a(min(c, (int)A.size()));
		forn (i, a.size())
			a[i] = A[i];
			
		R2 = R2 * R2;
		R2.resize(c);
		R2 = a * R2;
		
		forn (i, c) {
			R[i] = R[i] + R[i] - R2[i];
			if (R[i] < 0) R[i] += mod;
			if (R[i] >= mod) R[i] -= mod;
		} 
	}
	
	R.resize(A.size());
	return R;
}

vi sqrt (const vi& A) {
	vi R(1, 1);
	assert(R[0] * R[0] % mod == A[0]);
	
	while (R.size() < A.size()) {
		int c = 2 * R.size();
		R.resize(c);
		
		vi a(min(c, (int)A.size()));
		forn (i, a.size())
			a[i] = A[i];
		a = a * inv(R);
		
		forn (i, c) {
			R[i] = R[i] + a[i];
			if (R[i] >= mod) R[i] -= mod;
			R[i] = 1ll * R[i] * inv2 % mod;
		}
	}
	
	R.resize(A.size());
	return R;
}

int n, m;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	vi c(m + 1);
	forn (i, n) {
		int in;
		cin >> in;
		if (in <= m)
			c[in] = 1;
	}
	
	vi _1 = {1};
	vi r = 2 * inv(_1 + sqrt(_1 - 4 * c));
	
	for (int i = 1; i <= m; i++)
		cout << r[i] << endl;
	
	return 0;
}