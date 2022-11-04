#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
ll n, k, a[MX], s, res;

ll techo (ll a, ll b) {
	return (a + b - 1) / b;
}

void solve () {
	cin >> n >> k;
	forn (i, n) cin >> a[i];
	
	s = res = 0;
	for (int i = 1; i < n; i++) {
		ll x = techo(100 * a[i] - k * s, k);
		if (x > a[0])
			res = max(res, x - a[0]);
		s += a[i];
	}
	
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