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

const int MX = 300005;

int gcd (int a, int b) { return b ? gcd(b, a%b) : a; }

struct Punto {
	int x, y;

	ll operator ~ () { return ll(x) * x + ll(y) * y; }
	Punto operator + (Punto ot) { return {x + ot.x, y + ot.y}; }
	bool operator < (const Punto ot) const { return y ^ ot.y ? y < ot.y : x < ot.x; }
	void leer () { cin >> x >> y; }
	ll l () {
		int d = gcd(x, y);
		return ll (x / d) * MX + (y / d);
	}
};

int q, t, n = 0;
Punto p;
map<ll, int> a, b;
map<ll, set<Punto>> c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> q;
	while (q--) {
		cin >> t;
		p.leer();

		if (t == 1) {
			n++;
			a[p.l()]++;
			for (auto &q : c[~p])
				b[(p+q).l()]++;
			c[~p].insert(p);
		} else if (t == 2) {
			n--;
			a[p.l()]--;
			c[~p].erase(p);
			for (auto &q : c[~p])
				b[(p+q).l()]--;
		} else {
			ll l = p.l();
			int x = a.count(l) ? a[l] : 0;
			int y = b.count(l) ? b[l] : 0;
			cout << n - x - 2 * y << endl;
		}
	}

	return 0;
}