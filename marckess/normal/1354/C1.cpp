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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ld pi = acos(-1.0l);
int n;

void solve () {
	cin >> n;
	n *= 2;

	complex<ld> c(0, 0), sig(1, 0), v = polar(1.0l, 2 * pi / n);

	ld ax = 0, ay = 0, bx = 0, by = 0;
	forn (i, n) {
		c += sig;
		sig *= v;
		ax = min(ax, c.real());
		bx = max(bx, c.real());
		ay = min(ay, c.imag());
		by = max(by, c.imag());
	}

	cout << (bx - ax) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(8);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}