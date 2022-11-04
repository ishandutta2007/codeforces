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

ll n, k, l1, r1, l2, r2, res, s;

void solve () {
	cin >> n >> k;
	cin >> l1 >> r1;
	cin >> l2 >> r2;

	s = 0;
	res = 1e18;

	if (max(l1, l2) <= min(r1, r2)) {
		s = n * (min(r1, r2) - max(l1, l2));
		if (s >= k) {
			cout << 0 << endl;
			return;
		}
	}

	forn (i, n) {
		ll p = 0, f = k - s;

		ll ini = 0;
		if (max(l1, l2) > min(r1, r2))
			ini = max(l1, l2) - min(r1, r2);

		p += (i + 1) * ini;

		ll d = max(r1, r2) - min(l1, l2);
		if (max(l1, l2) <= min(r1, r2))
			d -= min(r1, r2) - max(l1, l2);

		d = min((i + 1) * d, f);
		f -= d;
		p += d;

		p += 2 * f;

		res = min(res, p);
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