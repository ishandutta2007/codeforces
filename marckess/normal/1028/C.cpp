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

const int MX = 1000005, inf = INT_MAX;

struct rec {
	int a, b, c, d;
	rec () : a(-inf), b(-inf), c(inf), d(inf) {}
	rec (int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
	void read () { cin >> a >> b >> c >> d; }
	void impr () { cout << a << " " << b << endl; }
	bool good () { return a <= c && b <= d; }
};

rec merge (rec i, rec j) {
	return { max(i.a, j.a), max(i.b, j.b), min(i.c, j.c), min(i.d, j.d) };
}

int n;
rec r[MX], izq[MX], der[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) r[i].read();
	
	for (int i = 1; i <= n; i++) izq[i] = merge(izq[i-1], r[i]);
	for (int i = n; i > 0; i--) der[i] = merge(der[i+1], r[i]);

	for (int i = 1; i <= n; i++)
		if (merge(izq[i-1], der[i+1]).good()) {
			merge(izq[i-1], der[i+1]).impr();
			return 0;
		}

	return -1;
}