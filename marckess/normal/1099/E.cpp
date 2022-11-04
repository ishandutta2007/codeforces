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
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, mn;
vector<string> a, res, aux;

void solve (string &v) {
	int tot = 0;
	forn (i, n) {
		int x = 0, y = 0;
		forn (j, m) {
			x += v[(j & 1) + 2 * (i & 1)] != a[i][j];
			y += v[1 - (j & 1) + 2 * (i & 1)] != a[i][j];
		}

		if (x < y) {
			tot += x;
			forn (j, m) aux[i][j] = v[(j & 1) + 2 * (i & 1)];
		} else {
			tot += y;
			forn (j, m) aux[i][j] = v[1 - (j & 1) + 2 * (i & 1)];
		}
	}

	if (tot < mn) {
		mn = tot;
		res = aux;
	}

	tot = 0;
	forn (j, m) {
		int x = 0, y = 0;
		forn (i, n) {
			x += v[(i & 1) + 2 * (j & 1)] != a[i][j];
			y += v[1 - (i & 1) + 2 * (j & 1)] != a[i][j];
		}

		if (x < y) {
			tot += x;
			forn (i, n) aux[i][j] = v[(i & 1) + 2 * (j & 1)];
		} else {
			tot += y;
			forn (i, n) aux[i][j] = v[1 - (i & 1) + 2 * (j & 1)];
		}
	}

	if (tot < mn) {
		mn = tot;
		res = aux;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	forn (i, n) {
		string in(m, 0);
		for (char &x : in)
			cin >> x;
		a.pb(in);
	}
	aux = a;

	mn = 1e9;
	string v = {'A', 'C', 'G', 'T'};
	
	do solve(v);
	while (next_permutation(all(v)));

	for (string &r : res) {
		for (char x : r) cout << x;
		cout << endl;
	}

	return 0;
}