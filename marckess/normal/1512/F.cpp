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

const int MX = 200005;
int n, c, a[MX], b[MX];

int techo (int a, int b) {
	return (a + b - 1) / b;
}

void solve () {
	cin >> n >> c;
	
	forn (i, n)
		cin >> a[i];
		
	forn (i, n - 1)
		cin >> b[i];
	
	ll off = 0, acu = 0, res = c;
	
	forn (i, n) {
		ll d = c - acu;
		
		if (d <= 0)
			res = min(res, off);
		else {
			ll e = techo(d, a[i]);
			res = min(res, off + e);
		}
		
		d = b[i] - acu;
		
		if (d <= 0) {
			off++;
			acu -= b[i];
		} else {
			ll e = techo(d, a[i]);
			off += e + 1;
			acu += a[i] * e - b[i];
		}
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