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

const int MX = 2005;
const ld inf = 1e36;

bool Q = 0;
struct Line {
	mutable ld m, b, x;

	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m < ot.m;
	}
};

ld intersection (const Line &p, const Line &q) {
	return (q.b - p.b) / (p.m - q.m);
}

struct Hull : multiset<Line> {
	bool valid (auto it) {
		if (it == begin()) {
			auto sig = it;
			sig++;
			if (sig != end()) sig->x = intersection(*it, *sig);
			return it->x = -inf;
		}

		auto ant = it, sig = it;
		ant--, sig++;

		if (sig == end()) {
			it->x = intersection(*it, *ant);
			return 1;
		}

		ld x = intersection(*it, *ant);
		ld y = intersection(*it, *sig);

		if (x > y) return 0;
		it->x = x, sig->x = y;
		return 1;
	}

	void add (ld m, ld b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			if (it->b > b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}

		if (!valid(it)) {
			erase(it);
			return;
		}

		auto ant = it;
		while (ant != begin()) {
			if (valid(--ant)) break;
			erase(ant);
			if (it == begin()) { it->x = -inf; break; }
			ant = it;
		}

		auto sig = it;
		sig++;
		while (sig != end() && !valid(sig))
			erase(sig++);
	}

	ld query (ld x) {
		if (empty()) return 0;

		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return x * it->m + it->b;
	}
}hmx, hmn;

int n, y[MX];
ii x[MX];
vector<pair<ii, ii>> a;
ld mx = -inf, mn = inf;

bool le (const ii &a, const ii &b) {
	return a.fi * b.se < a.se * b.fi;
}

bool leq (const ii &a, const ii &b) {
	return a.fi * b.se <= a.se * b.fi;
}

void norm (ii &a) {
	ll g = __gcd(a.fi, a.se);
	a.fi /= g;
	a.se /= g;
	if (a.se > 0) a.fi *= -1, a.se *= -1;
}

void go (ii &p) {
	ld k = 1.0l * p.fi / p.se;
	ld fi = -hmn.query(k);
	ld se = hmx.query(k);

	if (se - fi < mx - mn) {
		mx = se;
		mn = fi;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n;
	forn (i, n) cin >> x[i].fi >> x[i].se >> y[i];

	forn (i, n) forn (j, i) if (y[i] != y[j]) {
		ii fi(x[i].se - x[j].fi, y[j] - y[i]);
		ii se(x[i].fi - x[j].se, y[j] - y[i]);
		norm(fi), norm(se);

		if (le(se, fi)) swap(fi, se);
		a.emplace_back(fi, se);
	}

	if (a.empty()) {
		forn (i, n) {
			mn = min(mn, 1.0l * x[i].fi);
			mx = max(mx, 1.0l * x[i].se);
		}
		
		cout << mx - mn << endl;
		return 0;
	}

	mx = inf, mn = -inf;

	forn (i, n) {
		hmx.add(y[i], x[i].se);
		hmn.add(-y[i], -x[i].fi);
	}

	sort(all(a), [&] (const pair<ii, ii> &x, const pair<ii, ii> &y) {
		return le(x.fi, y.fi);
	});

	ii to = a[0].fi;

	for (auto &p : a) {
		if (leq(to, p.fi)) {
			go(to);
			go(p.fi);
		}

		if (le(to, p.se)) to = p.se;
	}

	go(to);

	cout << mx - mn << endl;

	return 0;
}