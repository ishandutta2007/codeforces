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

int n, m, k, f;
string s;
vector<pair<int, string>> res;

void ans () {
	cout << res.size() << endl;
	for (auto r : res)
		cout << r.fi << " " << r.se << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	if (k > 4 * n * m - 2 * n - 2 * m) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

	// Primeras n-1 filas
	for (int i = 0; i < n - 1; i++) {
		// Visita todas y las de abajo
		f = m - 1;
		s = "RDU";

		if (f * s.size() > k) {
			int ff = k / s.size();
			int rem = k % s.size();

			if (ff)
				res.emplace_back(ff, s);

			if (rem)
				res.emplace_back(1, s.substr(0, rem));

			ans();
		}

		if (f) res.emplace_back(f, s);
		k -= f * s.size();
		if (!k) ans();

		// Regresa
		f = min(m - 1, k);
		string s = "L";

		if (f) res.emplace_back(f, s);
		k -= f * s.size();
		if (!k) ans();

		// Baja
		res.emplace_back(1, "D");
		k -= 1;
		if (!k) ans();
	}

	// Ultima fila
	// Ida
	f = min(k, m - 1);
	s = "R";

	if (f) res.emplace_back(f, s);
	k -= f * s.size();
	if (!k) ans();

	// Regreso
	f = min(k, m - 1);
	s = "L";

	if (f) res.emplace_back(f, s);
	k -= f * s.size();
	if (!k) ans();

	// Regresa al inicio
	f = min(k, n - 1);
	s = "U";

	if (f) res.emplace_back(f, s);
	k -= f * s.size();
	assert(!k);
	ans();

	return 0;
}