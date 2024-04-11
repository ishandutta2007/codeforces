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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, m, fa[MX], fb[MX], ca[MX], cb[MX], p[MX], res;
bool exf, exc;
char v[MX][MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);

	if (a == b) return;
	p[a] = b;
}

void no () {
	cout << -1 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fill(fa, fa + MX, 1e9);
	fill(ca, ca + MX, 1e9);
	iota(p, p + MX, 0);

	cin >> n >> m;
	forn (i, n) forn (j, m) {
		cin >> v[i][j];
		if (v[i][j] == '#') {
			fa[i] = min(fa[i], j);
			fb[i] = max(fb[i], j);

			ca[j] = min(ca[j], i);
			cb[j] = max(cb[j], i);

			join(i, n + j);
		}
	}

	forn (i, n) {
		if (fa[i] != 1e9) {
			for (int j = fa[i]; j <= fb[i]; j++)
				if (v[i][j] == '.')
					no();

			if (parent(i) == i)
				res++;
		} else {
			exf = 1;
		}
	}

	forn (j, m) {
		if (ca[j] != 1e9) {
			for (int i = ca[j]; i <= cb[j]; i++)
				if (v[i][j] == '.')
					no();

			if (parent(n + j) == n + j)
				res++;
		} else {
			exc = 1;
		}
	}

	if (exf != exc) no();
	cout << res << endl;

	return 0;
}