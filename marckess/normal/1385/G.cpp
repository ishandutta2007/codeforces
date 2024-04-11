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

const int MX = 200005;
int n, a[2][MX], ini[MX], fin[MX], ex[MX];
vi res;

bool insert (int x, int i) {
	if (!ini[x]) ini[x] = i;
	else if (!fin[x]) fin[x] = i;
	else return 0;
	return 1;
}

void solve () {
	cin >> n;

	res.clear();
	for (int i = 1; i <= n; i++) {
		ini[i] = fin[i] = ex[i] = 0;
	}

	for (int i = 1; i <= n; i++) cin >> a[0][i];
	for (int i = 1; i <= n; i++) cin >> a[1][i];

	for (int i = 1; i <= n; i++) {
		if (a[0][i] == a[1][i]) ex[i] = 1;

		if (!insert(a[0][i], i) || !insert(a[1][i], i)) {
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 1; i <= n; i++)
		if (!ex[i]) {
			vi x, y;

			int u = i, act = a[0][i];

			do {
				ex[u] = 1;
				
				if (act == a[0][u]) {
					x.pb(u);
					act = a[1][u];
				} else {
					y.pb(u);
					act = a[0][u];
				}

				if (ini[act] == u) u = fin[act];
				else u = ini[act];

			} while (u != i);

			if (x.size() > y.size()) swap(x, y);

			for (int r : x) res.pb(r);
		}

	cout << res.size() << endl;
	for (int p : res)
		cout << p << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}