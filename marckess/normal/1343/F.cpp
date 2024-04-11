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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 205;
int n, res[MX], k[MX], a[MX][MX], ant[MX];
set<int> st[MX];

bool esPos (int fi) {
	forn (i, n) {
		res[i] = fi;

		if (i + 1 == n) break;

		int ind, cn = 0;

		forn (j, n - 1) {
			if (st[j].empty()) continue;

			if (st[j].count(fi)) {
				st[j].erase(fi);

				if (st[j].size() == 1) {
					cn++;
					ind = j;
				}

				ant[j] = 1;
			} else {
				if (ant[j]) return 0;
			}
		}

		if (cn != 1) return 0;

		fi = *st[ind].begin();
		st[ind].clear();
	}

	return 1;
}

void solve () {
	cin >> n;

	forn (i, n - 1) {
		cin >> k[i];
		forn (j, k[i])
			cin >> a[i][j];
	}

	for (int j = 1; j <= n; j++) {
		forn (i, n - 1) {
			st[i].clear();
			ant[i] = 0;
			forn (j, k[i])
				st[i].insert(a[i][j]);
		}

		if (esPos(j)) {
			forn (i, n)
				cout << res[i] << " ";
			cout << endl;
			return;
		}
	}

	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}