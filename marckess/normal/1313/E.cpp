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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 1000005;

vi obtZF (string &s) {
	int n = s.size();
	vi zf(n);

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			zf[i] = min (r - i + 1, zf[i - l]);

		while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
			zf[i]++;
		
		if (i + zf[i] - 1 > r)
			l = i, r = i + zf[i] - 1;
	}

	return zf;
}

void update (int i, int k, ll ft[]) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i, ll ft[]) {
	ll s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ll query (int a, int b, ll ft[]) {
	return query(b, ft) - query(a - 1, ft);
}

int n, m;
string s, a, b;
vi za, zb;
ll res, acu[MX], cn[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> a >> b >> s;

	{
		string aux = s + a;
		za = obtZF(aux);
		za.erase(za.begin(), za.begin() + m);
		for (int &x : za)
			x = min(x, m - 1);

		aux = b + s;
		reverse(all(aux));
		zb = obtZF(aux);
		zb.erase(zb.begin(), zb.begin() + m);
		reverse(all(zb));
		for (int &x : zb)
			x = min(x, m - 1);
	}

	for (int i = 0; i < n; i++) {
		if (i - m + 1 >= 0 && za[i - m + 1]) {
			update(za[i - m + 1], -1, cn);
			update(za[i - m + 1], -(za[i - m + 1] + 1 - m), acu);
		}

		if (za[i]) {
			update(za[i], 1, cn);
			update(za[i], za[i] + 1 - m, acu);
		}

		if (zb[i]) {
			res += query(m - zb[i], m, acu) + zb[i] * query(m - zb[i], m, cn);
		}
	}

	cout << res << endl;

	return 0;
}