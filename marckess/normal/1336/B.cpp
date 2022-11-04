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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll res, inf = numeric_limits<ll>::max();
int a, b, c, in;
set<int> sa, sb, sc;

#define sq(n) (ll(n)*(n))

ll f (int a, int b, set<int> &st) {
	ll res = inf;

	int m = (a + b) / 2;
	auto it = st.lower_bound(m);

	for (int i = 0; i < 3 && it != st.begin(); i++, it--);

	for (int i = 0; i < 7 && it != st.end(); i++, it++) {
		ll p = sq(a - b) + sq(a - *it) + sq(b - *it);
		res = min(res, p); 
	}

	return res;
}

void solve () {
	cin >> a >> b >> c;
	
	sa.clear();
	sb.clear();
	sc.clear();
	res = inf;

	while (a--) {
		cin >> in;
		sa.insert(in);
	}

	while (b--) {
		cin >> in;
		sb.insert(in);
	}

	while (c--) {
		cin >> in;
		sc.insert(in);
	}

	for (int x : sa) {
		auto it = sb.lower_bound(x);
		if (it != sb.end()) {
			res = min(res, f(x, *it, sc));
		}

		it = sc.lower_bound(x);
		if (it != sc.end()) {
			res = min(res, f(x, *it, sb));
		}
	}

	for (int x : sb) {
		auto it = sa.lower_bound(x);
		if (it != sa.end()) {
			res = min(res, f(x, *it, sc));
		}

		it = sc.lower_bound(x);
		if (it != sc.end()) {
			res = min(res, f(x, *it, sa));
		}
	}

	for (int x : sc) {
		auto it = sb.lower_bound(x);
		if (it != sb.end()) {
			res = min(res, f(x, *it, sa));
		}

		it = sa.lower_bound(x);
		if (it != sa.end()) {
			res = min(res, f(x, *it, sb));
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