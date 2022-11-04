#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e5+5;
int n, m, mod, a[MX], b[MX], cn[MX], g;
ll res = 0;
bitset<MX> pos;
vi d;

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> mod;

	forn (i, n) cin >> a[i];

	g = mod - 1;
	for (int i = 1; i * i <= mod - 1; i++)
		if ((mod - 1) % i == 0) {
			d.pb(i);
			if (i * i < mod - 1)
				d.pb((mod - 1) / i);
		}
	sort(all(d));

	forn (i, m) {
		cin >> b[i];
		g = gcd(g, b[i]);
	}

	forn (i, n) {
		a[i] = pot(a[i], g);

		forn (j, d.size())
			if (pot(a[i], d[j]) == 1) {
				pos[d.size() - j - 1] = 1;
				break;
			}
	}

	forn (i, d.size())
		if (pos[i]) {
			int p = 1 - cn[i];
			res += p * ll(mod - 1) / d[i];

			for (int j = i + 1; j < d.size(); j++) 
				if (d[j] % d[i] == 0) {
					cn[j] += p;
					pos[j] = 1;
				}
		}

	cout << res << endl;

	return 0;
}