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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005;
int n;
ll a[MX], b[MX], res, mx;

void solve () {
	cin >> n;
	
	forn (i, n) cin >> a[2 * i];
	forn (i, n) cin >> b[2 * i];
	
	forn (i, n)
		res += a[2 * i] * b[2 * i];
	
	forn (i, 2 * n) {
		ll acu = 0;
		
		for (int x = i - (i & 1), y = i + (i & 1); x >= 0 && y < 2 * n; x -= 2, y += 2) {
			acu -= a[x] * b[x];
			acu -= a[y] * b[y];
			acu += a[x] * b[y];
			acu += a[y] * b[x];
			
			mx = max(mx, acu);
 		}
	}
	
	cout << res + mx << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}