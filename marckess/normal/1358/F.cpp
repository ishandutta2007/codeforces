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

const int MX = 200000;
int n;
ll a[MX + 5], b[MX + 5], _b[MX + 5];
string res;
vi s;

void solve (bool rev = 0) {
	s.clear();

	while ((b[0] > a[0] || b[n - 1] > a[n - 1]) && s.size() <= 10 * MX) {
		bool f = 1, g = 1;

		forn (i, n - 1) {
			f &= b[i] < b[i + 1];
			g &= b[i] > b[i + 1];
		}

		if (!f && !g) break;

		if (f) {
			for (int i = n - 1; i > 0; i--)
				b[i] -= b[i - 1];
			s.pb(0);
		}

		if (g) {
			for (int i = 0; i + 1 < n; i++)
				b[i] -= b[i + 1];
			s.pb(1);
		}
	}

	if (s.size() > MX) {
		bool f = 1;
		forn (i, n) f &= a[i] == b[i];

		if (f) {
			cout << "BIG" << endl;
			cout << s.size() << endl;
			exit(0);
		}

		if (n > 2) return;

		ll res = s.size();
		if (a[0] > a[1]) swap(a[0], a[1]);
		if (b[0] > b[1]) swap(b[0], b[1]);



		while (a[0] < b[0] || a[1] < b[1]) {
			ll d = (b[1] - max(b[0], a[1]) + b[0] - 1) / b[0];
			res += d;
			b[1] -= d * b[0];
			if (b[0] > b[1]) swap(b[0], b[1]);
		}

		forn (i, n) if (a[i] != b[i]) return;

		cout << "BIG" << endl << res << endl;

		exit(0);
	}

	forn (i, n) if (a[i] != b[i]) return;

	reverse(all(s));
	
	int f = 0;
	for (int r : s) {
		if (f != r) {
			f = 1 - f;
			res.pb('R');
		}
		res.pb('P');
	}
	if (f) res.pb('R');
	if (rev) res.pb('R');

	cout << "SMALL" << endl << res.size() << endl;
	cout << res << endl;

	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> _b[i];

	if (n == 1) {
		if (a[0] == _b[0]) cout << "SMALL" << endl << 0 << endl << endl;
		else cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	forn (i, n) b[i] = _b[i];
	solve();

	forn (i, n) b[i] = _b[i];
	reverse(b, b + n);
	solve(1);

	cout << "IMPOSSIBLE" << endl;

	return 0;
}