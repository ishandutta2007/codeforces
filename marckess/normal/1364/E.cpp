#include <bits/stdc++.h>
 
//#define endl '\n'
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 4269;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, ex[MX], r[MX], cn, q[MX], mn, res[MX];

int query (int a, int b) {
	cout << "? " << a + 1 << " " << b + 1 << endl;
	int r;
	cin >> r;
	if (r == -1) exit(-1);
	return r;
}

int find () {
	vi c;
	forn (i, n) if (ex[i]) c.pb(i);
	int m = log2(c.size());
	uniform_int_distribution<> dis(0, (int)c.size() - 1);
	while (1) {
		int i = dis(rng), j = dis(rng);
		if (i != j) {
			int x = query(c[i], c[j]);
			if (__builtin_popcount(x) <= (m + 1) / 2)
				return c[i];
		}
	}
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) ex[i] = 1;

	iota(q, q + n, 0);
	shuffle(q, q + n, rng);

	int ptr = 0;
	cn = n;

	while (cn > 2) {
		int i = find();

		mn = 1e9;
		forn (j, n)	if (ex[j] && i != j) {
			r[j] = query(i, j);
			mn = min(mn, r[j]);
		}
		r[i] = mn;

		forn (j, n) if (ex[j] && r[j] != mn) {
			ex[j] = 0;
			cn--;
		}

		if (cn > 2) {
			res[i] = mn;
			ex[i] = 0;
			cn--;
		}
	}

	int x = -1, y = -1, cero;
	forn (i, n)
		if (ex[i]) {
			if (x == -1) x = i;
			else y = i;
		}

	forn (ptr, n) {
		int i = q[ptr];
		
		if (i == x || i == y) continue;

		int a = query(i, x);
		int b = query(i, y);

		if (a != b) {
			if (a < b) {
				cero = x;
				res[y] = mn;
			} else {
				cero = y;
				res[x] = mn;
			}
			break;
		}

		res[i] = a;
	}

	forn (i, n)
		if (i != cero && !res[i])
			res[i] = query(i, cero);

	cout << "!";
	forn (i, n) cout << " " << res[i];
	cout << endl;

	return 0;
}