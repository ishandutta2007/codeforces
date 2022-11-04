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

const int MX = 300005;
int n, q, a[MX], p[MX];
ll st[4 * MX][2][2];

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int x) {
	int pos = p[x];

	st[pos][1][1] = a[x];
	st[pos][0][0] = -a[x];
	st[pos][1][0] = st[pos][0][1] = -1e18;

	pos /= 2;
	while (pos) {
		forn (i, 2) {
			forn (j, 2) {
				st[pos][i][j] = max({
					st[pos * 2][i][0] + st[pos * 2 + 1][1][j], 
					st[pos * 2][i][1] + st[pos * 2 + 1][0][j],
					st[pos * 2][i][j],
					st[pos * 2 + 1][i][j],
				});
			}
		}
		pos /= 2;
	}
}

void ans () {
	cout << max(st[1][1][0], st[1][1][1]) << endl;
}

void solve () {
	cin >> n >> q;
	build(1, n, 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i);
	}

	ans();

	while (q--) {
		int l, r;
		cin >> l >> r;
		swap(a[l], a[r]);

		update(l);
		update(r);

		ans();
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}