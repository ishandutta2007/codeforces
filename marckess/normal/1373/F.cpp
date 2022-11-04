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

const int MX = 2000005;
int n, a[MX], b[MX], _b[MX];

void solve () {
	cin >> n;

	forn (i, n) cin >> a[i + 1];
	forn (i, n) cin >> b[i + 1];
	
	for (int i = 1; i <= n; i++) {
		int d = min(a[i], b[i]);
		_b[i] = b[i];
		a[i] -= d, b[i] -= d;
	}

	int acu = 0;

	for (int i = 1; i <= 2 * n; i++) {
		if (i > n) {
			a[i] = a[i - n];
			b[i] = b[i - n];
			_b[i] = _b[i - n];
		}

		if (i <= n) acu += b[i];
		int d = min(a[i], acu);
		a[i] -= d;
		acu -= d;

		acu = min(acu, _b[i]);
		_b[i] -= acu;

		if (i > n) a[i - n] = a[i];
	}

	for (int i = 1; i <= n; i++)
		if (a[i]) {
			cout << "NO" << endl;
			return;
		}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}