#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 105;
int n, m, a[MX], b[MX], res[MX][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];

	for (int i = 0; i < 30; i++) {
		vi x, y;

		for (int j = 0; j < n; j++)
			if (a[j] & (1 << i))
				x.pb(j);

		for (int j = 0; j < m; j++)
			if (b[j] & (1 << i))
				y.pb(j);

		if (x.size() % 2 != y.size() % 2) {
			cout << "NO" << endl;
			return 0;
		}

		for (int j = 0; j < min(x.size(), y.size()); j++)
			res[x[j]][y[j]] |= (1 << i);

		if (x.size() > y.size())
			for (int j = y.size(); j < x.size(); j++)
				res[x[j]][0] |= (1 << i);

		if (y.size() > x.size())
			for (int j = x.size(); j < y.size(); j++)
				res[0][y[j]] |= (1 << i);
	}

	cout << "YES" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}