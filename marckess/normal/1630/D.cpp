// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 1000005;
int n, m, a[MX], b[MX];

ll f (int g, vvi &x, vi &p, int f) {
	ll res = 0;
	
	for (vi &v : x)
		for (int y : v)
			res += y;
 	
	forn (i, g)
		if (p[i] ^ f)
			res -= 2 * x[i][0];
	
	return res;
}

void main_() {
	cin >> n >> m;
	forn (i, n) cin >> a[i];
	
	int g = 0;
	forn (i, m) {
		cin >> b[i];
		g = __gcd(g, b[i]);
	}
	
	vvi x(g);
	vi p(g);
	
	forn (i, n) {
		if (a[i] < 0) {
			x[i % g].pb(-a[i]);
			p[i % g] ^= 1;
		} else {
			x[i % g].pb(a[i]);
		}
	}
	
	forn (i, g)
		sort(all(x[i]));
	cout << max(f(g, x, p, 0), f(g, x, p, 1)) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}