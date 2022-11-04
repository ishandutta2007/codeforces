#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

struct Punto {
	ll x, y;

	Punto () {}
	Punto (ll _x, ll _y) : x(_x), y(_y) {}

	Punto operator + (Punto ot) { return {x+ot.x, y+ot.y}; }
	Punto operator - (Punto ot) { return {x-ot.x, y-ot.y}; }
	ll operator % (Punto ot) { return x*ot.x + y*ot.y; }
	ll operator ^ (Punto ot) { return x*ot.y - y*ot.x; }
	//bool operator == (const Punto &ot) { return Igual(x, ot.x) && Igual(y, ot.y); }
	bool operator < (const Punto &ot) const { return y ^ ot.y ? y < ot.y : x < ot.x; }
	//bool operator <= (const Punto &ot) const { return *this < ot || *this == ot; }
	int operator ~ () { return x * x + y * y; }
	void read () { cin >> x >> y; }
	void print () { cout << x << " " << y << endl; }
};

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int n;
Punto p[2005];
ll res = 0;
set<Punto> st, act;

int lat (Punto a, Punto b) {
	int x = a.x - b.x;
	int y = a.y - b.y;
	return gcd(x, y);
}

int manoDerecha (Punto o, Punto p, Punto q) {
	ll c = (p - o) ^ (q - o);
	return !c ? 0 : c / abs(c);
}

int inter (Punto a, Punto b, Punto c, Punto d) {
	int l = abs(lat(a, b));

	int i = 0, j = l+1, rep = 30, ini = manoDerecha(c, d, a);
	
	if (!ini) {
		if (st.count(a)){
			if (act.count(a)) return 0;
			act.insert(a);
			return 1;
		}
		st.insert(a);
		act.insert(a);
		return 0;
	}

	int x = (a.x - b.x) / l;
	int y = (a.y - b.y) / l;

	while (rep--) {
		int m = (i+j)/2;
		Punto t(a.x - x * m, a.y - y * m);

		int md = manoDerecha(c, d, t);
		if (!md)  {
			if (st.count(t)) {
				if (act.count(t)) return 0;
				act.insert(t);
				return 1;
			}
			st.insert(t);
			act.insert(t);
			return 0;
		}

		if (md == ini) i = m;
		else j = m;
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		p[2*i].read(), p[2*i+1].read();
		res += abs(lat(p[i*2], p[i*2+1])) + 1;
	}

	for (int i = 0; i < n; i++) {
		act.clear();
		for (int j = 0; j < n; j++)
			if (i != j)
				res -= inter(p[i*2], p[i*2+1], p[j*2], p[j*2+1]);
	}

	cout << res << endl;

	return 0;
}