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

const int MX = 200005;
int n, a[MX], cn[205][MX], res;
vi pos[205];

int sum (int i, int j, int k) {
	if (i > j) return 0;
	if (!i) return cn[k][j];
	return cn[k][j] - cn[k][i - 1]; 
}

void solve () {
	cin >> n;
	forn (i, 201) {
		pos[i].clear();
		forn (j, n) cn[i][j] = 0;
	}

	forn (i, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
		cn[a[i]][i] = 1;
	}

	forn (i, 201)
		forn (j, n - 1)
			cn[i][j + 1] += cn[i][j];

	res = 1;

	forn (k, 201) {
		int i = 0, j = (int)pos[k].size() - 1;

		while (i < j) {
			forn (x, 201) {
				int p = (i + 1) + ((int)pos[k].size() - j);
				p += sum(pos[k][i] + 1, pos[k][j] - 1, x);
				res = max(res, p);
			}

			i++, j--;
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}