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

const int MX = 1005;
int n, x, a[MX], s;

void solve () {
	cin >> n >> x;
	forn (i, n) cin >> a[i];

	forn (i, n) if (a[i] == x) {
		forn (j, n) if (a[j] != x) {
			cout << 1 << endl;
			return;
		}
		cout << 0 << endl;
		return;
	}

	s = 0;
	forn (i, n) s += a[i];
	if (s % n || s / n != x) cout << 2 << endl;
	else cout << 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}