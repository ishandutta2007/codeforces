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

const int MX = 200005;
ll n, k, a[MX];

void solve () {
	cin >> n >> k;
	forn (i, n) cin >> a[i];

	while (k) {
		bool neg = 0, cero = 0;
		ll mx = -1e18;

		forn (i, n) {
			mx = max(mx, a[i]);
			if (a[i] < 0) neg = 1;
			if (!a[i]) cero = 1;
		}

		if (!neg && cero) {
			k %= 2;

			if (k) {
				forn (i, n) a[i] = mx - a[i];
				k--;
			}

			forn (i, n) cout << a[i] << " ";
			cout << endl;
		} else {
			forn (i, n) a[i] = mx - a[i];
			k--;

			if (!k) {
				forn (i, n) cout << a[i] << " ";
				cout << endl;
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}