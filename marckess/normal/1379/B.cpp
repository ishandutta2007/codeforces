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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll l, r, m;

bool solve (ll a, ll d) {
	if (d < l - r || r - l < d || m + d <= 0) return 0;

	if (d < 0) {
		cout << a << " " << r << " " << r + d << endl;
	} else {
		cout << a << " " << l << " " << l + d << endl;
	}

	return 1;
}

void solve () {
	cin >> l >> r >> m;

	for (ll a = l; a <= r; a++) {
		ll r = m % a;
		if (solve(a, -r)) return;
		if (solve(a, -r + a)) return;
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