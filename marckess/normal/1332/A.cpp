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

void solve () {
	int a, b, c, d, x, y, x1, x2, y1, y2;
	cin >> a >> b >> c >> d;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	#define no { cout << "NO" << endl; return; } 

	if (a > b) {
		if (x - (a - b) < x1) no
	} else if (a < b) {
		if (x + (b - a) > x2) no
	} else if (a == b) {
		if (a + b && x1 == x2) no
	}

	if (c > d) {
		if (y - (c - d) < y1) no
	} else if (c < d) {
		if (y + (d - c) > y2) no
	} else {
		if (c + d && y1 == y2) no
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