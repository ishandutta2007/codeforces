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
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, q, f[12 * MX], a[12][MX], sz;
bitset<12 * MX> bs[12];
bitset<(1 << 12) + 5> v[MX];
vi c[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> q;
	forn (i, k) {
		forn (j, n) {
			cin >> a[i][j];
			c[j].pb(a[i][j]);
		}
	}

	forn (j, n)
		sort(all(c[j]));

	forn (i, k) {
		forn (j, n) {
			int x = lower_bound(all(c[j]), a[i][j]) - c[j].begin();
			forn (l, x)
				bs[i][j * k + l] = 1;
		}
	}

	forn (j, k * n)
		forn (i, k)
			f[j] |= int(bs[i][j]) << i;

	forn (i, k)
		forn (j, k * n)
			v[i][f[j]] = bs[i][j];

	sz = k;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		x--, y--;

		if (t == 1) {
			v[sz] = v[x] | v[y];
			sz++;
		} else if (t == 2) {
			v[sz] = v[x] & v[y];
			sz++;
		} else {
			int res = 0;
			forn (l, k)
				res += v[x][f[y * k + l]];
			cout << c[y][res] << endl;
		}
	}

	return 0;
}