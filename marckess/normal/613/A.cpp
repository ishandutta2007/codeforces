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

const ld eps = 1e-15;

struct Punto {
	ld x, y;
	ld abs2 () { return x * x + y * y; }
	ld abs () { return hypot(x, y); }
	bool operator <= (Punto ot) {
		if ((*this - ot).abs() < eps) return 1;
		return fabs(x - ot.x) < eps ? y < ot.y : x < ot.x;
	}
	Punto operator - (Punto ot) {
		return {x - ot.x, y - ot.y};
	}
	ld operator % (Punto ot) {
		return x * ot.x + y * ot.y;
	}
	void leer () {
		cin >> x >> y;
	}
	void impr () {
		cout << x << " " << y << endl;
	}
};

const int MX = 100005;
int n;
Punto a[MX];

Punto closest (Punto a, Punto b, Punto p) {
	Punto ap = p - a;
	Punto ab = b - a;

	ld t = (ap % ab) / ab.abs2();

	return {a.x + ab.x * t, a.y + ab.y * t};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n;
	for (int i = 0; i <= n; i++)
		a[i].leer();

	a[n+1] = a[1];

	ld mn = numeric_limits<ld>::max();
	ld mx = 0;

	for (int i = 1; i <= n; i++) {
		Punto q = closest(a[i], a[i+1], a[0]);
		ld d;

		if (a[i] <= a[i+1]) {
			if (a[i] <= q && q <= a[i+1]) d = (q - a[0]).abs();
			else d = min((a[i] - a[0]).abs(), (a[i+1] - a[0]).abs());
		} else {
			if (a[i+1] <= q && q <= a[i]) d = (q - a[0]).abs();
			else d = min((a[i] - a[0]).abs(), (a[i+1] - a[0]).abs());
		}

		mn = min(mn, d);
		mx = max(mx, (a[i] - a[0]).abs());
	}

	cout << acos(-1.0l) * (mx * mx - mn * mn) << endl;

	return 0;
}