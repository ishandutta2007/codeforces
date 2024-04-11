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

const int MX = 1000005, mod = 1000000007;
int n, k, q, bs[MX];
ll phi[MX], inv[MX], cn[MX], f[MX], res;
vi d[MX];

void sum (ll &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	if (a < 0) a += mod;
}

void insert (int n) {
	for (int x : d[n]) {
		cn[x]++;

		if (cn[x] == k) {
			f[x] = 1;
			sum(res, phi[x]);
		} else if (cn[x] > k) {
			sum(res, -phi[x] * f[x] % mod);
			(f[x] *= cn[x]) %= mod;
			(f[x] *= inv[cn[x] - k]) %= mod;
			sum(res, phi[x] * f[x] % mod);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}

	for (int i = 1; i < MX; i++)
		for (int j = i; j < MX; j += i)
			d[j].pb(i);

	inv[0] = inv[1] = 1;
	for (int i = 2; i < MX; i++)
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;

	for (int i = 1; i < MX; i++) {
		phi[i] = 1;

		for (int x = i; x > 1;) {
			int p = bs[x], f = 1;

			while (x % p == 0) {
				x /= p;
				f *= p;
			}

			phi[i] *= f - f / p;
		}
	}

	cin >> n >> k >> q;

	forn (i, n) {
		int in;
		cin >> in;
		insert(in);
	}

	while (q--) {
		int c;
		cin >> c;
		insert(c);
		cout << res << endl;
	}
	
	return 0;
}