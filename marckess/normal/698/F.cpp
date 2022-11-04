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

const int MX = 1000005, mod = 1000000007;
int n, p[MX], bs[MX], f[MX], inv[MX], cn[MX], y[MX], ex[MX];
ll fac[MX], a[MX], b[MX], res = 1;
vi fp[MX];

void no () {
	cout << 0 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	fac[0] = fac[1] = 1;
	for (int i = 2; i < MX; i++) {
		fac[i] = fac[i-1] * i % mod;
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = 1ll * i * i; j < MX; j += i)
				bs[j] = i;
		}
	} 

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];

		if (i == 1) {
			cn[1] = 1;
			fp[1].pb(1);
		} else {
			int x = i;
			y[i] = 1;
			
			while (x > 1) {
				int p = bs[x];
				cn[p]++;
				fp[i].pb(p);
				y[i] *= p;

				while (x % p == 0)
					x /= p;
			}

			b[y[i]]++;
		}
	}

	for (int i = 1; i <= n; i++) 
		if (p[i]) {
			vi &v = fp[i];
			vi &w = fp[p[i]];

			if (v.size() != w.size()) no ();
			sort(all(v)), sort(all(w));

			for (int j = 0; j < v.size(); j++) {
				if (!f[v[j]]) {
					if (cn[v[j]] != cn[w[j]]) no();
					if (inv[w[j]]) no();
					ex[v[j]] = 1;
					f[v[j]] = w[j];
					inv[w[j]] = v[j];
				} else if (f[v[j]] != w[j]) {
					no();
				}
			}

			b[y[i]]--;
		}

	for (int i = 1; i <= n; i++)
		if (!ex[i])
			a[cn[i]]++;

	for (int i = 1; i <= n; i++) {
		(res *= fac[a[i]]) %= mod;
		(res *= fac[b[i]]) %= mod;
	}

	cout << res << endl;

	return 0;
}