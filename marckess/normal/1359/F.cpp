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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 25005;
const ld eps = 1e-10;

bool eq (ld a, ld b) { return abs(a - b) < eps; }
bool ge (ld a, ld b) { return a - b > eps; }   
bool le (ld a, ld b) { return b - a > eps; } 
bool leq (ld a, ld b) { return eq(a, b) || le(a, b); }

struct point {
	ld x, y;

	point operator + (const point &ot) const { return {x + ot.x, y + ot.y}; }
	point operator - (const point &ot) const { return {x - ot.x, y - ot.y}; }
	point operator / (const ld &k) const { return {x / k, y / k}; }
	point operator * (const ld &k) const { return {x * k, y * k}; }

	ld cross (const point &p) const { return x * p.y - y * p.x; }
	ld dot (const point &p) const { return x * p.x + y * p.y; }
	ld length () const { return sqrtl(x * x + y * y); }

	point unit () const { return (*this) / length(); }
};

int sgn (ld x) {
	if (ge(x, 0)) return 1;
	if (le(x, 0)) return -1;
	return 0;
}

bool pointInLine (const point &a, const point &v, const point &p) {
	return eq((p - a).cross(v), 0);
}

bool pointInSegment (const point &a, const point &b, const point &p) {
	return pointInLine(a, b - a, p) && leq((a - p).dot(b - p), 0);
}

int interInfo (const point &a, const point &b, const point &c, const point &d) {
	point v1 = b - a, v2 = d - c;
	
	int t = sgn(v1.cross(c - a)), u = sgn(v1.cross(d - a));
	
	if (t == u) {
		if (t == 0) {
			if(pointInSegment(a, b, c) || pointInSegment(a, b, d) || pointInSegment(c, d, a) || pointInSegment(c, d, b))
				return -1;
			else
				return 0;
		} else
			return 0;
	} else {
		return sgn(v2.cross(a - c)) != sgn(v2.cross(b - c));
	}
}

int n, s[MX];
point p[MX], d[MX], a[MX], b[MX];
ld res = 1e30;

bool esPos (ld m, int f = 0) {
	vii eve;
	set<pair<ld, int>> st;

	forn (i, n) {
		a[i] = p[i] + d[i].unit() * m * s[i];
		b[i] = p[i];

		if (a[i].x > b[i].x) swap(a[i], b[i]);

		eve.emplace_back(i, 1);
		eve.emplace_back(i, -1);
	}

	sort(all(eve), [&] (ii &i, ii &j) {
		ld x1 = i.se == 1 ? a[i.fi].x : b[i.fi].x;
		ld x2 = j.se == 1 ? a[j.fi].x : b[j.fi].x;
		return x1 < x2;
	});

	for (auto &e : eve) {
		auto q = e.se == 1 ? a[e.fi] : b[e.fi];
		auto it = st.lower_bound(make_pair(q.y, -1));

		forn (i, 2) if (it != st.begin()) it--;

		forn (i, 5) if (it != st.end()) {
			if (e.fi != it->se) {
				int info = interInfo(a[e.fi], b[e.fi], a[it->se], b[it->se]);
				if (info)
					return 1;
			}

			it++;
		} 

		if (e.se == 1) st.emplace(a[e.fi].y, e.fi);
		else st.erase(make_pair(a[e.fi].y, e.fi));
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n;
	forn (i, n)
		cin >> p[i].x >> p[i].y >> d[i].x >> d[i].y >> s[i];
	
	ld i = 2 * eps, j = 1e10, rep = 100;

	while (rep--) {
		ld m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (esPos(j)) cout << j << endl;
	else cout << "No show :(" << endl;

	esPos(j, 1);

	return 0;
}