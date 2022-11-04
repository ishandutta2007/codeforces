#include <bits/stdc++.h>
 
//#define endl '\n'
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MX = 1005;

string query (vi a, vi b) {
	cout << "? " << a.size() << " " << b.size() << endl;
	for (int x : a) cout << x << " "; cout << endl;
	for (int x : b) cout << x << " "; cout << endl;

	string s;
	cin >> s;
	if (s == "WASTED") exit(0);
	return s;
}

void solve () {
	int n, k;
	vi v, a;
	bitset<MX> bs;

	cin >> n >> k;

	a.resize(n);
	iota(all(a), 1);
	shuffle(all(a), rng);

	v.pb(a[0]);
	for (int i = 1; i < min(25, n); i++)
		if (query({v[0]}, {a[i]}) == "SECOND")
			v[0] = a[i];

	bs.reset();
	bs[v[0]] = 1;

	vi x;
	for (int i = 1;;) {
		vi a, b;

		while (i <= n && a.size() < v.size()) {
			if (!bs[i]) a.pb(i);
			i++;
		}

		forn (j, a.size()) b.pb(v[j]);

		if (query(a, b) == "SECOND") {
			x = a;
			break;
		}

		for (int k : a) {
			bs[k] = 1;
			v.pb(k);
		}
	}

	int i = 0, j = int(x.size()) - 1;
	while (i < j) {
		int m = (i + j) / 2;
		vi a, b;

		for (int k = i; k <= m; k++) {
			a.pb(x[k]);
			b.pb(v[k - i]);
		}

		if (query(a, b) == "SECOND") j = m;
		else i = m + 1;
	}

	cout << "! " << x[i] << endl;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}