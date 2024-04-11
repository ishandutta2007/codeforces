#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

struct Frac {
	ll x, y;
	
	Frac () : x(0), y(1) {}
	Frac (ll _x, ll _y) {
		x = _x, y = _y;
		norm();
	}

	Frac operator + (Frac ot) { return {x * ot.y  + y * ot.x, y * ot.y}; }
	Frac operator - (Frac ot) { return {x * ot.y  - y * ot.x, y * ot.y}; }
	Frac operator * (Frac ot) { return {x * ot.x, y * ot.y}; }
	Frac operator / (Frac ot) { return {x * ot.y, y * ot.x}; }
	Frac& operator = (int _x) { x = _x, y = 1; return *this; }
	operator bool() { return bool(x); } 

	void norm () {
		ll g = __gcd(x, y);
		x /= g, y /= g;
		if (y < 0) x *= -1, y *= -1;
	}

	string to_str () {
		if (y == 1) return to_string(x);
		return to_string(x) + "/" + to_string(y);
	}
};

const int MX = 100005;
int h[4][4];
vector<vector<Frac>> m(6, vector<Frac>(8));
vector<vi> mat = {
	{1, 0, 1, 0, 1, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{0, 0, 0, 1, 1, 1, 1},
	{1, 1, 0, 0, 1, 1, 0},
	{1, 0, 1, 1, 0, 1, 0},
	{0, 1, 1, 1, 1, 0, 0}
};

int res;
vi r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n = 0;
	forn (i, 4) forr (j, i + 1, 3) {
		cin >> h[i][j];
		h[j][i] = h[i][j];
		m[n++][7] = h[i][j];
	}

	forn (i, 6) forn (j, 7) m[i][j] = mat[i][j];

	forn (i, 6) {
		int ind = i;
		for (int j = i; j < 6; j++)
			if (m[j][i])
				ind = j;

		swap(m[i], m[ind]);

		auto act = m[i][i];
		for (int j = i; j <= 7; j++)
			m[i][j] = m[i][j] / act;

		forn (j, 6)
			if (i != j && m[j][i]) {
				act = m[j][i];
				for (int k = i; k <= 7; k++)
					m[j][k] = m[j][k] - act * m[i][k];
			}
	}

	forn (l, MX) {
		int p = l;
		vi b(8);
		b[7] = l;

		forn (i, 6) {
			Frac x = m[i][7] - m[i][6] * Frac(l, 1);
			if (x.y != 1 || x.x < 0) {
				p = -1;
				break;
			}
			b[i + 1] = x.x;
			p += b[i + 1];
		}

		if (p != -1 && (!res || res > p))
			res = p, r = b;
	}

	if (res) {
		vi v[4];

		for (int i = 1; i < 8; i++)
			while (r[i]--) {
				v[0].pb(0);
				v[1].pb(i & 1);
				v[2].pb(i & 2);
				v[3].pb(i & 4);
			}

		cout << res << endl;
		forn (i, 4) {
			for (int x : v[i]) cout << "ab"[bool(x)];
			cout << endl;
		}
	} else cout << -1 << endl;

	return 0;
}