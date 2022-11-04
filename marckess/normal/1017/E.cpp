#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;

struct Punto {
	int x, y;

	Punto () {}
	Punto (int x, int y) : x(x), y(y) {}

	Punto operator - (Punto ot) { return {x - ot.x, y - ot.y}; }
	ll operator ^ (Punto ot) { return ll(x) * ot.y - ll(y) * ot.x; }
	ll operator % (Punto ot) { return ll(x) * ot.x + ll(y) * ot.y; }
	ll operator ~ () { return ll(x) * x + ll(y) * y; }
	bool operator < (Punto ot) { return x ^ ot.x ? x < ot.x : y < ot.y; }
	void leer () { cin >> x >> y; }
	void impr () { cout << x << " " << y << endl; }
};

typedef vector<Punto> vp;

int md (Punto o, Punto p, Punto q) {
	ll c = (p - o) ^ (q - o);
	return c ? c / abs(c) : 0;
}

void ch (vp p, vp &r) {
	Punto piv = *min_element(ALL(p));

	sort(ALL(p), [&] (Punto &p, Punto &q) {
		int c = md(piv, p, q);
		return c ? c == 1 : ~(p-piv) < ~(q-piv);
	});

	r = {p[0], p[1]};
	for (int i = 2; i < p.size(); i++) {
		Punto &q = p[i];
		while (r.size() >= 2 && md(r[r.size()-2], r.back(), q) != 1)
			r.pop_back();
		r.push_back(q);
	}
	r.push_back(r[0]);
	r.push_back(r[1]);
}

void ccw (vp p, vi &r) {
	for (int i = 1; i < (int)p.size()-1; i++) {
		r.push_back(~(p[i] - p[i-1]));
		r.push_back((p[i] - p[i-1]) % (p[i+1] - p[i]));
	}
}

int n, m, f[2*MX];
vp a, b;
vi p, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n >> m;
	a.resize(n), b.resize(m);
	for (auto &x : a) x.leer();
	for (auto &x : b) x.leer();

	ch(a, a);
	ch(b, b);
	
	ccw(a, p);
	ccw(b, t);

	t.insert(t.end(), ALL(t));

	int i = 0, j = -1; f[0] = -1;

	while (i < p.size()) {
		while (j >= 0 && p[i] != p[j]) j = f[j];
		i++, j++;
		f[i] = j;
	}

	i = 0, j = 0;
	while (i < t.size()) {
		while (j >= 0 && t[i] != p[j]) j = f[j];
		i++, j++;
		if (j == p.size()) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}