
// Problem : F. Tree Coloring
// Contest : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1613/problem/F
// Memory Limit : 512 MB
// Time Limit : 4500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 250005, mod = 998244353, g = 3;
const ll inv2 = (mod + 1) / 2;

int n;
ll fac[MX], inv[MX];
map<int, int> mp; 
vi adj[MX], p[MX];

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

ll comb (int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void main_() {
	cin >> n;
	
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	for (int i = 1; i <= n; i++)
		mp[(int)adj[i].size() - (1 < i)]++;
	mp.erase(0);
	
	priority_queue<ii, vii, greater<ii>> pq;
	for (auto it : mp) {
		p[it.fi].resize(it.se + 1);
		for (int i = 0; i <= it.se; i++)
			p[it.fi][i] = comb(it.se, i) * pot(it.fi, i) % mod;
		pq.emplace(p[it.fi].size(), it.fi);
	}
	
	while (pq.size() > 1) {
		int a = pq.top().se; pq.pop();
		int b = pq.top().se; pq.pop();
		
		p[a] = p[a] * p[b];
		pq.emplace(p[a].size(), a);
	}
	
	int a = pq.top().se; pq.pop();
	
	ll res = 0;
	forn (i, p[a].size())
		(res += (i % 2 == 0 ? 1 : -1) * fac[n - i] * p[a][i]) %= mod;
	cout << MOD(res, mod) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], -1);
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}