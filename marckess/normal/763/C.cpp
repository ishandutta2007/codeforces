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
int mod, n, p, a[MX], b[MX], c[MX], m, o;
bool f = 0;

int go (int d) {
	int res = f ? p + d : p, cn = 1, act = p;

	while (cn < o) {
		act += d;
		if (act >= mod) act -= mod;
		if (f ^ (*lower_bound(a, a+m, act) != act)) break;
		if (f) res = act + d;
		cn++;
	}

	act = p;
	while (cn < o) {
		act -= d;
		if (act < 0) act += mod;
		if (f ^ (*lower_bound(a, a+m, act) != act)) break;
		if (!f) res = act;
		cn++;
	}

	if (cn == o) return res % mod;
	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	scanf("%d %d", &mod, &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	a[n] = mod;
	m = n + 1;

	if (n == 1 || n == mod) {
		printf("%d 1\n", a[0]);
		return 0;
	}

	p = a[rand()%n];

	for (int i = 0; i < n; i++)
		if (a[i] != p) {
			int d = a[i]-p;
			if (d >= mod) d -= mod;
			if (d < 0) d += mod;
			c[i] = d;
		}

	if (2 * n > mod) {
		f = 1;
		for (int i = 0; i < mod; i++)
			if (*lower_bound(a, a+m, i) != i) {
				p = i;
				break;
			}
		o = mod - n;
	} else {
		o = n;
	}

	random_shuffle(c, c+n);

	for (int i = 0; i < n; i++) {
		if (!c[i]) continue;
		int res = go(c[i]);
		if (res != -1) {
			printf("%d %d\n", res, c[i]);
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}