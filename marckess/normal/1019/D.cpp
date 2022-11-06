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

const int MX = 2005;

struct Punto {
	ll x, y;

	Punto () {}
	Punto (ll x, ll y) : x(x), y(y) {}

	Punto operator - (Punto ot) { return {x - ot.x, y - ot.y}; }
	ll operator ^ (Punto ot) { return x * ot.y - y * ot.x; }
	bool operator < (Punto ot) { return y != ot.y ? y < ot.y : x < ot.x; }
	void leer () { cin >> x >> y; }
	void impr () { cout << x << " " << y << endl; }
};

struct Seg {
	Punto p;
	int a, b;

	Seg () {}
	Seg (Punto p, int a, int b) : p(p), a(a), b(b) {}

	bool operator < (Seg ot) { return (p ^ ot.p) > 0; }
};

Punto p[MX];
int n, q[MX];
ll S;
vector<Seg> vs;

void res (Punto a, Punto b, Punto c) {
	cout << "Yes" << endl;
	a.impr();
	b.impr();
	c.impr();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> S;
	for (int i = 0; i < n; p[i++].leer());
	sort(p, p+n);
	iota(q, q+n, 0);

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			vs.emplace_back(p[j] - p[i], i, j);
	sort(ALL(vs));

	for (Seg &s : vs) {
		int a = q[s.a];
		int b = q[s.b];

		int i = 0, j = n, rep = 15;

		while (rep--) {
			int m = (i+j)/2;
			ll c = (p[b] - p[a]) ^ (p[m] - p[a]);

			if (c == S * 2) {
				res(p[a], p[b], p[m]);
				return 0;
			}

			if (c < S * 2) i = m;
			else j = m;
		}

		i = 0, j = n, rep = 15;
		while (rep--) {
			int m = (i+j)/2;
			ll c = (p[b] - p[a]) ^ (p[m] - p[a]);

			if (-c == S * 2) {
				res(p[a], p[b], p[m]);
				return 0;
			}

			if (-c < S * 2) i = m;
			else j = m;
		}

		swap(p[a], p[b]);
		swap(q[s.a], q[s.b]);
	}

	cout << "No" << endl;

	return 0;
}