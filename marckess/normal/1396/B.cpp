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

const int MX = 105;
int n, a[MX], s;

void solve () {
	cin >> n;
	s = 0;
	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}

	forn (i, n) if (2 * a[i] > s) {
		cout << "T" << endl;
		return;
	}

	int f = 0;

	forn (i, n) {
		int t = s - 1, p = 0;

		forn (j, n) if (i != j) {
			if (2 * a[j] > t) {
				p = 1;
			}
		}

		f += p;
	}

	if (f == n) {
		cout << "HL" << endl;
		return;
	}

	if (s % 2 == 1) cout << "T" << endl;
	else cout << "HL" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}