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

const int MX = 35;
int n, k, a[MX], b[MX];

void solve () {
	cin >> n >> k;
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];

	while (k--) {
		int x = 0, y = 0;
		forn (i, n) if (a[i] < a[x]) x = i;
		forn (i, n) if (b[i] > b[y]) y = i;
		if (a[x] < b[y]) swap(a[x], b[y]);
	}

	int res = 0;
	forn (i, n) res += a[i];
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}