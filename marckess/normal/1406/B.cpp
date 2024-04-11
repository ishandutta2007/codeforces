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

int n, x, c;
vi a, b;
ll res;

void solve () {
	cin >> n;

	c = 0;
	a.clear();
	b.clear();

	while (n--) {
		cin >> x;
		if (!x) c++;
		else if (x > 0) a.pb(x);
		else b.pb(x);
	}

	if (c) res = 0;
	else res = -1e18;

	sort(all(a), greater<int>());
	sort(all(b));

	if (a.size() >= 5 && b.size() >= 0) {
		res = max(res, 1ll * a[0] * a[1] * a[2] * a[3] * a[4]);
	}

	if (a.size() >= 3 && b.size() >= 2) {
		res = max(res, 1ll * a[0] * a[1] * a[2] * b[1] * b[0]);
	}

	if (a.size() >= 1 && b.size() >= 4) {
		res = max(res, 1ll * a[0] * b[3] * b[2] * b[1] * b[0]);
	}

	reverse(all(a));
	reverse(all(b));

	if (a.size() >= 4 && b.size() >= 1) {
		res = max(res, 1ll * a[0] * a[1] * a[2] * a[3] * b[0]);
	}

	if (a.size() >= 2 && b.size() >= 3) {
		res = max(res, 1ll * a[0] * a[1] * b[2] * b[1] * b[0]);
	}

	if (a.size() >= 0 && b.size() >= 5) {
		res = max(res, 1ll * b[4] * b[3] * b[2] * b[1] * b[0]);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}