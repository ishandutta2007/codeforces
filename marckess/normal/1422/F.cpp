#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005, mod = 1000000007;

struct PST {
	PST *izq, *der;
	ll x;
	
	PST () : izq(0), der(0), x(1) {}
	PST (PST *_izq, PST *_der) {
		izq = _izq, der = _der;
		x = izq->x * der->x % mod;
	}
	PST (ll x) : izq(0), der(0), x(x) {}
	
	void build (int i, int j) {
		if (i == j) return;
		int m = (i + j) / 2;
		(izq = new PST())->build(i, m);
		(der = new PST())->build(m + 1, j);
	}
	
	PST * update (int i, int j, int a, ll k) {
		if (j < a || a < i) return this;
		if (i == j) return new PST (x * k % mod);
		int m = (i + j) / 2;
		return new PST (
			izq->update(i, m, a, k),
			der->update(m + 1, j, a, k)
		);
	}
	
	ll query (int i, int j, int a, int b) {
		if (j < a || b < i) return 1;
		if (a <= i && j <= b) return x;
		int m = (i + j) / 2;
		return izq->query(i, m, a, b) * der->query(m + 1, j, a, b) % mod;
	}
};

int n, q, last, bs[MX], inv[MX];
PST *st[MX];
vi ant[MX], pos[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	inv[1] = 1;
	
	for (ll i = 2; i < MX; i++) {
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
		inv[i] = pot(i, mod - 2);
	}
	
	cin >> n;
	
	(st[0] = new PST())->build(1, n);
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		
		st[i] = st[i - 1]->update(1, n, i, a);
		
		while (a > 1) {
			int p = bs[a], f = 1, _f;
			
			while (a % p == 0) {
				f *= p;
				a /= p;
			}
			
			_f = f;
			
			while (f > 1 && ant[p].size()) {
				if (f >= ant[p].back()) {
					st[i] = st[i]->update(1, n, pos[p].back(), inv[ant[p].back()]);
					f /= ant[p].back();
					
					ant[p].pop_back();
					pos[p].pop_back();
				} else {
					st[i] = st[i]->update(1, n, pos[p].back(), inv[f]);
					ant[p].back() /= f;
					
					f = 1;
				}
			}
			
			ant[p].pb(_f);
			pos[p].pb(i);
		}
	}
	
	cin >> q;
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		l = (l + last) % n + 1;
		r = (r + last) % n + 1;
		if (l > r) swap(l, r);
		
		last = st[r]->query(1, n, l, r);
		
		cout << last << endl;
	}
	
	return 0;
}