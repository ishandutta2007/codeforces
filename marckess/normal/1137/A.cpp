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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, a[MX][MX], res[MX];
vi c[MX], r[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			r[i].pb(a[i][j]);
			c[j].pb(a[i][j]);
		}

	for (int i = 0; i < n; i++) {
		sort(all(r[i]));
		r[i].erase(unique(all(r[i])), r[i].end());
	}

	for (int j = 0; j < m; j++) {
		sort(all(c[j]));
		c[j].erase(unique(all(c[j])), c[j].end());
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = upper_bound(all(r[i]), a[i][j]) - r[i].begin();
			int y = upper_bound(all(c[j]), a[i][j]) - c[j].begin();
			int p = max(x, y);
			cout << p + max((int)r[i].size() - x, (int)c[j].size() - y) << " ";
		}
		cout << endl;
	}

	return 0;
}