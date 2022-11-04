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

const int MX = 300005, mod = 998244353, gen = 3;
int n, k, cn[MX], b[MX], res[(1 << 20) + MX], x, y, Q;
vi p, q, r;

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

void ntt (vi &p, int inv){
	int n = p.size();

	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		if (i < j) swap(p[i], p[j]);
	}

	vl wp(n >> 1, 1);
	for (int k = 1; k < n; k <<= 1) {
		ll wk = pot(gen, inv * (mod - 1) / (k << 1));

		for(int j = 1; j < k; ++j)
			wp[j] = wp[j - 1] * wk % mod;
		
		for (int i = 0; i < n; i += k << 1) {
			for (int j = 0; j < k; ++j) {
				int u = p[i + j], v = p[i + j + k] * wp[j] % mod;
				p[i + j] = u + v < mod ? u + v : u + v - mod;
				p[i + j + k] = u - v < 0 ? u - v + mod : u - v;
			}
		}
	}

	if (inv == -1) {
		ll rev = pot(n, mod - 2);
		for(int i = 0; i < n; ++i)
			p[i] = p[i] * rev % mod;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cn[x]++;
	}

	p = {1, 2, 1}, q = {1, 2, 0};
	p.resize(1 << 20), q.resize(1 << 20);
	ntt(p, 1), ntt(q, 1);

	for (int i = 0; i < k; i++) {
		cin >> b[i];

		x = y = 0;
		for (int j = 1; j < b[i]; j++) {
			if (cn[j] >= 2) x++;
			else if (cn[j] >= 1) y++;
		}

		r = vi(1 << 20);
		for (int j = 0; j < (1 << 20); j++)
			r[j] = pot(p[j], x) * pot(q[j], y) % mod;
		ntt(r, -1);

		for (int j = 0; j < (1 << 20); j++)
			(res[j + b[i] + 1] += r[j]) %= mod;
	}

	cin >> Q;
	while (Q--) {
		cin >> x;
		cout << res[x / 2] << endl;
	}

	return 0;
}