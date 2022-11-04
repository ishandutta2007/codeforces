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

const int MX = 105;
int n, m, a[MX][MX], cn, l[MX * MX], r[MX * MX], mem[MX][MX];

int dp (int i, int j) {
	if (i > j) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;
	res = 0;

	set<ii> st, nex;

	forn (k, n) {
		int x = a[k][i];

		if (i <= l[x] && r[x] <= j)
			st.emplace(r[x], k);

		x = a[k][r[x] + 1];

		if (i <= l[x] && r[x] <= j)
			nex.emplace(l[x], k);
	}

	for (int k = i; k <= j; k++) {
		while (st.size() && st.begin()->fi < k) {
			int y = st.begin()->se;
			st.erase(st.begin());

			int x = a[y][k];

			if (i <= l[x] && r[x] <= j)
				st.emplace(r[x], y);
		}

		while (nex.size() && nex.begin()->fi == k) {
			int y = nex.begin()->se;
			nex.erase(nex.begin());

			int x = a[y][k];

			if (i <= l[x] && r[x] <= j)
				st.emplace(r[x], y);
		}

		res = max(res, int(st.size()) * int(st.size()) + dp(i, k - 1) + dp(k + 1, j));
	}

	return res;
}

void solve () {
	cin >> n >> m;

	forn (i, n) {
		int k;
		cin >> k;
		
		while (k--) {
			cin >> l[cn] >> r[cn];
			l[cn]--, r[cn]--;

			for (int j = l[cn]; j <= r[cn]; j++)
				a[i][j] = cn;

			cn++;
		}
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(0, m - 1) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}