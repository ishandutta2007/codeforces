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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, mod = 998244353, gen = 3;

ll pot (ll b, ll p) {
	ll res = 1;
	p = MOD(p, mod - 1);
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int npt (int n) {
	int res = 1;
	while (res < n) res <<= 1;
	return res;
}

void ntt (vi &x, int inv) {
	int n = x.size();

	for (int i = 1, j = 0; i < n - 1; i++) {
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if (i < j) swap(x[i], x[j]);
	}
	
	vl wp(n >> 1, 1);
	for (int k = 1; k < n; k <<= 1){
		ll wk = pot(gen, inv * (mod - 1) / (k << 1));
		
		for (int j = 1; j < k; j++)
			wp[j] = wp[j - 1] * wk % mod;

		for (int i = 0; i < n; i += k << 1) {
			for (int j = 0; j < k; j++){
				int u = x[i + j], v = x[i + j + k] * wp[j] % mod;
				x[i + j] = u + v < mod ? u + v : u + v - mod;
				x[i + j + k] = u - v < 0 ? u - v + mod : u - v;
			}
		}
	}

	if (inv == -1){
		ll nrev = pot(n, mod - 2);
		for(int i = 0; i < n; ++i)
			x[i] = x[i] * nrev % mod;
	}
}

int n;
map<int, int> mp;
vi x[MX];
priority_queue<ii, vii, greater<ii>> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while (n--) {
		int p;
		cin >> p;
		mp[p]++;
	}

	int i = 0;
	for (auto it = mp.begin(); it != mp.end(); it++, i++) {
		x[i] = vi(it->se + 1, 1);
		pq.emplace(it->se + 1, i);
	}

	while (pq.size() > 1) {
		ii a = pq.top(); pq.pop();
		ii b = pq.top(); pq.pop();

		n = npt(a.fi + b.fi - 1);
		x[a.se].resize(n); ntt(x[a.se], 1);
		x[b.se].resize(n); ntt(x[b.se], 1);

		for (int i = 0; i < n; i++)
			x[a.se][i] = 1ll * x[a.se][i] * x[b.se][i] % mod;
		ntt(x[a.se], -1);

		x[b.se].clear();
		pq.emplace(a.fi + b.fi - 1, a.se);
	}

	ii a = pq.top();
	cout << x[a.se][a.fi / 2] << endl;

	return 0;
}