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

typedef vector<vvi> mat;
int n, k;

mat operator * (const mat &a, const mat &b) {
	mat c(a.size(), vvi(b[0].size(), vi(1, 0)));
	
	forn (i, a.size())
		forn (j, b[i].size())
			forn (l, b.size()) {
				c[i][j] = c[i][j] + a[i][l] * b[l][j];
	        	
	        	if ((int)c[i][j].size() > k + 1)
	        		c[i][j].resize(k + 1);
	        }
	    		
	return c;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	mat b = {
		{ {1, 1}, {0, 1} },
		{ {1},    {0}    },
	};
	mat res = {
		{ {1}, {0} },
		{ {0}, {1} },
	};
	
	while (n) {
		if (n & 1) res = res * b;
		b = b * b;
		n /= 2;
	}
	
	res[0][0].resize(k + 1);
	for (int i = 1; i <= k; i++)
		cout << res[0][0][i] << " ";
	cout << endl;
	
	return 0;
}