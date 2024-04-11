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

ll l1, r1, l2, r2, res;

ll sig (ll n, int i) {
	if (n % (1 << i)) {
		n -= n % (1 << i);
		n += (1 << i);
	}

	if (~n & (1 << i))
		n |= 1 << i;

	return n;
}

ll f (ii a, ii b) {
	if (a.fi > 0 || a.se < 0) return 0;
	if (b.fi > 0 || b.se < 0) return 0;
	return min(a.se, b.se) - max(a.fi, b.fi) + 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> l1 >> r1 >> l2 >> r2;

	forn (i, 30) {
		#define ran(s, l, r) ii(-min(s - l, (1ll << i) - 1), min(r - s, (1ll << i) - 1))

		ll s = sig(l1, i);
		ii a1 = ran(s, l1, r1);

		s = sig(s + 1, i);
		ii a2 = ran(s, l1, r1);

		s = sig(l2, i);
		ii b1 = ran(s, l2, r2);

		s = sig(s + 1, i);
		ii b2 = ran(s, l2, r2);

		res = max(res, f(a1, b1));
		res = max(res, f(a1, b2));
		res = max(res, f(a2, b1));
		res = max(res, f(a2, b2));
	}

	cout << res << endl;

	return 0;
}