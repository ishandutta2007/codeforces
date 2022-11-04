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

const int MX = 1e5+5;
int n, m, a[MX], b[MX], c[MX], d[MX], k[MX], x[MX], y[MX], res[MX];
set<ii> st;

void no () {
	cout << "NO" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> c[i] >> d[i] >> k[i];

	iota(x, x+n, 0);
	sort(x, x+n, [&] (int i, int j) {
		return a[i] < a[j];
	});

	iota(y, y+m, 0);
	sort(y, y+m, [&] (int i, int j) {
		return c[i] < c[j];
	});

	for (int i = 0, j = 0; i < n; i++) {
		int u = x[i];

		while (j < m) {
			int v = y[j];

			if (c[v] <= a[u]) st.emplace(d[v], v);
			else break;

			j++;
		}

		auto it = st.upper_bound(ii(b[u], -1));

		if (it == st.end()) no();

		k[it->se]--;
		res[u] = it->se + 1;

		if (!k[it->se])
			st.erase(it);
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}