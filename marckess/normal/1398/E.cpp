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

const int MX = 200005;
int q, x, y;
ll res, s;
set<ii> si, no;
set<int> f; 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> q;

	forn (i, q) {
		ii p;

		cin >> p.se >> p.fi;

		if (p.fi < 0) {
			p.fi = abs(p.fi);
			s -= p.fi;
			x -= p.se;

			if (!p.se) f.erase(p.fi);

			if (si.count(p)) {
				si.erase(p);
				res -= p.fi;
				y -= p.se;
			} else no.erase(p);
		} else {
			s += p.fi;
			x += p.se;

			if (!p.se) f.insert(p.fi);

			no.insert(p);
		}

		while (si.size() < x) {
			ii p = *no.rbegin();
			si.insert(p);
			no.erase(p);
			res += p.fi;
			y += p.se;
		}

		while (si.size() > x) {
			ii p = *si.begin();
			si.erase(p);
			no.insert(p);
			res -= p.fi;
			y -= p.se;
		}

		while (si.size() && no.size() && *si.begin() < *no.rbegin()) {
			ii a = *si.begin();
			ii b = *no.rbegin();

			res -= a.fi;
			y -= a.se;
			si.erase(a);
			no.insert(a);

			res += b.fi;
			y += b.se;
			si.insert(b);
			no.erase(b);
		}

		if (x && x == y) {
			ll r = res - si.begin()->fi;

			if (f.size()) r += *f.rbegin();

			cout << s + r << endl;
		} else {
			cout << s + res << endl;
		}
	}

	return 0;
}