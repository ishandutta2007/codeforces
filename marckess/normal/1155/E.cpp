#include <bits/stdc++.h>

//#define endl '\n'
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 1000003;
vi a(1000003);
vvi m(11, vi(12));

ll pot (ll b, int p) {
	ll ans = 1;
	while (p) {
		if (p & 1) (ans *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return ans;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	iota(all(a), 0);

	bool f = 0;
	while (!f) {
		random_shuffle(all(a));

		for (int i = 0; i < 11; i++) {
			cout << "? " << a[i] << endl;
			int r;
			cin >> r;
			if (r == -1) exit(0);

			m[i].back() = r;
			ll x = 1;
			for (int j = 0; j < 11; j++) {
				m[i][j] = x;
				(x *= a[i]) %= mod;
			}
		}

		for (int i = 0; i < 11; i++) {
			f = 0;

			for (int j = i; j < 11; j++)
				if (m[i][j]) {
					swap(m[i], m[j]);
					f = 1;
					break;
				}

			if (!f) break;

			ll in = pot(m[i][i], mod - 2);
			for (int j = i; j < 12; j++)
				(m[i][j] *= in) %= mod;

			for (int j = 0; j < 11; j++)
				if (i != j) {
					ll c = m[j][i];
					for (int k = i; k < 12; k++) {
						m[j][k] -= c * m[i][k];
						m[j][k] = MOD(m[j][k], mod);
					}
				}
		}
	}

	for (int i = 0; i < 11; i++)
		a[i] = m[i].back();

	for (int i = 0; i < mod; i++) {
		ll x = 1, s = 0;
		for (int j = 0; j < 11; j++) {
			s += x * a[j];
			x *= i;
			x %= mod;
		}
		s %= mod;
		if (!s) {
			cout << "! " << i << endl;
			return 0;
		}
	}

	cout << "! " << -1 << endl;

	return 0;
}