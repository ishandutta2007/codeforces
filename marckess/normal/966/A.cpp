#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, cl, ce, v;
vi l, e;
int q, x, y, x2, y2;

ii query (vi &st, int x) {
	ii res(-1, -1);
	auto it = upper_bound(all(st), x);

	if (it != st.end()) res.se = *it;
	if (it != st.begin()) {
		it--;
		res.fi = *it;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> cl >> ce >> v;

	l.resize(cl);
	e.resize(ce);

	for (int &x : l) cin >> x;
	for (int &x : e) cin >> x;

	cin >> q;
	while (q--) {
		cin >> x >> y >> x2 >> y2;
		int res = 2e9;

		if (x == x2) {
			cout << abs(y-y2) << endl;
			continue;
		}

		//Stairs
		ii c = query(l, y);
		if (c.fi != -1) res = min(res, abs(y-c.fi) + abs(y2-c.fi) + abs(x-x2));
		if (c.se != -1) res = min(res, abs(y-c.se) + abs(y2-c.se) + abs(x-x2));

		c = query(l, y2);
		if (c.fi != -1) res = min(res, abs(y-c.fi) + abs(y2-c.fi) + abs(x-x2));
		if (c.se != -1) res = min(res, abs(y-c.se) + abs(y2-c.se) + abs(x-x2));

		//Elevator
		int d = (abs(x-x2)+v-1)/v;

		c = query(e, y);
		if (c.fi != -1) res = min(res, abs(y-c.fi) + abs(y2-c.fi) + d);
		if (c.se != -1) res = min(res, abs(y-c.se) + abs(y2-c.se) + d);

		c = query(e, y2);
		if (c.fi != -1) res = min(res, abs(y-c.fi) + abs(y2-c.fi) + d);
		if (c.se != -1) res = min(res, abs(y-c.se) + abs(y2-c.se) + d);

		cout << res << endl;
	}

	return 0;
}