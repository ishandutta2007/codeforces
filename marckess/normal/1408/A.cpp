#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
int n, a[MX], b[MX], c[MX], res[MX];

void solve () {
	cin >> n;
	
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	forn (i, n) cin >> c[i];

	forn (i, n) {
		if ((!i || a[i] != res[i - 1]) && (i + 1 < n || a[i] != res[0])) res[i] = a[i];
		if ((!i || b[i] != res[i - 1]) && (i + 1 < n || b[i] != res[0])) res[i] = b[i];
		if ((!i || c[i] != res[i - 1]) && (i + 1 < n || c[i] != res[0])) res[i] = c[i];

		cout << res[i] << " ";
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)	
		solve();

	return 0;
}