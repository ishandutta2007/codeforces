#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

bool Q;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return l.k * x + l.m;
	}
};

struct PT {
	ll x, y, a;
};

bool operator<(PT a, PT b) {
	return a.x > b.x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<PT> a(n);
	for (auto &b : a) cin >> b.x >> b.y >> b.a;

#ifdef DEBUG
	n = 1e6;
	a = vector<PT>(n);
	for (int i = 0; i < n; i++) {
		a[i].x = i + 1;
		a[i].y = n + 1 - i;
		a[i].a = (rand() % 300) + 10;
	}
#endif

	sort(all(a));

	LineContainer lc;
	lc.add(0, 0); // y = 0

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll q = lc.query(a[i].x);
		q += a[i].x * a[i].y - a[i].a;
		lc.add(-a[i].y, q);
		ans = max(ans, q);
	}
	cout << ans << endl;

	return 0;
}