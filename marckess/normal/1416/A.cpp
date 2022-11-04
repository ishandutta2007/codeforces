#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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
int n, a[MX], res[MX];
vi pos[MX];

void solve () {
	cin >> n;

	for (int i = 1; i <= n; i++)
		pos[i] = {-1};

	forn (i, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}

	for (int i = 1; i <= n; i++)
		pos[i].pb(n);

	for (int i = 1; i <= n; i++)
		res[i] = n + 1;

	for (int i = 1; i <= n; i++) {
		int mx = 0;

		for (int j = 1; j < pos[i].size(); j++)
			mx = max(mx, pos[i][j] - pos[i][j - 1]);

		res[mx] = min(res[mx], i);
	}

	res[0] = n + 1;
	for (int i = 1; i <= n; i++) {
		res[i] = min(res[i], res[i - 1]);
		cout << (res[i] == n + 1 ? -1 : res[i]) << " ";
	}
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